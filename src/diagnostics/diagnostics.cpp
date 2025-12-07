#include "diagnostics.h"
#include <iostream>

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
