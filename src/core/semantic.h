#pragma once

#include <vector>
#include "../diagnostics/diagnostics.h"
#include "../../generated/EZLanguageParser.h"

// Run semantic checks over the parse tree, adding diagnostics:
//  - Access modifiers on top-level variable declarations (disallowed)
//  - Calls to private class-scoped functions from top-level statements
//  - Use of 'protected' (not implemented yet)
void runSemanticChecks(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics);
