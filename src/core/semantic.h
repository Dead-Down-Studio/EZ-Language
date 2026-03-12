#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "../diagnostics/diagnostics.h"
#include "types.h"
#include "../../generated/EZLanguageParser.h"

struct VariableInfo {
	SimpleType type = SimpleType::Unknown;
	size_t line = 0;
};

struct FunctionParam {
	std::string name;
	SimpleType type = SimpleType::Unknown;
	size_t line = 0;
};

struct FunctionInfo {
	SimpleType returnType = SimpleType::Unknown;
	std::vector<FunctionParam> params;
	size_t line = 0;
};

struct SemanticModel {
	std::unordered_map<std::string, VariableInfo> globals;
	std::unordered_map<std::string, FunctionInfo> functions;
};

// Run semantic checks (access control, type checking) and build a semantic model
// for globals and functions. Adds diagnostics for:
//  - invalid access modifiers at top-level
//  - protected usage
//  - duplicate functions/variables
//  - type mismatches, missing returns, unknown identifiers
SemanticModel runSemanticChecks(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics);
