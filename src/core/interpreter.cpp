#include "interpreter.h"
#include <dlfcn.h>

using namespace std;

SimpleInterpreter::SimpleInterpreter(std::ostream &stream, std::unordered_map<std::string, std::filesystem::path> friendLibs, bool verbose)
    : output(stream), libraries(std::move(friendLibs)), verboseOutput(verbose) {}

bool SimpleInterpreter::execute(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics)
{
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
    }

    return diagnostics.empty();
}

void SimpleInterpreter::printVariables() const
{
    if (variables.empty()) {
        output << "No variables declared." << '\n';
        return;
    }

    output << "Variable state:" << '\n';
    for (const auto &entry : variables) {
        output << "  " << entry.first << " = " << entry.second << '\n';
    }
}

std::optional<int> SimpleInterpreter::evaluateExpression(EZLanguageParser::ExpressionContext &expression,
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

    const auto &operators = expression.OPERATOR();
    for (size_t index = 0; index < operators.size(); ++index) {
        auto rhs = evaluatePrimary(*primaries[index + 1], diagnostics);
        if (!rhs.has_value()) {
            return std::nullopt;
        }

        const std::string opText = operators[index]->getText();
        if (opText == "+") {
            current = current.value() + rhs.value();
        } else if (opText == "-") {
            current = current.value() - rhs.value();
        } else if (opText == "*") {
            current = current.value() * rhs.value();
        } else if (opText == "/") {
            if (rhs.value() == 0) {
                diagnostics.push_back({lineOf(expression), "division by zero"});
                return std::nullopt;
            }
            current = current.value() / rhs.value();
        } else {
            diagnostics.push_back({lineOf(expression), "operator '" + opText + "' not supported in interpreter"});
            return std::nullopt;
        }
    }

    return current;
}

std::optional<int> SimpleInterpreter::evaluatePrimary(EZLanguageParser::PrimaryExpressionContext &primary,
                                                      std::vector<Diagnostic> &diagnostics)
{
    if (auto *identifier = primary.IDENTIFIER()) {
        const std::string name = identifier->getText();
        auto iterator = variables.find(name);
        if (iterator == variables.end()) {
            diagnostics.push_back({lineOf(primary), "unknown identifier '" + name + "'"});
            return std::nullopt;
        }
        return iterator->second;
    }

    if (auto *literal = primary.literal()) {
        if (auto *number = literal->NUMBER()) {
            const std::string text = number->getText();
            if (text.find('.') != std::string::npos) {
                diagnostics.push_back({lineOf(primary), "floating point literals not supported yet"});
                return std::nullopt;
            }
            return std::stoi(text);
        }
        if (auto *booleanTok = literal->BOOLEAN()) {
            const std::string val = booleanTok->getText();
            return val == "true" ? 1 : 0; // represent booleans as 1/0
        }
        diagnostics.push_back({lineOf(primary), "only numeric and boolean literals are supported"});
        return std::nullopt;
    }

    if (auto *call = primary.functionCall()) {
        // Built-in print/printf support
        const std::string fname = call->IDENTIFIER()->getText();
        if (fname == "print" || fname == "printf") {
            std::vector<std::string> rendered;
            if (auto *args = call->argumentList()) {
                for (auto *expr : args->expression()) {
                    // If single primary is a STRING literal, emit it raw (strip quotes)
                    auto prims = expr->primaryExpression();
                    if (prims.size() == 1) {
                        if (auto *lit = prims[0]->literal()) {
                            if (auto *strTok = lit->STRING()) {
                                std::string text = strTok->getText();
                                if (text.size() >= 2 && text.front() == '"' && text.back() == '"') {
                                    text = text.substr(1, text.size() - 2);
                                }
                                rendered.push_back(text);
                                continue;
                            } else if (lit->BOOLEAN()) {
                                rendered.push_back(lit->BOOLEAN()->getText());
                                continue;
                            } else if (lit->NUMBER()) {
                                rendered.push_back(lit->NUMBER()->getText());
                                continue;
                            }
                        }
                    }
                    // Fallback: evaluate as int expression
                    auto value = evaluateExpression(*expr, diagnostics);
                    if (!value.has_value()) {
                        rendered.push_back("<error>");
                    } else {
                        rendered.push_back(std::to_string(value.value()));
                    }
                }
            }
            // Join with space for simple printing
            std::string joined;
            for (size_t i = 0; i < rendered.size(); ++i) {
                if (i) joined += ' ';
                joined += rendered[i];
            }
            output << joined << '\n';
            // Return 0 as dummy value
            return 0;
        }

        diagnostics.push_back({lineOf(primary), "function calls are not supported in interpreter (only print/printf)"});
        return std::nullopt;
    }

    if (auto *friendCall = primary.friendFunctionCall()) {
        const std::string alias = friendCall->IDENTIFIER(0)->getText();
        const std::string symbol = friendCall->IDENTIFIER(1)->getText();

        auto it = libraries.find(alias);
        if (it == libraries.end()) {
            diagnostics.push_back({lineOf(primary), "no library found for alias '" + alias + "'"});
            return std::nullopt;
        }

        std::vector<int> args;
        if (auto *argsList = friendCall->argumentList()) {
            for (auto *expr : argsList->expression()) {
                auto value = evaluateExpression(*expr, diagnostics);
                if (!value.has_value()) return std::nullopt;
                args.push_back(value.value());
            }
        }

        auto result = callSymbol(it->second, symbol, args, diagnostics, lineOf(primary));
        if (result.has_value()) return result;
        return std::nullopt;
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

    std::vector<int> args;
    if (auto *argsList = context.argumentList()) {
        for (auto *expr : argsList->expression()) {
            auto value = evaluateExpression(*expr, diagnostics);
            if (!value.has_value()) return;
            args.push_back(value.value());
        }
    }

    auto result = callSymbol(it->second, symbol, args, diagnostics, lineOf(context));
    if (result.has_value() && verboseOutput) {
        output << "=> " << result.value() << '\n';
    }
}

std::optional<int> SimpleInterpreter::callSymbol(const std::filesystem::path &libPath,
                                                 const std::string &symbol,
                                                 const std::vector<int> &args,
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

    int result = 0;
    switch (args.size()) {
        case 0: {
            using Fn = int (*)();
            result = reinterpret_cast<Fn>(sym)();
            break;
        }
        case 1: {
            using Fn = int (*)(int);
            result = reinterpret_cast<Fn>(sym)(args[0]);
            break;
        }
        case 2: {
            using Fn = int (*)(int, int);
            result = reinterpret_cast<Fn>(sym)(args[0], args[1]);
            break;
        }
        case 3: {
            using Fn = int (*)(int, int, int);
            result = reinterpret_cast<Fn>(sym)(args[0], args[1], args[2]);
            break;
        }
        case 4: {
            using Fn = int (*)(int, int, int, int);
            result = reinterpret_cast<Fn>(sym)(args[0], args[1], args[2], args[3]);
            break;
        }
        default:
            diagnostics.push_back({line, "only up to 4 int arguments supported"});
            return std::nullopt;
    }

    // Library kept loaded via RTLD_NODELETE (required for Python embedding)
    return result;
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
    if (typeName != "int") {
        diagnostics.push_back({lineOf(context), "only 'int' variables are supported in interpreter"});
        return;
    }

    const std::string variableName = context.IDENTIFIER()->getText();
    if (variables.count(variableName) != 0) {
        diagnostics.push_back({lineOf(context), "variable '" + variableName + "' already declared"});
        return;
    }

    int value = 0;
    if (auto *expression = context.expression()) {
        auto evaluated = evaluateExpression(*expression, diagnostics);
        if (!evaluated.has_value()) {
            return;
        }
        value = evaluated.value();
    }

    variables.emplace(variableName, value);
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

    if (verboseOutput) output << "=> " << result.value() << '\n';
}

size_t SimpleInterpreter::lineOf(const antlr4::ParserRuleContext &context)
{
    return static_cast<size_t>(context.getStart()->getLine());
}
