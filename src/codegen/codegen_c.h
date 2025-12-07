#pragma once
#include <string>
#include <vector>
#include "../diagnostics/diagnostics.h"
#include "../../generated/EZLanguageParser.h"

class CCodeGenerator {
public:
    std::string generate(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics);
};
