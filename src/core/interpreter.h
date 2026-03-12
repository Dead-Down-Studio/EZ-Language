#pragma once
#include <cstdint>
#include <filesystem>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../diagnostics/diagnostics.h"
#include "types.h"
#include "semantic.h"
#include "../../generated/EZLanguageParser.h"

struct Value {
    SimpleType type = SimpleType::Unknown;
    int64_t intValue = 0; // also used for boolean (0/1)
    double floatValue = 0.0; // for float/double types
    std::string stringValue; // for string types
};

class SimpleInterpreter {
public:
    explicit SimpleInterpreter(std::ostream &stream,
                               std::unordered_map<std::string, std::filesystem::path> friendLibs,
                               bool verbose,
                               SemanticModel model);
    bool execute(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics);
    void printVariables() const;

private:
    static std::optional<Value> callSymbol(const std::filesystem::path &libPath,
                                           const std::string &symbol,
                                           const std::vector<Value> &args,
                                           std::vector<Diagnostic> &diagnostics,
                                           size_t line);

    std::optional<Value> evaluateExpression(EZLanguageParser::ExpressionContext &expression,
                                            std::vector<Diagnostic> &diagnostics);
    std::optional<Value> evaluatePrimary(EZLanguageParser::PrimaryExpressionContext &primary,
                                         std::vector<Diagnostic> &diagnostics);
    void handleFriendCall(EZLanguageParser::FriendFunctionCallContext &context,
                          std::vector<Diagnostic> &diagnostics);
    void handleVariableDeclaration(EZLanguageParser::VariableDeclarationContext &context,
                                   std::vector<Diagnostic> &diagnostics);
    void handleAssignmentStatement(EZLanguageParser::AssignmentStatementContext &context,
                                   std::vector<Diagnostic> &diagnostics);
    void handleExpressionStatement(EZLanguageParser::ExpressionStatementContext &context,
                                   std::vector<Diagnostic> &diagnostics);
    std::optional<Value> executeFunction(const std::string &name,
                                         EZLanguageParser::FunctionDeclarationContext &ctx,
                                         const std::vector<Value> &args,
                                         std::vector<Diagnostic> &diagnostics);
    
    // Control flow execution
    bool executeIfStatement(EZLanguageParser::IfStatementContext &context,
                           std::vector<Diagnostic> &diagnostics,
                           bool &shouldBreak, bool &shouldContinue,
                           std::optional<Value> &returnValue);
    bool executeLoopStatement(EZLanguageParser::LoopStatementContext &context,
                             std::vector<Diagnostic> &diagnostics,
                             std::optional<Value> &returnValue);
    bool executeForeachStatement(EZLanguageParser::ForeachStatementContext &context,
                                std::vector<Diagnostic> &diagnostics,
                                std::optional<Value> &returnValue);
    bool executeStatementBlock(const std::vector<EZLanguageParser::StatementContext*> &statements,
                              std::vector<Diagnostic> &diagnostics,
                              bool &shouldBreak, bool &shouldContinue,
                              std::optional<Value> &returnValue);
    
    static size_t lineOf(const antlr4::ParserRuleContext &context);

    Value makeInt(int64_t v) const { return Value{SimpleType::Int, v, 0.0}; }
    Value makeFloat(double v) const { return Value{SimpleType::Float, 0, v}; }
    Value makeBool(bool v) const { return Value{SimpleType::Bool, v ? 1 : 0, 0.0}; }
    Value makeString(const std::string &s) const {
        Value v;
        v.type = SimpleType::String;
        v.stringValue = s;
        return v;
    }
    Value makeVoid() const { return Value{SimpleType::Void, 0, 0.0}; }

    std::ostream &output;
    std::unordered_map<std::string, std::filesystem::path> libraries;
    bool verboseOutput = false;

    // Semantic model and function definitions captured during analysis
    SemanticModel semanticModel;
    std::unordered_map<std::string, EZLanguageParser::FunctionDeclarationContext *> functions;

    // Simple call stack of variable frames (frame 0 = globals)
    std::vector<std::unordered_map<std::string, Value>> frames;
};
