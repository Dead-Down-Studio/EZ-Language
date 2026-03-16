#include "diagnostics.h"
#include <iostream>

namespace {

std::string jsonEscape(const std::string &value)
{
    std::string escaped;
    escaped.reserve(value.size() + 8);

    for (char ch : value) {
        switch (ch) {
            case '\\': escaped += "\\\\"; break;
            case '"': escaped += "\\\""; break;
            case '\n': escaped += "\\n"; break;
            case '\r': escaped += "\\r"; break;
            case '\t': escaped += "\\t"; break;
            default: escaped += ch; break;
        }
    }

    return escaped;
}

} // namespace

void printDiagnostics(const std::vector<Diagnostic> &diagnostics, const std::filesystem::path &filePath)
{
    if (diagnostics.empty()) {
        return;
    }

    std::cerr << "Encountered " << diagnostics.size() << " issue(s) in " << filePath << ":\n";
    for (const auto &diagnostic : diagnostics) {
        if (diagnostic.line != 0) {
            std::cerr << "  line " << diagnostic.line << ": " << diagnostic.message << '\n';
        } else {
            std::cerr << "  " << diagnostic.message << '\n';
        }
    }
}

void printDiagnosticsJson(const std::vector<Diagnostic> &diagnostics, const std::filesystem::path &filePath)
{
    if (diagnostics.empty()) {
        return;
    }

    std::cerr << "{\n";
    std::cerr << "  \"file\": \"" << jsonEscape(filePath.string()) << "\",\n";
    std::cerr << "  \"issueCount\": " << diagnostics.size() << ",\n";
    std::cerr << "  \"issues\": [\n";

    for (size_t index = 0; index < diagnostics.size(); ++index) {
        const auto &diagnostic = diagnostics[index];
        std::cerr << "    {\"line\": " << diagnostic.line
                  << ", \"message\": \"" << jsonEscape(diagnostic.message) << "\"}";
        if (index + 1 != diagnostics.size()) {
            std::cerr << ',';
        }
        std::cerr << '\n';
    }

    std::cerr << "  ]\n";
    std::cerr << "}\n";
}
