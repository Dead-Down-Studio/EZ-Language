#pragma once
#include <filesystem>
#include <string>

std::string quote(const std::filesystem::path &path);
std::string readFile(const std::filesystem::path &filePath);
