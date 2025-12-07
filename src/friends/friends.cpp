#include "friends.h"
#include "../util/util.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <system_error>
#include <unordered_map>
#include <unordered_set>

using namespace std;
namespace fs = std::filesystem;

std::vector<BuildPlanEntry> prepareBuildPlan(const std::vector<BootstrapListener::FriendModule> &modules,
                                             const fs::path &baseDir,
                                             std::vector<Diagnostic> &diagnostics,
                                             const std::vector<BootstrapListener::FriendCall> &calls,
                                             const EZConfig &config)
{
    std::vector<BuildPlanEntry> plan;
    if (modules.empty()) {
        return plan;
    }

    const fs::path outputDir = baseDir / config.outputDir;
    std::error_code ec;
    fs::create_directories(outputDir, ec);
    if (ec) {
        diagnostics.push_back({0, "failed to create build directory '" + outputDir.string() + "': " + ec.message()});
        return plan;
    }

    unordered_map<string, unordered_map<string, size_t>> used;
    for (const auto &c : calls) {
        auto &funcs = used[c.alias];
        auto it = funcs.find(c.func);
        if (it == funcs.end()) {
            funcs.emplace(c.func, c.argc);
        } else if (it->second != c.argc) {
            diagnostics.push_back({c.line, "inconsistent argument count for '" + c.alias + "." + c.func + "'"});
        }
    }

    for (const auto &module : modules) {
        fs::path source = baseDir / module.sourceToken;
        if (!source.has_extension()) {
            if (module.language == "c") source.replace_extension(".c");
            else if (module.language == "cpp") source.replace_extension(".cpp");
            else if (module.language == "python") source.replace_extension(".py");
        }

        if (!fs::exists(source)) {
            diagnostics.push_back({module.line, "friend source file not found: " + source.string()});
            continue;
        }

        fs::path object = outputDir / (module.alias + ".o");
        std::ostringstream compileCmd;
        std::ostringstream linkCmd;
        fs::path dylib = outputDir / ("lib" + module.alias + ".dylib");

        if (module.language == "python") {
            auto usedIt = used.find(module.alias);
            if (usedIt == used.end() || usedIt->second.empty()) {
                diagnostics.push_back({module.line, "no friend functions used for alias '" + module.alias + "'"});
                continue;
            }
            const fs::path shim = outputDir / (module.alias + "_shim.c");
            auto writeShim = [&](const fs::path &shimPath) {
                std::ofstream out(shimPath);
                const std::string dir = source.parent_path().string();
                const std::string mod = source.stem().string();
                out << "#include <Python.h>\n";
                out << "static PyObject* g_module = NULL;\n";
                out << "static int ensure_init() {\n";
                out << "  if (g_module) return 0;\n";
                out << "  if (!Py_IsInitialized()) Py_Initialize();\n";
                out << "  PyObject* sys_path = PySys_GetObject(\"path\");\n";
                out << "  if (sys_path) { PyObject* p = PyUnicode_FromString(\"" << dir << "\"); if (p) { PyList_Append(sys_path, p); Py_DECREF(p);} }\n";
                out << "  PyObject* name = PyUnicode_FromString(\"" << mod << "\");\n";
                out << "  g_module = PyImport_Import(name); Py_DECREF(name);\n";
                out << "  if (!g_module) { PyErr_Print(); return -1; }\n";
                out << "  return 0;\n";
                out << "}\n";
                for (const auto &fn : usedIt->second) {
                    const std::string &fname = fn.first;
                    const size_t argc = fn.second;
                    out << "int " << fname << "(";
                    for (size_t i = 0; i < argc; ++i) {
                        out << "int a" << i;
                        if (i + 1 < argc) out << ", ";
                    }
                    out << ") {\n";
                    out << "  if (ensure_init() != 0) return 0;\n";
                    out << "  PyObject* func = PyObject_GetAttrString(g_module, \"" << fname << "\");\n";
                    out << "  if (!func || !PyCallable_Check(func)) { Py_XDECREF(func); return 0; }\n";
                    out << "  PyObject* args = PyTuple_New(" << argc << ");\n";
                    for (size_t i = 0; i < argc; ++i) {
                        out << "  PyTuple_SET_ITEM(args, " << i << ", PyLong_FromLong(a" << i << "));\n";
                    }
                    out << "  PyObject* res = PyObject_CallObject(func, args);\n";
                    out << "  Py_DECREF(args); Py_DECREF(func);\n";
                    out << "  if (!res) { PyErr_Print(); return 0; }\n";
                    out << "  long v = PyLong_AsLong(res); Py_DECREF(res);\n";
                    out << "  return (int)v;\n";
                    out << "}\n";
                }
            };
            try { writeShim(shim); } catch (...) {
                diagnostics.push_back({module.line, "failed to write Python shim"});
                continue;
            }
            compileCmd.str("");
            linkCmd << "clang -std=c11 -dynamiclib " << quote(shim) << " -o " << quote(dylib);

            // Use configured Python executable (env vars override config)
            const char *pyC = std::getenv("PY_CFLAGS");
            const char *pyL = std::getenv("PY_LDFLAGS");
            const char *pyExeEnv = std::getenv("PYTHON");
            std::string pyExe = (pyExeEnv && *pyExeEnv) ? std::string(pyExeEnv) : config.pythonExecutable;
            
            if (pyC && *pyC) {
                linkCmd << ' ' << pyC;
            }
            if (pyL && *pyL) {
                linkCmd << ' ' << pyL;
            }
            if (!(pyC && *pyC) || !(pyL && *pyL)) {
                // Try python3-config for the configured Python
                std::string pyConfigCmd = pyExe + "-config";
                linkCmd << " $(command -v " << pyConfigCmd << " >/dev/null 2>&1 && " << pyConfigCmd << " --includes || true)";
                linkCmd << " $(command -v " << pyConfigCmd << " >/dev/null 2>&1 && (" << pyConfigCmd << " --ldflags --embed 2>/dev/null || " << pyConfigCmd << " --ldflags) || true)";
                // Fallback: introspect using sysconfig
                linkCmd << " $(" << pyExe << " -c \"import sysconfig,sys; inc=sysconfig.get_config_var('INCLUDEPY') or ''; sys.stdout.write(('-I'+inc) if inc else '')\" 2>/dev/null || true)";
                linkCmd << " $(" << pyExe << " -c \"import sysconfig,sys; keys=('LDFLAGS','LIBS','SYSLIBS','LINKFORSHARED'); sys.stdout.write(' '.join([sysconfig.get_config_var(k) or '' for k in keys]))\" 2>/dev/null | sed -E 's/(^| )[^ ]*stack_size[^ ]*( |$)/ /g' || true)";
            }
        } else {
            const bool isC = module.language == "c";
            const std::string compiler = isC ? config.cCompiler : config.cppCompiler;
            const std::string stdFlag = isC ? ("-std=" + config.cStandard) : ("-std=" + config.cppStandard);
            const std::string extraFlags = isC ? config.cFlags : config.cppFlags;

            const std::string ext = source.extension().string();
            if (ext == ".c" || ext == ".cpp" || ext == ".cc" || ext == ".cxx") {
                compileCmd << compiler << ' ' << stdFlag;
                if (!extraFlags.empty()) compileCmd << ' ' << extraFlags;
                compileCmd << " -c " << quote(source) << " -o " << quote(object);
                
                linkCmd << compiler << ' ' << stdFlag;
                if (!extraFlags.empty()) linkCmd << ' ' << extraFlags;
                linkCmd << " -dynamiclib " << quote(source) << " -o " << quote(dylib);
            } else if (ext == ".o") {
                object = source;
                linkCmd << compiler << ' ' << stdFlag << " -dynamiclib " << quote(object) << " -o " << quote(dylib);
            } else if (ext == ".a") {
                linkCmd << compiler << ' ' << stdFlag << " -dynamiclib " << quote(source) << " -o " << quote(dylib);
            } else if (ext == ".dylib") {
                dylib = source;
            } else {
                diagnostics.push_back({module.line, "unsupported friend file extension '" + ext + "'"});
                continue;
            }
        }

        BuildPlanEntry entry;
        entry.module = module;
        entry.source = std::move(source);
        entry.object = std::move(object);
        entry.command = compileCmd.str();
        entry.dylib = std::move(dylib);
        entry.linkCommand = linkCmd.str();
        plan.push_back(std::move(entry));
    }

    return plan;
}
