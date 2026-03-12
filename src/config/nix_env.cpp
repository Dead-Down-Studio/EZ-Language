#include "nix_env.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

static bool cmdExists(const std::string &cmd) {
    std::string probe = cmd + " >/dev/null 2>&1";
    return std::system(probe.c_str()) == 0;
}

bool nixAvailable() {
    return cmdExists("command -v nix-shell");
}

bool insideNixShell() {
    const char *flag = std::getenv("IN_NIX_SHELL");
    return flag && *flag;
}

std::optional<fs::path> findProjectEnv(const fs::path &projectRoot) {
    fs::path p1 = projectRoot / ".ez-env.nix";
    fs::path p2 = projectRoot / "ez-env.nix";
    if (fs::exists(p1)) return p1;
    if (fs::exists(p2)) return p2;
    return std::nullopt;
}

std::optional<fs::path> findBuiltinEnv(const std::string &envType, const fs::path &exeDir) {
    fs::path candidate = exeDir / "envs" / (envType + ".nix");
    if (fs::exists(candidate)) return candidate;
    fs::path parentCandidate = exeDir.parent_path() / "envs" / (envType + ".nix");
    if (fs::exists(parentCandidate)) return parentCandidate;
    return std::nullopt;
}

bool prepareNixEnv(const fs::path &envFile) {
    std::ostringstream cmd;
    cmd << "nix-shell " << '"' << envFile.string() << '"' << " --run \"true\"";
    int rc = std::system(cmd.str().c_str());
    return rc == 0;
}

int runInNixEnv(const fs::path &envFile, const std::string &commandLine) {
    std::ostringstream cmd;
    cmd << "nix-shell " << '"' << envFile.string() << '"' << " --run \"" << commandLine << "\"";
    return std::system(cmd.str().c_str());
}

int runInNixEnvWithArgs(const fs::path &envFile, const std::vector<std::string> &args) {
    std::ostringstream cmd;
    cmd << "nix-shell " << '"' << envFile.string() << '"' << " --run \"";
    for (size_t i = 0; i < args.size(); ++i) {
        if (i > 0) cmd << " ";
        const auto &arg = args[i];
        // Escape single quotes and wrap each arg in single quotes
        cmd << "'";
        for (char c : arg) {
            if (c == '\'') {
                cmd << "'\\''";  // exit single quote, add escaped quote, re-enter
            } else {
                cmd << c;
            }
        }
        cmd << "'";
    }
    cmd << "\"";
    return std::system(cmd.str().c_str());
}

bool installNixForCurrentOS() {
#if defined(__APPLE__) || defined(__linux__)
    const char *installer = "curl -L https://nixos.org/nix/install | sh -s -- --daemon";
    int rc = std::system(installer);
    if (rc != 0) {
        std::cerr << "Failed to install Nix (installer exited with code " << rc << ")." << '\n';
        return false;
    }
    return true;
#else
    std::cerr << "Nix installation automation is not supported on this OS.\n";
    return false;
#endif
}
