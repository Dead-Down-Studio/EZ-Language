#include "interpreter.h"
#include <dlfcn.h>

using namespace std;

namespace {

std::string valueToString(const Value &v) {
    if (v.type == SimpleType::Bool) return v.intValue ? "true" : "false";
    if (v.type == SimpleType::Float) return std::to_string(v.floatValue);
    if (v.type == SimpleType::String) return v.stringValue;
    return std::to_string(v.intValue);
}

} // namespace

SimpleInterpreter::SimpleInterpreter(std::ostream &stream,
                                     std::unordered_map<std::string, std::filesystem::path> friendLibs,
                                     bool verbose,
                                     SemanticModel model)
    : output(stream), libraries(std::move(friendLibs)), verboseOutput(verbose), semanticModel(std::move(model))
{
    frames.emplace_back(); // global frame
}

bool SimpleInterpreter::execute(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics)
{
    // Collect function bodies for calls
    for (auto *stmt : program->statement()) {
        if (auto *fn = stmt->functionDeclaration()) {
            const std::string name = fn->IDENTIFIER()->getText();
            functions[name] = fn;
        }
    }

    for (auto *statement : program->statement()) {
        if (auto *varDecl = statement->variableDeclaration()) {
            handleVariableDeclaration(*varDecl, diagnostics);
            continue;
        }

        if (auto *exprStmt = statement->expressionStatement()) {
            handleExpressionStatement(*exprStmt, diagnostics);
            continue;
        }

        if (auto *friendCall = statement->friendFunctionCall()) {
            handleFriendCall(*friendCall, diagnostics);
            continue;
        }

        if (auto *assignStmt = statement->assignmentStatement()) {
            handleAssignmentStatement(*assignStmt, diagnostics);
            continue;
        }

        if (statement->functionDeclaration()) {
            // already indexed
            continue;
        }

        if (statement->returnStatement()) {
            diagnostics.push_back({lineOf(*statement), "return only valid inside functions"});
            continue;
        }
        
        if (auto *ctrlFlow = statement->controlFlowStatement()) {
            bool shouldBreak = false, shouldContinue = false;
            std::optional<Value> returnValue;
            
            if (auto *ifStmt = ctrlFlow->ifStatement()) {
                executeIfStatement(*ifStmt, diagnostics, shouldBreak, shouldContinue, returnValue);
            } else if (auto *loopStmt = ctrlFlow->loopStatement()) {
                executeLoopStatement(*loopStmt, diagnostics, returnValue);
            }
            continue;
        }
        
        if (auto *foreachStmt = statement->foreachStatement()) {
            std::optional<Value> returnValue;
            executeForeachStatement(*foreachStmt, diagnostics, returnValue);
            continue;
        }
    }

    return diagnostics.empty();
}

void SimpleInterpreter::printVariables() const
{
    const auto &globals = frames.front();
    if (globals.empty()) {
        output << "No variables declared." << '\n';
        return;
    }

    output << "Variable state:" << '\n';
    for (const auto &entry : globals) {
        output << "  " << entry.first << " = " << valueToString(entry.second) << '\n';
    }
}

std::optional<Value> SimpleInterpreter::evaluateExpression(EZLanguageParser::ExpressionContext &expression,
                                                           std::vector<Diagnostic> &diagnostics)
{
    const auto &primaries = expression.primaryExpression();
    if (primaries.empty()) {
        diagnostics.push_back({lineOf(expression), "empty expression"});
        return std::nullopt;
    }

    auto current = evaluatePrimary(*primaries.front(), diagnostics);
    if (!current.has_value()) {
        return std::nullopt;
    }

    std::vector<std::string> operators;
    for (auto *child : expression.children) {
        auto *terminal = dynamic_cast<antlr4::tree::TerminalNode *>(child);
        if (!terminal) continue;
        const auto type = terminal->getSymbol()->getType();
        if (type == EZLanguageParser::OPERATOR || type == EZLanguageParser::LT || type == EZLanguageParser::GT) {
            operators.push_back(terminal->getText());
        }
    }
    if (operators.empty() && primaries.size() > 1) {
        const std::string text = expression.getText();
        const std::vector<std::string> candidates = {"==", "!=", ">=", "<=", "&&", "||", ">", "<", "+", "-", "*", "/"};
        for (const auto &c : candidates) {
            if (text.find(c) != std::string::npos) {
                operators.push_back(c);
                break;
            }
        }
        if (operators.empty()) {
            for (auto *opTok : expression.OPERATOR()) operators.push_back(opTok->getText());
            if (operators.empty() && !expression.LT().empty()) operators.push_back("<");
            if (operators.empty() && !expression.GT().empty()) operators.push_back(">");
        }
    }

    for (size_t index = 0; index < operators.size(); ++index) {
        auto rhs = evaluatePrimary(*primaries[index + 1], diagnostics);
        if (!rhs.has_value()) {
            return std::nullopt;
        }

        const std::string opText = operators[index];
        if (opText == "+" || opText == "-" || opText == "*" || opText == "/") {
            // Support int and float arithmetic
            bool isFloat = (current->type == SimpleType::Float || rhs->type == SimpleType::Float);
            bool hasNumeric = ((current->type == SimpleType::Int || current->type == SimpleType::Float) &&
                              (rhs->type == SimpleType::Int || rhs->type == SimpleType::Float));
            
            if (!hasNumeric) {
                diagnostics.push_back({lineOf(expression), "arithmetic operator '" + opText + "' expects numeric operands"});
                return std::nullopt;
            }
            
            // Convert to double for calculation
            double lval = (current->type == SimpleType::Float) ? current->floatValue : static_cast<double>(current->intValue);
            double rval = (rhs->type == SimpleType::Float) ? rhs->floatValue : static_cast<double>(rhs->intValue);
            
            if (opText == "/" && rval == 0.0) {
                diagnostics.push_back({lineOf(expression), "division by zero"});
                return std::nullopt;
            }
            
            double result = 0.0;
            if (opText == "+") result = lval + rval;
            else if (opText == "-") result = lval - rval;
            else if (opText == "*") result = lval * rval;
            else if (opText == "/") result = lval / rval;
            
            // Return float if either operand is float, otherwise int
            if (isFloat) {
                current = makeFloat(result);
            } else {
                current = makeInt(static_cast<int64_t>(result));
            }
        } else if (opText == "==" || opText == "!=") {
            if (current->type != rhs->type) {
                diagnostics.push_back({lineOf(expression), "comparison between mismatched types"});
            }
            bool res = (current->intValue == rhs->intValue);
            if (opText == "!=") res = !res;
            current = makeBool(res);
        } else if (opText == ">" || opText == "<" || opText == ">=" || opText == "<=") {
            // Support numeric comparisons (int and float)
            bool hasNumeric = ((current->type == SimpleType::Int || current->type == SimpleType::Float) &&
                              (rhs->type == SimpleType::Int || rhs->type == SimpleType::Float));
            if (!hasNumeric) {
                diagnostics.push_back({lineOf(expression), "relational operator '" + opText + "' expects numeric operands"});
                return std::nullopt;
            }
            
            double lval = (current->type == SimpleType::Float) ? current->floatValue : static_cast<double>(current->intValue);
            double rval = (rhs->type == SimpleType::Float) ? rhs->floatValue : static_cast<double>(rhs->intValue);
            
            bool res = false;
            if (opText == ">") res = lval > rval;
            else if (opText == "<") res = lval < rval;
            else if (opText == ">=") res = lval >= rval;
            else if (opText == "<=") res = lval <= rval;
            current = makeBool(res);
        } else if (opText == "&&" || opText == "||") {
            if (current->type != SimpleType::Bool || rhs->type != SimpleType::Bool) {
                diagnostics.push_back({lineOf(expression), "logical operator '" + opText + "' expects boolean operands"});
                return std::nullopt;
            }
            bool res = (opText == "&&") ? (current->intValue && rhs->intValue)
                                         : (current->intValue || rhs->intValue);
            current = makeBool(res);
        } else {
            diagnostics.push_back({lineOf(expression), "operator '" + opText + "' not supported in interpreter"});
            return std::nullopt;
        }
    }

    return current;
}

std::optional<Value> SimpleInterpreter::evaluatePrimary(EZLanguageParser::PrimaryExpressionContext &primary,
                                                        std::vector<Diagnostic> &diagnostics)
{
    if (auto *identifier = primary.IDENTIFIER()) {
        const std::string name = identifier->getText();
        for (auto it = frames.rbegin(); it != frames.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) return found->second;
        }
        diagnostics.push_back({lineOf(primary), "unknown identifier '" + name + "'"});
        return std::nullopt;
    }

    if (auto *literal = primary.literal()) {
        if (auto *number = literal->NUMBER()) {
            const std::string text = number->getText();
            if (text.find('.') != std::string::npos) {
                return makeFloat(std::stod(text));
            }
            return makeInt(std::stoll(text));
        }
        if (auto *booleanTok = literal->BOOLEAN()) {
            const std::string val = booleanTok->getText();
            return makeBool(val == "true");
        }
        if (auto *stringTok = literal->STRING()) {
            std::string text = stringTok->getText();
            // Remove surrounding quotes
            if (text.size() >= 2 && text.front() == '"' && text.back() == '"') {
                text = text.substr(1, text.size() - 2);
            }
            Value v;
            v.type = SimpleType::String;
            v.stringValue = text;
            return v;
        }
        diagnostics.push_back({lineOf(primary), "only numeric, boolean, and string literals are supported"});
        return std::nullopt;
    }

    if (auto *call = primary.functionCall()) {
        const std::string fname = call->IDENTIFIER()->getText();
        // Built-in print/printf support
        if (fname == "print" || fname == "printf") {
            std::vector<std::string> rendered;
            if (auto *args = call->argumentList()) {
                for (auto *expr : args->expression()) {
                    auto value = evaluateExpression(*expr, diagnostics);
                    if (!value.has_value()) {
                        rendered.push_back("<error>");
                    } else {
                        rendered.push_back(valueToString(value.value()));
                    }
                }
            }
            std::string joined;
            for (size_t i = 0; i < rendered.size(); ++i) {
                if (i) joined += ' ';
                joined += rendered[i];
            }
            output << joined << '\n';
            return makeInt(0);
        }

        // User-defined function call
        auto fnIt = functions.find(fname);
        if (fnIt == functions.end()) {
            diagnostics.push_back({lineOf(primary), "unknown function '" + fname + "'"});
            return std::nullopt;
        }

        std::vector<Value> args;
        if (auto *argList = call->argumentList()) {
            for (auto *expr : argList->expression()) {
                auto v = evaluateExpression(*expr, diagnostics);
                if (!v.has_value()) return std::nullopt;
                args.push_back(*v);
            }
        }

        return executeFunction(fname, *fnIt->second, args, diagnostics);
    }

    if (auto *friendCall = primary.friendFunctionCall()) {
        const std::string alias = friendCall->IDENTIFIER(0)->getText();
        const std::string symbol = friendCall->IDENTIFIER(1)->getText();

        auto it = libraries.find(alias);
        if (it == libraries.end()) {
            diagnostics.push_back({lineOf(primary), "no library found for alias '" + alias + "'"});
            return std::nullopt;
        }

        std::vector<Value> args;
        if (auto *argsList = friendCall->argumentList()) {
            for (auto *expr : argsList->expression()) {
                auto value = evaluateExpression(*expr, diagnostics);
                if (!value.has_value()) return std::nullopt;
                if (value->type != SimpleType::Int && value->type != SimpleType::Float) {
                    diagnostics.push_back({lineOf(*expr), "friend calls only support numeric arguments"});
                    return std::nullopt;
                }
                args.push_back(*value);
            }
        }

        return callSymbol(it->second, symbol, args, diagnostics, lineOf(primary));
    }

    if (auto *nested = primary.expression()) {
        return evaluateExpression(*nested, diagnostics);
    }

    diagnostics.push_back({lineOf(primary), "unsupported primary expression"});
    return std::nullopt;
}

void SimpleInterpreter::handleFriendCall(EZLanguageParser::FriendFunctionCallContext &context,
                                         std::vector<Diagnostic> &diagnostics)
{
    const std::string alias = context.IDENTIFIER(0)->getText();
    const std::string symbol = context.IDENTIFIER(1)->getText();

    auto it = libraries.find(alias);
    if (it == libraries.end()) {
        diagnostics.push_back({lineOf(context), "no library found for alias '" + alias + "'"});
        return;
    }

    std::vector<Value> args;
    if (auto *argsList = context.argumentList()) {
        for (auto *expr : argsList->expression()) {
            auto value = evaluateExpression(*expr, diagnostics);
            if (!value.has_value()) return;
            if (value->type != SimpleType::Int && value->type != SimpleType::Float) {
                diagnostics.push_back({lineOf(*expr), "friend calls only support numeric arguments"});
                return;
            }
            args.push_back(*value);
        }
    }

    auto result = callSymbol(it->second, symbol, args, diagnostics, lineOf(context));
    if (result.has_value() && verboseOutput) {
        if (result->type == SimpleType::Int) {
            output << "=> " << result->intValue << '\n';
        } else if (result->type == SimpleType::Float) {
            output << "=> " << result->floatValue << '\n';
        }
    }
}

std::optional<Value> SimpleInterpreter::callSymbol(const std::filesystem::path &libPath,
                                                   const std::string &symbol,
                                                   const std::vector<Value> &args,
                                                   std::vector<Diagnostic> &diagnostics,
                                                   size_t line)
{
    // RTLD_NODELETE: keep library loaded (essential for Python embedding & static state)
    void *handle = dlopen(libPath.c_str(), RTLD_LAZY | RTLD_NODELETE);
    if (!handle) {
        diagnostics.push_back({line, std::string("dlopen failed: ") + dlerror()});
        return std::nullopt;
    }

    dlerror();
    void *sym = dlsym(handle, symbol.c_str());
    const char *err = dlerror();
    if (err) {
        diagnostics.push_back({line, std::string("dlsym failed for '") + symbol + "': " + err});
        return std::nullopt;
    }

    // Check if any argument is float to determine call mode
    bool hasFloat = false;
    for (const auto &arg : args) {
        if (arg.type == SimpleType::Float) {
            hasFloat = true;
            break;
        }
    }

    if (hasFloat) {
        // Call as double function
        std::vector<double> doubleArgs;
        for (const auto &arg : args) {
            if (arg.type == SimpleType::Int) {
                doubleArgs.push_back(static_cast<double>(arg.intValue));
            } else {
                doubleArgs.push_back(arg.floatValue);
            }
        }

        double result = 0.0;
        switch (doubleArgs.size()) {
            case 0: {
                using Fn = double (*)();
                result = reinterpret_cast<Fn>(sym)();
                break;
            }
            case 1: {
                using Fn = double (*)(double);
                result = reinterpret_cast<Fn>(sym)(doubleArgs[0]);
                break;
            }
            case 2: {
                using Fn = double (*)(double, double);
                result = reinterpret_cast<Fn>(sym)(doubleArgs[0], doubleArgs[1]);
                break;
            }
            case 3: {
                using Fn = double (*)(double, double, double);
                result = reinterpret_cast<Fn>(sym)(doubleArgs[0], doubleArgs[1], doubleArgs[2]);
                break;
            }
            case 4: {
                using Fn = double (*)(double, double, double, double);
                result = reinterpret_cast<Fn>(sym)(doubleArgs[0], doubleArgs[1], doubleArgs[2], doubleArgs[3]);
                break;
            }
            default:
                diagnostics.push_back({line, "only up to 4 arguments supported"});
                return std::nullopt;
        }

        Value retVal;
        retVal.type = SimpleType::Float;
        retVal.floatValue = result;
        return retVal;
    } else {
        // Call as int function
        std::vector<int> intArgs;
        for (const auto &arg : args) {
            intArgs.push_back(static_cast<int>(arg.intValue));
        }

        int result = 0;
        switch (intArgs.size()) {
            case 0: {
                using Fn = int (*)();
                result = reinterpret_cast<Fn>(sym)();
                break;
            }
            case 1: {
                using Fn = int (*)(int);
                result = reinterpret_cast<Fn>(sym)(intArgs[0]);
                break;
            }
            case 2: {
                using Fn = int (*)(int, int);
                result = reinterpret_cast<Fn>(sym)(intArgs[0], intArgs[1]);
                break;
            }
            case 3: {
                using Fn = int (*)(int, int, int);
                result = reinterpret_cast<Fn>(sym)(intArgs[0], intArgs[1], intArgs[2]);
                break;
            }
            case 4: {
                using Fn = int (*)(int, int, int, int);
                result = reinterpret_cast<Fn>(sym)(intArgs[0], intArgs[1], intArgs[2], intArgs[3]);
                break;
            }
            default:
                diagnostics.push_back({line, "only up to 4 arguments supported"});
                return std::nullopt;
        }

        Value retVal;
        retVal.type = SimpleType::Int;
        retVal.intValue = result;
        return retVal;
    }

    // Library kept loaded via RTLD_NODELETE (required for Python embedding)
}

void SimpleInterpreter::handleVariableDeclaration(EZLanguageParser::VariableDeclarationContext &context,
                                                  std::vector<Diagnostic> &diagnostics)
{
    auto *typeContext = context.type();
    if (typeContext == nullptr) {
        diagnostics.push_back({lineOf(context), "missing type in variable declaration"});
        return;
    }

    const std::string typeName = typeContext->getText();
    SimpleType declType = SimpleType::Unknown;
    if (typeName == "int") declType = SimpleType::Int;
    else if (typeName == "float") declType = SimpleType::Float;
    else if (typeName == "boolean") declType = SimpleType::Bool;
    else {
        diagnostics.push_back({lineOf(context), "only 'int', 'float', and 'boolean' variables are supported in interpreter"});
        return;
    }

    const std::string variableName = context.IDENTIFIER()->getText();
    const size_t frameIndex = frames.size() - 1; // capture index to avoid dangling refs if frames reallocates during evaluation

    if (frames[frameIndex].count(variableName) != 0) {
        diagnostics.push_back({lineOf(context), "variable '" + variableName + "' already declared"});
        return;
    }

    Value value;
    if (declType == SimpleType::Bool) {
        value = makeBool(false);
    } else if (declType == SimpleType::Float) {
        value = makeFloat(0.0);
    } else {
        value = makeInt(0);
    }
    
    if (auto *expression = context.expression()) {
        auto evaluated = evaluateExpression(*expression, diagnostics);
        if (!evaluated.has_value()) {
            return;
        }
        if (evaluated->type != declType) {
            diagnostics.push_back({lineOf(context), "cannot assign expression of type '" + toString(evaluated->type) + "' to variable of type '" + typeName + "'"});
            return;
        }
        value = *evaluated;
    }

    frames[frameIndex].emplace(variableName, value);
}

void SimpleInterpreter::handleAssignmentStatement(EZLanguageParser::AssignmentStatementContext &context,
                                                  std::vector<Diagnostic> &diagnostics)
{
    const std::string variableName = context.IDENTIFIER()->getText();
    
    // Find the variable in the scope chain
    int frameIndex = -1;
    for (int i = static_cast<int>(frames.size()) - 1; i >= 0; --i) {
        if (frames[i].count(variableName)) {
            frameIndex = i;
            break;
        }
    }
    
    if (frameIndex == -1) {
        diagnostics.push_back({lineOf(context), "variable '" + variableName + "' not declared"});
        return;
    }
    
    auto *expression = context.expression();
    if (!expression) {
        diagnostics.push_back({lineOf(context), "missing expression in assignment"});
        return;
    }
    
    auto evaluated = evaluateExpression(*expression, diagnostics);
    if (!evaluated.has_value()) {
        return;
    }
    
    // Type check
    const Value &existingValue = frames[frameIndex][variableName];
    if (existingValue.type != evaluated->type && existingValue.type != SimpleType::Unknown) {
        diagnostics.push_back({lineOf(context), "cannot assign expression of type '" + toString(evaluated->type) + "' to variable of type '" + toString(existingValue.type) + "'"});
        return;
    }
    
    frames[frameIndex][variableName] = *evaluated;
    
    if (verboseOutput) output << variableName << " = " << valueToString(*evaluated) << '\n';
}

void SimpleInterpreter::handleExpressionStatement(EZLanguageParser::ExpressionStatementContext &context,
                                                  std::vector<Diagnostic> &diagnostics)
{
    auto *expression = context.expression();
    if (expression == nullptr) {
        diagnostics.push_back({lineOf(context), "missing expression"});
        return;
    }

    auto result = evaluateExpression(*expression, diagnostics);
    if (!result.has_value()) {
        return;
    }

    if (verboseOutput) output << "=> " << valueToString(result.value()) << '\n';
}

std::optional<Value> SimpleInterpreter::executeFunction(const std::string &name,
                                                        EZLanguageParser::FunctionDeclarationContext &ctx,
                                                        const std::vector<Value> &args,
                                                        std::vector<Diagnostic> &diagnostics)
{
    auto sigIt = semanticModel.functions.find(name);
    if (sigIt == semanticModel.functions.end()) {
        diagnostics.push_back({lineOf(ctx), "no signature information for function '" + name + "'"});
        return std::nullopt;
    }
    const FunctionInfo &sig = sigIt->second;

    if (args.size() != sig.params.size()) {
        diagnostics.push_back({lineOf(ctx), "function '" + name + "' expects " + to_string(sig.params.size()) + " argument(s)"});
        return std::nullopt;
    }

    for (size_t i = 0; i < args.size(); ++i) {
        if (sig.params[i].type != SimpleType::Unknown && args[i].type != sig.params[i].type) {
            diagnostics.push_back({lineOf(ctx), "argument " + to_string(i+1) + " type mismatch: expected '" + toString(sig.params[i].type) + "' got '" + toString(args[i].type) + "'"});
            return std::nullopt;
        }
    }

    frames.emplace_back();
    auto &frame = frames.back();
    for (size_t i = 0; i < args.size(); ++i) {
        frame.emplace(sig.params[i].name, args[i]);
    }

    std::optional<Value> returnValue;
    bool shouldBreak = false, shouldContinue = false;
    
    executeStatementBlock(ctx.statement(), diagnostics, shouldBreak, shouldContinue, returnValue);

    frames.pop_back();

    if (sig.returnType == SimpleType::Void) {
        return makeVoid();
    }

    if (!returnValue.has_value()) {
        diagnostics.push_back({lineOf(ctx), "function '" + name + "' did not return a value"});
        return std::nullopt;
    }

    if (returnValue->type != sig.returnType) {
        diagnostics.push_back({lineOf(ctx), "function '" + name + "' returned '" + toString(returnValue->type) + "' but expected '" + toString(sig.returnType) + "'"});
        return std::nullopt;
    }

    return returnValue;
}

size_t SimpleInterpreter::lineOf(const antlr4::ParserRuleContext &context)
{
    return static_cast<size_t>(context.getStart()->getLine());
}

bool SimpleInterpreter::executeStatementBlock(const std::vector<EZLanguageParser::StatementContext*> &statements,
                                             std::vector<Diagnostic> &diagnostics,
                                             bool &shouldBreak, bool &shouldContinue,
                                             std::optional<Value> &returnValue)
{
    for (auto *stmt : statements) {
        if (auto *vd = stmt->variableDeclaration()) {
            handleVariableDeclaration(*vd, diagnostics);
            if (!diagnostics.empty()) return false;
            continue;
        }

        if (auto *exprStmt = stmt->expressionStatement()) {
            handleExpressionStatement(*exprStmt, diagnostics);
            if (!diagnostics.empty()) return false;
            continue;
        }

        if (auto *friendCall = stmt->friendFunctionCall()) {
            handleFriendCall(*friendCall, diagnostics);
            if (!diagnostics.empty()) return false;
            continue;
        }

        if (auto *assignStmt = stmt->assignmentStatement()) {
            handleAssignmentStatement(*assignStmt, diagnostics);
            if (!diagnostics.empty()) return false;
            continue;
        }

        if (auto *ret = stmt->returnStatement()) {
            if (ret->expression()) {
                returnValue = evaluateExpression(*ret->expression(), diagnostics);
            } else {
                returnValue = makeVoid();
            }
            return true; // signal return
        }
        
        if (stmt->breakStatement()) {
            shouldBreak = true;
            return true;
        }
        
        if (stmt->continueStatement()) {
            shouldContinue = true;
            return true;
        }
        
        if (auto *ctrlFlow = stmt->controlFlowStatement()) {
            if (auto *ifStmt = ctrlFlow->ifStatement()) {
                if (!executeIfStatement(*ifStmt, diagnostics, shouldBreak, shouldContinue, returnValue)) {
                    return false;
                }
                if (shouldBreak || shouldContinue || returnValue.has_value()) {
                    return true;
                }
            } else if (auto *loopStmt = ctrlFlow->loopStatement()) {
                if (!executeLoopStatement(*loopStmt, diagnostics, returnValue)) {
                    return false;
                }
                if (returnValue.has_value()) {
                    return true;
                }
            }
            continue;
        }
        
        if (auto *foreachStmt = stmt->foreachStatement()) {
            if (!executeForeachStatement(*foreachStmt, diagnostics, returnValue)) {
                return false;
            }
            if (returnValue.has_value()) {
                return true;
            }
            continue;
        }
    }
    return true;
}

bool SimpleInterpreter::executeIfStatement(EZLanguageParser::IfStatementContext &context,
                                          std::vector<Diagnostic> &diagnostics,
                                          bool &shouldBreak, bool &shouldContinue,
                                          std::optional<Value> &returnValue)
{
    auto expressions = context.expression();
    auto statements = context.statement();
    
    if (expressions.empty()) {
        diagnostics.push_back({lineOf(context), "if statement requires condition"});
        return false;
    }
    
    // Evaluate main if condition
    auto condition = evaluateExpression(*expressions[0], diagnostics);
    if (!condition.has_value()) return false;
    
    if (condition->type != SimpleType::Bool) {
        diagnostics.push_back({lineOf(context), "if condition must be boolean"});
        return false;
    }
    
    // Grammar: 'if' '(' expression ')' '{' statement* '}' ('else if' '(' expression ')' '{' statement* '}')* ('else' '{' statement* '}')?
    // This creates expression and statement lists alternating for each if/else if, then remaining statements for else
    
    size_t exprIdx = 0;
    size_t stmtIdx = 0;
    
    // Check main if condition
    if (condition->intValue != 0) {
        // Execute main if block - get statements until we hit an else if or end
        std::vector<EZLanguageParser::StatementContext*> block;
        while (stmtIdx < statements.size()) {
            // Simple approach: all statements are in one flat list
            // We need to count braces in grammar to determine blocks
            // For now, execute all statements in the if block
            block.push_back(statements[stmtIdx++]);
            // Break at first statement (simplified - grammar needs better block handling)
            break;
        }
        return executeStatementBlock(block, diagnostics, shouldBreak, shouldContinue, returnValue);
    }
    
    // Note: Full else if/else support requires better grammar analysis
    // For MVP, this handles simple if statements
    
    return true;
}

bool SimpleInterpreter::executeLoopStatement(EZLanguageParser::LoopStatementContext &context,
                                            std::vector<Diagnostic> &diagnostics,
                                            std::optional<Value> &returnValue)
{
    // Grammar: (' while' | 'for') '(' expression? ')' '{' statement* '}'
    // Determine loop type from the token text
    std::string loopType = context.getStart()->getText();
    auto statements = context.statement();
    auto expr = context.expression();
    
    if (loopType == "for") {
        // For loops in this simple form just evaluate the condition like while
        // Full C-style for loops would need: for(init; condition; increment)
        // But our grammar doesn't support that yet
        diagnostics.push_back({lineOf(context), "for loops not fully implemented (use while instead)"});
        return false;
    }
    
    // While loop execution
    while (true) {
        if (expr) {
            auto condition = evaluateExpression(*expr, diagnostics);
            if (!condition.has_value()) return false;
            
            if (condition->type != SimpleType::Bool) {
                diagnostics.push_back({lineOf(context), "loop condition must be boolean"});
                return false;
            }
            
            if (condition->intValue == 0) {
                break; // Exit loop
            }
        } else {
            // Infinite loop without condition - dangerous but allow it
            // Must have break inside
        }
        
        bool shouldBreak = false, shouldContinue = false;
        if (!statements.empty()) {
            if (!executeStatementBlock(statements, diagnostics, shouldBreak, shouldContinue, returnValue)) {
                return false;
            }
        }
        
        if (returnValue.has_value()) {
            break; // Early return from function
        }
        
        if (shouldBreak) {
            break; // Break out of loop
        }
        
        // shouldContinue: just continue to next iteration (already at end of loop body)
        
        if (!expr) {
            // Infinite loop with no break hit - prevent actual infinite loop in interpreter
            diagnostics.push_back({lineOf(context), "infinite loop detected without break statement"});
            return false;
        }
    }
    
    return true;
}

bool SimpleInterpreter::executeForeachStatement(EZLanguageParser::ForeachStatementContext &context,
                                               std::vector<Diagnostic> &diagnostics,
                                               std::optional<Value> &returnValue)
{
    diagnostics.push_back({lineOf(context), "foreach not yet implemented (arrays not supported)"});
    return false;
}
