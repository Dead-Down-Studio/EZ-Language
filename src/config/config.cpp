#include "config.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

static string trim(const string &str) {
    size_t start = 0;
    while (start < str.size() && isspace(str[start])) ++start;
    size_t end = str.size();
    while (end > start && isspace(str[end - 1])) --end;
    return str.substr(start, end - start);
}

static string unquote(const string &str) {
    string s = trim(str);
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
        return s.substr(1, s.size() - 2);
    }
    return s;
}

void EZConfig::parseLine(const string &line, string &currentSection) {
    string trimmed = trim(line);
    if (trimmed.empty() || trimmed[0] == '#') return;
    
    // Section header: [section]
    if (trimmed.front() == '[' && trimmed.back() == ']') {
        currentSection = trimmed.substr(1, trimmed.size() - 2);
        return;
    }
    
    // Key = value
    size_t eq = trimmed.find('=');
    if (eq != string::npos) {
        string key = trim(trimmed.substr(0, eq));
        string value = unquote(trimmed.substr(eq + 1));
        setValue(currentSection, key, value);
    }
}

void EZConfig::setValue(const string &section, const string &key, const string &value) {
    if (section == "python") {
        if (key == "executable") pythonExecutable = value;
    } else if (section == "c") {
        if (key == "compiler") cCompiler = value;
        else if (key == "standard") cStandard = value;
        else if (key == "flags") cFlags = value;
    } else if (section == "cpp") {
        if (key == "compiler") cppCompiler = value;
        else if (key == "standard") cppStandard = value;
        else if (key == "flags") cppFlags = value;
    } else if (section == "build") {
        if (key == "output_dir") outputDir = value;
        else if (key == "verbose") verboseBuild = (value == "true" || value == "1");
        else if (key == "no_env" || key == "no-env") noEnv = (value == "true" || value == "1");
    }
}

bool EZConfig::loadFromFile(const fs::path &path) {
    ifstream file(path);
    if (!file.is_open()) return false;
    
    string currentSection;
    string line;
    while (getline(file, line)) {
        parseLine(line, currentSection);
    }
    return true;
}

EZConfig EZConfig::loadWithFallback(const fs::path &projectRoot) {
    EZConfig config; // Start with defaults
    
    // Try ~/.ezconfig first (user-level defaults)
    const char *home = getenv("HOME");
    if (home) {
        fs::path userConfig = fs::path(home) / ".ezconfig";
        if (fs::exists(userConfig)) {
            config.loadFromFile(userConfig);
        }
    }
    
    // Try nearest project-level .ezconfig walking upward from projectRoot
    fs::path current = projectRoot;
    while (true) {
        fs::path projectConfig = current / ".ezconfig";
        if (fs::exists(projectConfig)) {
            config.loadFromFile(projectConfig);
            break;
        }
        if (!current.has_parent_path() || current.parent_path() == current) {
            break;
        }
        current = current.parent_path();
    }
    
    return config;
}
