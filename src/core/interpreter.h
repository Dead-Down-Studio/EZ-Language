#pragma once
#include <filesystem>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../diagnostics/diagnostics.h"
#include "../../generated/EZLanguageParser.h"

class SimpleInterpreter {
public:
    explicit SimpleInterpreter(std::ostream &stream, std::unordered_map<std::string, std::filesystem::path> friendLibs, bool verbose);
    bool execute(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics);
    void printVariables() const;

private:
    static std::optional<int> callSymbol(const std::filesystem::path &libPath,
                                         const std::string &symbol,
                                         const std::vector<int> &args,
                                         std::vector<Diagnostic> &diagnostics,
                                         size_t line);

    std::optional<int> evaluateExpression(EZLanguageParser::ExpressionContext &expression,
                                          std::vector<Diagnostic> &diagnostics);
    std::optional<int> evaluatePrimary(EZLanguageParser::PrimaryExpressionContext &primary,
                                       std::vector<Diagnostic> &diagnostics);
    void handleFriendCall(EZLanguageParser::FriendFunctionCallContext &context,
                          std::vector<Diagnostic> &diagnostics);
    void handleVariableDeclaration(EZLanguageParser::VariableDeclarationContext &context,
                                   std::vector<Diagnostic> &diagnostics);
    void handleExpressionStatement(EZLanguageParser::ExpressionStatementContext &context,
                                   std::vector<Diagnostic> &diagnostics);
    static size_t lineOf(const antlr4::ParserRuleContext &context);

    std::ostream &output;
    std::unordered_map<std::string, int> variables;
    std::unordered_map<std::string, std::filesystem::path> libraries;
    bool verboseOutput = false;
};
