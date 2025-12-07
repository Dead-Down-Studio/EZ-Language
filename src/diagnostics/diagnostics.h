#pragma once
#include <filesystem>
#include <string>
#include <vector>

struct Diagnostic {
    size_t line;
    std::string message;
};

void printDiagnostics(const std::vector<Diagnostic> &diagnostics, const std::filesystem::path &filePath);
