#pragma once
#include <string>
#include <vector>
#include "../diagnostics/diagnostics.h"
#include "../core/semantic.h"
#include "../../generated/EZLanguageParser.h"

class CCodeGenerator {
public:
    std::string generate(EZLanguageParser::ProgramContext *program,
                         const SemanticModel &model,
                         std::vector<Diagnostic> &diagnostics);
};
