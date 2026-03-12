#pragma once
#include <filesystem>
#include <optional>
#include <string>

struct NixEnvInfo {
    std::filesystem::path envFile;   // path to env.nix used
    std::string envSource;           // "project" or "builtin"
};

// Detect if nix is installed (nix-shell available)
bool nixAvailable();

// Detect if we are already inside a nix shell
bool insideNixShell();

// Locate project-level environment file (.ez-env.nix or ez-env.nix)
std::optional<std::filesystem::path> findProjectEnv(const std::filesystem::path &projectRoot);

// Locate built-in environment for the given env type (e.g., native)
std::optional<std::filesystem::path> findBuiltinEnv(const std::string &envType, const std::filesystem::path &exeDir);

// Prepare environment (download/build) by running nix-shell --run "true"
bool prepareNixEnv(const std::filesystem::path &envFile);

// Re-exec inside nix-shell with the given command string (returns process exit code)
int runInNixEnv(const std::filesystem::path &envFile, const std::string &commandLine);

// Re-exec inside nix-shell with properly escaped argv array (returns process exit code)
int runInNixEnvWithArgs(const std::filesystem::path &envFile, const std::vector<std::string> &args);

// Attempt to install Nix using the official installer for the current OS
bool installNixForCurrentOS();
