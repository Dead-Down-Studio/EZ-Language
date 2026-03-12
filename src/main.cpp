#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "util/util.h"
#include "diagnostics/diagnostics.h"
#include "core/bootstrap_listener.h"
#include "friends/friends.h"
#include "codegen/codegen_c.h"
#include "core/interpreter.h"
#include "core/semantic.h"
#include "config/config.h"
#include "config/nix_env.h"

#include "../generated/EZLanguageLexer.h"
#include "../generated/EZLanguageParser.h"
#include "antlr4-runtime.h"

using namespace antlr4;
namespace fs = std::filesystem;

struct EnvDefaults {
    std::string cCompiler;
    std::string cppCompiler;
    std::string pythonExecutable;
    std::string cStandard;
    std::string cppStandard;
    std::string outputDir;
};

static EnvDefaults builtinNativeDefaults()
{
    return {"clang", "clang++", "python3", "c11", "c++17", ".ezenv/build"};
}

static void persistResolvedEnv(const fs::path &projectRoot, const NixEnvInfo &info, const EnvDefaults &defaults)
{
    std::error_code ec;
    const fs::path dir = projectRoot / ".ezenv";
    fs::create_directories(dir, ec);
    if (ec) return;
    const fs::path resolved = dir / "resolved.json";
    std::ofstream out(resolved, std::ios::binary);
    if (!out.is_open()) return;
    out << "{\n";
    out << "  \"envFile\": \"" << info.envFile.string() << "\",\n";
    out << "  \"source\": \"" << info.envSource << "\",\n";
    out << "  \"cCompiler\": \"" << defaults.cCompiler << "\",\n";
    out << "  \"cppCompiler\": \"" << defaults.cppCompiler << "\",\n";
    out << "  \"pythonExecutable\": \"" << defaults.pythonExecutable << "\",\n";
    out << "  \"cStandard\": \"" << defaults.cStandard << "\",\n";
    out << "  \"cppStandard\": \"" << defaults.cppStandard << "\",\n";
    out << "  \"outputDir\": \"" << defaults.outputDir << "\"\n";
    out << "}\n";
}

static void printUsage(const std::string &binaryName)
{
    std::cerr << "Usage: " << binaryName << " <source.ez> [options]\n";
    std::cerr << "Options:\n";
    std::cerr << "  --plan           Print compile/link commands for friend modules\n";
    std::cerr << "  --build          Build friend objects and dylibs (.ezenv/build)\n";
    std::cerr << "  --run            Interpret declarations/expressions/friend calls\n";
    std::cerr << "  --emit-c         Generate C code (.ezenv/build/<base>.c) for int subset\n";
    std::cerr << "  --build-native   Generate + compile C to native exe (.ezenv/build/<base>)\n";
    std::cerr << "  --run-native     Generate, compile, and execute the native binary\n";
    std::cerr << "  --prepare        Prepare Nix environment (download/build)\n";
    std::cerr << "  --ignore-conflicts, -ic  Skip config/env conflict prompts\n";
    std::cerr << "  --no-env         Skip Nix environment activation\n";
    std::cerr << "  --env-info       Show resolved environment info and exit\n";
    std::cerr << "  -v, --verbose    Show environment, build plan, variable state, and evaluation results\n";
}



int main(int argc, const char *argv[])
{
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    bool runBuild = false;
    bool runInterpreter = false;
    bool emitC = false;
    bool buildNative = false;
    bool runNative = false;
    bool verbose = false;
    bool prepareEnv = false;
    bool ignoreConflicts = false;
    bool skipEnv = false;
    bool showEnvInfo = false;
    bool inNixShellFlag = false; // internal marker to avoid recursion

    for (int index = 2; index < argc; ++index) {
        const std::string flag = argv[index];
        if (flag == "--build") {
            runBuild = true;
        } else if (flag == "--plan") {
            runBuild = false;
        } else if (flag == "--run") {
            runInterpreter = true;
        } else if (flag == "--emit-c") {
            emitC = true;
        } else if (flag == "--build-native") {
            buildNative = true;
        } else if (flag == "--run-native") {
            runNative = true; buildNative = true; // implies build
        } else if (flag == "-v" || flag == "--verbose") {
            verbose = true;
        } else if (flag == "--prepare") {
            prepareEnv = true;
        } else if (flag == "--ignore-conflicts" || flag == "-ic") {
            ignoreConflicts = true;
        } else if (flag == "--no-env") {
            skipEnv = true;
        } else if (flag == "--env-info") {
            showEnvInfo = true;
        } else if (flag == "--in-nix-env") {
            inNixShellFlag = true;
        } else {
            printUsage(argv[0]);
            return 1;
        }
    }

    fs::path sourcePath = fs::absolute(argv[1]);
    if (!fs::exists(sourcePath)) {
        std::cerr << "Source file not found: " << sourcePath << '\n';
        return 1;
    }

    const fs::path projectRoot = sourcePath.parent_path();
    EZConfig config = EZConfig::loadWithFallback(projectRoot);

    EnvDefaults envDefaults = builtinNativeDefaults();
    envDefaults.cCompiler = config.cCompiler;
    envDefaults.cppCompiler = config.cppCompiler;
    envDefaults.pythonExecutable = config.pythonExecutable;
    envDefaults.cStandard = config.cStandard;
    envDefaults.cppStandard = config.cppStandard;
    envDefaults.outputDir = config.outputDir;

    // Config file can request verbose output or skipping environment setup
    verbose = verbose || config.verboseBuild;
    skipEnv = skipEnv || config.noEnv;

    bool nixPresent = skipEnv ? false : nixAvailable();
    const bool alreadyInNix = insideNixShell();

    if (!nixPresent && !skipEnv) {
        std::cerr << "nix is not installed do you want to install it ? [Y/N] " << std::flush;
        std::string choice;
        if (!std::getline(std::cin, choice)) {
            return 1;
        }
        const char sel = choice.empty() ? 'N' : choice[0];
        if (sel == 'y' || sel == 'Y') {
            if (!installNixForCurrentOS()) {
                std::cerr << "Nix installation failed. use --no-env to run the code without the nix support" << '\n';
                return 1;
            }
            nixPresent = nixAvailable();
            if (!nixPresent) {
                std::cerr << "Nix installation completed but nix-shell is still not detected in this session." << '\n';
                std::cerr << "use --no-env to run the code without the nix support" << '\n';
                return 1;
            }
        } else {
            std::cerr << "use --no-env to run the code without the nix support" << '\n';
            skipEnv = true;
        }
    }

    std::optional<NixEnvInfo> resolvedEnv;
    if (nixPresent && !skipEnv) {
        if (auto projectEnv = findProjectEnv(projectRoot)) {
            resolvedEnv = NixEnvInfo{*projectEnv, "project"};
        } else if (auto builtinEnv = findBuiltinEnv("native", projectRoot)) {
            resolvedEnv = NixEnvInfo{*builtinEnv, "builtin"};
        }
    }

    if (showEnvInfo) {
        std::cout << "nix-available: " << (nixPresent ? "yes" : "no") << '\n';
        std::cout << "inside-nix: " << (alreadyInNix ? "yes" : "no") << '\n';
        if (resolvedEnv) {
            std::cout << "env-file: " << resolvedEnv->envFile << " (" << resolvedEnv->envSource << ")" << '\n';
        } else {
            std::cout << "env-file: none" << '\n';
        }
        return resolvedEnv ? 0 : 1;
    }

    if (skipEnv && prepareEnv) {
        return 0;
    }

    if (prepareEnv) {
        if (!nixPresent) {
            std::cerr << "Nix is not available (nix-shell missing)." << '\n';
            return 1;
        }
        if (!resolvedEnv) {
            std::cerr << "No Nix environment file found (tried project and builtin)." << '\n';
            return 1;
        }
        if (!prepareNixEnv(resolvedEnv->envFile)) {
            std::cerr << "Failed to prepare Nix environment: " << resolvedEnv->envFile << '\n';
            return 1;
        }
        persistResolvedEnv(projectRoot, *resolvedEnv, envDefaults);
        return 0;
    }

    if (!skipEnv && nixPresent && resolvedEnv && !alreadyInNix && !inNixShellFlag) {
        std::vector<std::string> cmdArgs;
        cmdArgs.push_back(fs::absolute(argv[0]).string());
        for (int i = 1; i < argc; ++i) {
            if (std::string(argv[i]) == "--in-nix-env") continue;
            cmdArgs.push_back(argv[i]);
        }
        cmdArgs.push_back("--in-nix-env");
        if (verbose) {
            std::cout << "Entering Nix environment using " << resolvedEnv->envFile << '\n';
        }
        const int rc = runInNixEnvWithArgs(resolvedEnv->envFile, cmdArgs);
        return rc == 0 ? 0 : rc;
    }

    std::string sourceText;
    try {
        sourceText = readFile(sourcePath);
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << '\n';
        return 1;
    }

    ANTLRInputStream input(sourceText);
    EZLanguageLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    EZLanguageParser parser(&tokens);
    EZLanguageParser::ProgramContext *program = parser.program();

    if (parser.getNumberOfSyntaxErrors() > 0) {
        std::cerr << "Syntax errors detected in " << sourcePath << '\n';
        return 1;
    }

    BootstrapListener listener(sourcePath.parent_path());
    tree::ParseTreeWalker::DEFAULT.walk(&listener, program);

    std::vector<Diagnostic> diagnostics = listener.getDiagnostics();

    const auto &environment = listener.getEnvironment();
    if (!environment.has_value()) {
        diagnostics.push_back({0, "missing environment declaration. Add 'doing native;' at the top of the file."});
    } else if (environment.value() != "native") {
        const size_t line = listener.getEnvironmentLine().value_or(0);
        diagnostics.push_back({line, "only the 'native' environment is supported in this MVP"});
    }

    std::unordered_set<std::string> aliases;
    for (const auto &module : listener.getFriendModules()) {
        if (module.language != "c" && module.language != "cpp" && module.language != "python") {
            diagnostics.push_back({module.line, "unsupported friend language '" + module.language + "'. Use 'c', 'cpp', or 'python'."});
        }

        if (!aliases.insert(module.alias).second) {
            diagnostics.push_back({module.line, "duplicate friend alias '" + module.alias + "'."});
        }
    }

    // Semantic checks (types, access control, returns)
    SemanticModel semanticModel = runSemanticChecks(program, diagnostics);

    if (resolvedEnv && resolvedEnv->envSource == "builtin") {
        std::vector<std::string> conflicts;
        const auto add = [&](const std::string &key, const std::string &cfg, const std::string &envVal) {
            if (cfg != envVal) {
                conflicts.push_back(key + ": config='" + cfg + "' env='" + envVal + "'");
            }
        };
        add("c compiler", config.cCompiler, envDefaults.cCompiler);
        add("c standard", config.cStandard, envDefaults.cStandard);
        add("c flags", config.cFlags, std::string(""));
        add("cpp compiler", config.cppCompiler, envDefaults.cppCompiler);
        add("cpp standard", config.cppStandard, envDefaults.cppStandard);
        add("cpp flags", config.cppFlags, std::string(""));
        add("python executable", config.pythonExecutable, envDefaults.pythonExecutable);
        add("output directory", config.outputDir, envDefaults.outputDir);

        if (!conflicts.empty()) {
            if (ignoreConflicts) {
                std::cerr << "Warning: config differs from Nix environment; proceeding with existing config (conflicts: " << conflicts.size() << ")." << '\n';
            } else {
                std::cerr << "Config conflicts with Nix environment:" << '\n';
                for (const auto &c : conflicts) {
                    std::cerr << "  - " << c << '\n';
                }
                std::cerr << "Choose: [1] use Nix values, [2] keep config, [3] abort > ";
                std::string choice;
                if (!std::getline(std::cin, choice)) {
                    return 1;
                }
                const char sel = choice.empty() ? '0' : choice[0];
                if (sel == '1') {
                    config.cCompiler = envDefaults.cCompiler;
                    config.cStandard = envDefaults.cStandard;
                    config.cFlags.clear();
                    config.cppCompiler = envDefaults.cppCompiler;
                    config.cppStandard = envDefaults.cppStandard;
                    config.cppFlags.clear();
                    config.pythonExecutable = envDefaults.pythonExecutable;
                    config.outputDir = envDefaults.outputDir;
                } else if (sel == '2') {
                    // keep user config
                } else {
                    std::cerr << "Aborted due to config/env conflict." << '\n';
                    return 1;
                }
            }
        }
    }

    if (resolvedEnv) {
        persistResolvedEnv(projectRoot, *resolvedEnv, envDefaults);
    }

    std::vector<BuildPlanEntry> plan = prepareBuildPlan(listener.getFriendModules(), listener.getBaseDirectory(), diagnostics, listener.getFriendCalls(), config);

    if (!diagnostics.empty()) {
        printDiagnostics(diagnostics, sourcePath);
        return 1;
    }

    // Always show plan if requested, otherwise only in verbose mode
    const bool showPlan = !runBuild || verbose;
    if (showPlan || verbose) {
        if (verbose) std::cout << "Environment: native" << '\n';
        if (plan.empty()) {
            if (verbose) std::cout << "No friend modules declared." << '\n';
        } else {
            std::cout << "Friend build plan:" << '\n';
            for (const auto &entry : plan) {
                std::cout << "  [" << entry.module.language << "] " << entry.module.alias
                          << " <= " << entry.source << '\n';
                if (!runBuild) {
                    std::cout << "    " << entry.command << '\n';
                }
            }
        }
    }

    if (runBuild) {
        if (!plan.empty()) {
            if (verbose) std::cout << '\n' << "Compiling/linking friend modules..." << '\n';
            for (const auto &entry : plan) {
                if (!entry.command.empty()) {
                    if (verbose) std::cout << entry.command << '\n';
                    const int status = std::system(entry.command.c_str());
                    if (status != 0) {
                        std::cerr << "Command failed with exit code " << status << '\n';
                        return status == 0 ? 1 : status;
                    }
                }
                if (!entry.linkCommand.empty()) {
                    if (verbose) std::cout << entry.linkCommand << '\n';
                    const int linkStatus = std::system(entry.linkCommand.c_str());
                    if (linkStatus != 0) {
                        std::cerr << "Link command failed with exit code " << linkStatus << '\n';
                        return linkStatus == 0 ? 1 : linkStatus;
                    }
                }
            }

            if (verbose) {
                const fs::path outputDir = plan.front().object.parent_path();
                std::cout << '\n' << "Friend artifacts written to " << outputDir << '\n';
                std::cout << "Dynamic libraries are named lib<alias>.dylib" << '\n';
            }
        }
    } else {
        // --plan mode (no build): always show instruction
        if (!plan.empty()) {
            std::cout << '\n';
            std::cout << "Run with '--build' to compile the friend modules." << '\n';
        }
    }

    // Optional: C codegen and native build/run path
    if (emitC || buildNative || runNative) {
        const fs::path baseDir = sourcePath.parent_path();
        const fs::path outDir = baseDir / config.outputDir;
        std::error_code ecGen;
        fs::create_directories(outDir, ecGen);
        if (ecGen) {
            std::cerr << "Failed to create output directory: " << outDir << " (" << ecGen.message() << ")\n";
            return 1;
        }

        const std::string stem = sourcePath.stem().string();
        const fs::path cFile = outDir / (stem + ".c");
        const fs::path exeFile = outDir / stem;

        std::vector<Diagnostic> cgDiags;
        CCodeGenerator codegen;
        const std::string cSrc = codegen.generate(program, semanticModel, cgDiags);
        if (!cgDiags.empty()) {
            printDiagnostics(cgDiags, sourcePath);
            return 1;
        }
        // Write C output
        try {
            std::ofstream out(cFile, std::ios::binary);
            out << cSrc;
            out.close();
        } catch (...) {
            std::cerr << "Failed to write C file: " << cFile << "\n";
            return 1;
        }
        std::cout << "C emitted to " << cFile << '\n';

        if (buildNative) {
            std::ostringstream cc;
            cc << "clang -std=c11 " << quote(cFile) << " -o " << quote(exeFile);
            std::cout << cc.str() << '\n';
            int rc = std::system(cc.str().c_str());
            if (rc != 0) {
                std::cerr << "Native build failed with exit code " << rc << "\n";
                return rc == 0 ? 1 : rc;
            }
            std::cout << "Native binary written to " << exeFile << '\n';
        }

        if (runNative) {
            const std::string runCmd = quote(exeFile);
            std::cout << runCmd << '\n';
            int rc = std::system(runCmd.c_str());
            if (rc != 0) return rc == 0 ? 1 : rc;
            return 0;
        }
    }

    if (!runInterpreter) {
        return 0;
    }

    // Map alias -> dylib path
    std::unordered_map<std::string, fs::path> libMap;
    for (const auto &e : plan) {
        libMap.emplace(e.module.alias, e.dylib);
    }

    SimpleInterpreter interpreter(std::cout, std::move(libMap), verbose, semanticModel);
    if (!interpreter.execute(program, diagnostics)) {
        printDiagnostics(diagnostics, sourcePath);
        return 1;
    }

    if (verbose) {
        std::cout << '\n';
        interpreter.printVariables();
    }

    return 0;
}