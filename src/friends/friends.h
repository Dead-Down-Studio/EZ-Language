#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include "../diagnostics/diagnostics.h"
#include "../core/bootstrap_listener.h"
#include "../config/config.h"

struct BuildPlanEntry {
    BootstrapListener::FriendModule module;
    std::filesystem::path source;
    std::filesystem::path object;
    std::string command;
    std::filesystem::path dylib;
    std::string linkCommand;
};

std::vector<BuildPlanEntry> prepareBuildPlan(const std::vector<BootstrapListener::FriendModule> &modules,
                                             const std::filesystem::path &baseDir,
                                             std::vector<Diagnostic> &diagnostics,
                                             const std::vector<BootstrapListener::FriendCall> &calls,
                                             const EZConfig &config);
