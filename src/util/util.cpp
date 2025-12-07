#include "util.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string quote(const std::filesystem::path &path)
{
    std::ostringstream stream;
    stream << '"' << path.string() << '"';
    return stream.str();
}

std::string readFile(const std::filesystem::path &filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("unable to open source file: " + filePath.string());
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
