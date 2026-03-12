#pragma once
#include <string>
#include <unordered_map>
#include <filesystem>
#include <optional>

struct EZConfig {
    // Python settings
    std::string pythonExecutable = "python3";
    
    // C settings
    std::string cCompiler = "clang";
    std::string cStandard = "c11";
    std::string cFlags = "";
    
    // C++ settings
    std::string cppCompiler = "clang++";
    std::string cppStandard = "c++17";
    std::string cppFlags = "";
    
    // Build settings
    std::string outputDir = ".ezenv/build";
    bool verboseBuild = false;
    bool noEnv = false;
    
    // Load config from file (returns false if file doesn't exist or has errors)
    bool loadFromFile(const std::filesystem::path &path);
    
    // Load config with fallback: project .ezconfig -> ~/.ezconfig -> defaults
    static EZConfig loadWithFallback(const std::filesystem::path &projectRoot);
    
private:
    void parseLine(const std::string &line, std::string &currentSection);
    void setValue(const std::string &section, const std::string &key, const std::string &value);
};
