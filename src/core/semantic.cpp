#include "semantic.h"
#include "types.h"
#include "../../generated/EZLanguageParser.h"

#include <unordered_set>

using namespace std;

namespace {

size_t lineOf(const antlr4::ParserRuleContext &ctx) {
    return static_cast<size_t>(ctx.getStart()->getLine());
}

vector<string> collectOperators(EZLanguageParser::ExpressionContext &expr) {
    vector<string> result;
    // Preserve source order by walking children and capturing operator tokens
    for (auto *child : expr.children) {
        auto *terminal = dynamic_cast<antlr4::tree::TerminalNode *>(child);
        if (!terminal) continue;
        const auto type = terminal->getSymbol()->getType();
        if (type == EZLanguageParser::OPERATOR || type == EZLanguageParser::LT || type == EZLanguageParser::GT) {
            result.push_back(terminal->getText());
        }
    }

    if (result.empty() && expr.primaryExpression().size() > 1) {
        // Fallback: scan raw text to recover simple operators when token lists are empty
        const std::string text = expr.getText();
        const std::vector<std::string> candidates = {"==", "!=", ">=", "<=", "&&", "||", ">", "<", "+", "-", "*", "/"};
        for (const auto &c : candidates) {
            if (text.find(c) != std::string::npos) {
                result.push_back(c);
                break; // single-operator expressions for now
            }
        }
    }
    return result;
}

SimpleType parseType(EZLanguageParser::TypeContext *ctx, vector<Diagnostic> &diagnostics) {
    if (!ctx) return SimpleType::Unknown;
    auto *base = ctx->baseType();
    if (!base) return SimpleType::Unknown;
    const string t = base->getText();
    if (t == "int") return SimpleType::Int;
    if (t == "float") return SimpleType::Float;
    if (t == "boolean") return SimpleType::Bool;
    if (t == "void") return SimpleType::Void;
    if (t == "string") return SimpleType::String;
    diagnostics.push_back({lineOf(*ctx), "type '" + t + "' is not supported yet"});
    return SimpleType::Unknown;
}

// Check if a value of type 'from' can be assigned to a variable of type 'to'
bool isAssignable(SimpleType to, SimpleType from) {
    if (to == from) return true;
    // Allow int -> float implicit conversion
    if (to == SimpleType::Float && from == SimpleType::Int) return true;
    return false;
}

SimpleType inferExpressionType(EZLanguageParser::ExpressionContext &expr,
                               const unordered_map<string, VariableInfo> &vars,
                               const unordered_map<string, FunctionInfo> &fns,
                               vector<Diagnostic> &diagnostics);

SimpleType inferPrimary(EZLanguageParser::PrimaryExpressionContext &p,
                        const unordered_map<string, VariableInfo> &vars,
                        const unordered_map<string, FunctionInfo> &fns,
                        vector<Diagnostic> &diagnostics)
{
    if (auto *id = p.IDENTIFIER()) {
        auto it = vars.find(id->getText());
        if (it == vars.end()) {
            diagnostics.push_back({lineOf(p), "unknown identifier '" + id->getText() + "'"});
            return SimpleType::Unknown;
        }
        return it->second.type;
    }

    if (auto *lit = p.literal()) {
        if (lit->NUMBER()) {
            // Check if it's a float (contains decimal point)
            std::string numText = lit->NUMBER()->getText();
            if (numText.find('.') != std::string::npos) {
                return SimpleType::Float;
            }
            return SimpleType::Int;
        }
        if (lit->BOOLEAN()) return SimpleType::Bool;
        if (lit->STRING()) return SimpleType::String;
        diagnostics.push_back({lineOf(p), "literal type not supported here"});
        return SimpleType::Unknown;
    }

    if (auto *call = p.functionCall()) {
        const string name = call->IDENTIFIER()->getText();
        auto it = fns.find(name);
        if (it == fns.end()) {
            diagnostics.push_back({lineOf(p), "unknown function '" + name + "'"});
            return SimpleType::Unknown;
        }
        const auto &sig = it->second;
        size_t argc = call->argumentList() ? call->argumentList()->expression().size() : 0;
        // printf accepts variable number of arguments
        bool isVariadic = (name == "printf");
        if (!isVariadic && argc != sig.params.size()) {
            diagnostics.push_back({lineOf(p), "function '" + name + "' expects " + to_string(sig.params.size()) + " argument(s)"});
        }
        for (size_t i = 0; call->argumentList() && i < call->argumentList()->expression().size(); ++i) {
            auto argType = inferExpressionType(*call->argumentList()->expression(i), vars, fns, diagnostics);
            // For variadic functions like printf, skip parameter type checking
            if (!isVariadic && i < sig.params.size() && argType != SimpleType::Unknown && sig.params[i].type != SimpleType::Unknown && argType != sig.params[i].type) {
                diagnostics.push_back({lineOf(*call->argumentList()->expression(i)), "argument " + to_string(i+1) + " type mismatch: expected '" + toString(sig.params[i].type) + "' got '" + toString(argType) + "'"});
            }
        }
        return sig.returnType;
    }

    if (auto *friendCall = p.friendFunctionCall()) {
        // Friend calls support numeric types (int/float) with appropriate function signatures.
        // Determine return type: if any arg is float, call as double->double; else int->int.
        bool hasFloat = false;
        if (auto *args = friendCall->argumentList()) {
            for (auto *ex : args->expression()) {
                auto t = inferExpressionType(*ex, vars, fns, diagnostics);
                if (t != SimpleType::Unknown && !isNumeric(t)) {
                    diagnostics.push_back({lineOf(*ex), "friend calls only support numeric arguments"});
                }
                if (t == SimpleType::Float) {
                    hasFloat = true;
                }
            }
        }
        return hasFloat ? SimpleType::Float : SimpleType::Int;
    }

    if (auto *inner = p.expression()) {
        return inferExpressionType(*inner, vars, fns, diagnostics);
    }

    diagnostics.push_back({lineOf(p), "unsupported primary expression"});
    return SimpleType::Unknown;
}

SimpleType inferExpressionType(EZLanguageParser::ExpressionContext &expr,
                               const unordered_map<string, VariableInfo> &vars,
                               const unordered_map<string, FunctionInfo> &fns,
                               vector<Diagnostic> &diagnostics)
{
    const auto &primaries = expr.primaryExpression();
    if (primaries.empty()) {
        diagnostics.push_back({lineOf(expr), "empty expression"});
        return SimpleType::Unknown;
    }

    auto current = inferPrimary(*primaries.front(), vars, fns, diagnostics);
    // Collect operators including LT and GT tokens
    vector<string> ops = collectOperators(expr);

    for (size_t i = 0; i < ops.size(); ++i) {
        const string op = ops[i];
        auto rhs = inferPrimary(*primaries[i + 1], vars, fns, diagnostics);

        // Simple typing rules aligned with interpreter/codegen support
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            if (!isNumeric(current) || !isNumeric(rhs)) {
                diagnostics.push_back({lineOf(expr), "arithmetic operator '" + op + "' expects numeric operands"});
            }
            // Result type promotion: if either operand is float, result is float
            current = (current == SimpleType::Float || rhs == SimpleType::Float) ? SimpleType::Float : SimpleType::Int;
        } else if (op == "==" || op == "!=") {
            if (current != SimpleType::Unknown && rhs != SimpleType::Unknown && current != rhs) {
                diagnostics.push_back({lineOf(expr), "comparison between mismatched types"});
            }
            current = SimpleType::Bool;
        } else if (op == ">" || op == "<" || op == ">=" || op == "<=") {
            if (!isNumeric(current) || !isNumeric(rhs)) {
                diagnostics.push_back({lineOf(expr), "relational operator '" + op + "' expects numeric operands"});
            }
            current = SimpleType::Bool;
        } else if (op == "&&" || op == "||") {
            if (!isBoolean(current) || !isBoolean(rhs)) {
                diagnostics.push_back({lineOf(expr), "logical operator '" + op + "' expects boolean operands"});
            }
            current = SimpleType::Bool;
        } else {
            diagnostics.push_back({lineOf(expr), "operator '" + op + "' not supported yet"});
            return SimpleType::Unknown;
        }
    }

    return current;
}

void typeCheckStatementList(const vector<EZLanguageParser::StatementContext*> &statements,
                            unordered_map<string, VariableInfo> &scope,
                            unordered_map<string, VariableInfo> &locals,
                            const unordered_map<string, FunctionInfo> &functions,
                            SimpleType fnReturnType,
                            bool &sawReturn,
                            vector<Diagnostic> &diagnostics);

void typeCheckAssignment(EZLanguageParser::AssignmentStatementContext &assign,
                         unordered_map<string, VariableInfo> &scope,
                         const unordered_map<string, FunctionInfo> &functions,
                         vector<Diagnostic> &diagnostics)
{
    const string name = assign.IDENTIFIER()->getText();
    auto it = scope.find(name);
    if (it == scope.end()) {
        diagnostics.push_back({lineOf(assign), "variable '" + name + "' not declared"});
        return;
    }

    auto *expr = assign.expression();
    if (!expr) {
        diagnostics.push_back({lineOf(assign), "missing expression in assignment"});
        return;
    }

    auto et = inferExpressionType(*expr, scope, functions, diagnostics);
    if (it->second.type != SimpleType::Unknown && et != SimpleType::Unknown && !isAssignable(it->second.type, et)) {
        diagnostics.push_back({lineOf(assign), "cannot assign expression of type '" + toString(et) + "' to variable of type '" + toString(it->second.type) + "'"});
    }
}

void typeCheckIf(EZLanguageParser::IfStatementContext &ifStmt,
                 unordered_map<string, VariableInfo> &scope,
                 unordered_map<string, VariableInfo> &locals,
                 const unordered_map<string, FunctionInfo> &functions,
                 SimpleType fnReturnType,
                 bool &sawReturn,
                 vector<Diagnostic> &diagnostics)
{
    for (auto *expr : ifStmt.expression()) {
        auto t = inferExpressionType(*expr, scope, functions, diagnostics);
        if (t != SimpleType::Unknown && t != SimpleType::Bool) {
            diagnostics.push_back({lineOf(*expr), "if condition must be boolean"});
        }
    }

    // The current grammar flattens branch statements; type-check all nested statements.
    typeCheckStatementList(ifStmt.statement(), scope, locals, functions, fnReturnType, sawReturn, diagnostics);
}

void typeCheckLoop(EZLanguageParser::LoopStatementContext &loopStmt,
                   unordered_map<string, VariableInfo> &scope,
                   unordered_map<string, VariableInfo> &locals,
                   const unordered_map<string, FunctionInfo> &functions,
                   SimpleType fnReturnType,
                   bool &sawReturn,
                   vector<Diagnostic> &diagnostics)
{
    if (auto *whileCtx = loopStmt.whileLoop()) {
        if (auto *cond = whileCtx->expression()) {
            auto t = inferExpressionType(*cond, scope, functions, diagnostics);
            if (t != SimpleType::Unknown && t != SimpleType::Bool) {
                diagnostics.push_back({lineOf(*cond), "loop condition must be boolean"});
            }
        }
        typeCheckStatementList(whileCtx->statement(), scope, locals, functions, fnReturnType, sawReturn, diagnostics);
        return;
    }

    if (auto *forCtx = loopStmt.forLoop()) {
        // Loop-scoped symbol table for initializer declarations.
        auto forScope = scope;
        auto forLocals = locals;

        if (auto *init = forCtx->forInit()) {
            if (auto *initVar = dynamic_cast<EZLanguageParser::ForInitVarDeclContext *>(init)) {
                const string name = initVar->IDENTIFIER()->getText();
                auto t = parseType(initVar->type(), diagnostics);
                if (forLocals.count(name)) {
                    diagnostics.push_back({lineOf(*initVar), "duplicate local variable '" + name + "'"});
                }
                forLocals[name] = VariableInfo{t, lineOf(*initVar)};
                forScope[name] = VariableInfo{t, lineOf(*initVar)};
                if (auto *expr = initVar->expression()) {
                    auto et = inferExpressionType(*expr, forScope, functions, diagnostics);
                    if (t != SimpleType::Unknown && et != SimpleType::Unknown && !isAssignable(t, et)) {
                        diagnostics.push_back({lineOf(*initVar), "cannot assign expression of type '" + toString(et) + "' to variable of type '" + toString(t) + "'"});
                    }
                }
            } else if (auto *initAssign = dynamic_cast<EZLanguageParser::ForInitAssignContext *>(init)) {
                const string name = initAssign->IDENTIFIER()->getText();
                auto it = forScope.find(name);
                if (it == forScope.end()) {
                    diagnostics.push_back({lineOf(*initAssign), "variable '" + name + "' not declared"});
                } else {
                    auto et = inferExpressionType(*initAssign->expression(), forScope, functions, diagnostics);
                    if (it->second.type != SimpleType::Unknown && et != SimpleType::Unknown && !isAssignable(it->second.type, et)) {
                        diagnostics.push_back({lineOf(*initAssign), "cannot assign expression of type '" + toString(et) + "' to variable of type '" + toString(it->second.type) + "'"});
                    }
                }
            } else if (auto *initExpr = dynamic_cast<EZLanguageParser::ForInitExprContext *>(init)) {
                inferExpressionType(*initExpr->expression(), forScope, functions, diagnostics);
            }
        }

        if (auto *cond = forCtx->expression()) {
            auto t = inferExpressionType(*cond, forScope, functions, diagnostics);
            if (t != SimpleType::Unknown && t != SimpleType::Bool) {
                diagnostics.push_back({lineOf(*cond), "loop condition must be boolean"});
            }
        }

        typeCheckStatementList(forCtx->statement(), forScope, forLocals, functions, fnReturnType, sawReturn, diagnostics);

        if (auto *update = forCtx->forUpdate()) {
            if (auto *updateAssign = dynamic_cast<EZLanguageParser::ForUpdateAssignContext *>(update)) {
                const string name = updateAssign->IDENTIFIER()->getText();
                auto it = forScope.find(name);
                if (it == forScope.end()) {
                    diagnostics.push_back({lineOf(*updateAssign), "variable '" + name + "' not declared"});
                } else {
                    auto et = inferExpressionType(*updateAssign->expression(), forScope, functions, diagnostics);
                    if (it->second.type != SimpleType::Unknown && et != SimpleType::Unknown && !isAssignable(it->second.type, et)) {
                        diagnostics.push_back({lineOf(*updateAssign), "cannot assign expression of type '" + toString(et) + "' to variable of type '" + toString(it->second.type) + "'"});
                    }
                }
            } else if (auto *updateExpr = dynamic_cast<EZLanguageParser::ForUpdateExprContext *>(update)) {
                inferExpressionType(*updateExpr->expression(), forScope, functions, diagnostics);
            }
        }
    }
}

void typeCheckStatementList(const vector<EZLanguageParser::StatementContext*> &statements,
                            unordered_map<string, VariableInfo> &scope,
                            unordered_map<string, VariableInfo> &locals,
                            const unordered_map<string, FunctionInfo> &functions,
                            SimpleType fnReturnType,
                            bool &sawReturn,
                            vector<Diagnostic> &diagnostics)
{
    for (auto *stmt : statements) {
        if (auto *vd = stmt->variableDeclaration()) {
            auto vt = parseType(vd->type(), diagnostics);
            const string name = vd->IDENTIFIER()->getText();
            if (locals.count(name)) {
                diagnostics.push_back({lineOf(*vd), "duplicate local variable '" + name + "'"});
            }
            locals[name] = VariableInfo{vt, lineOf(*vd)};
            scope[name] = VariableInfo{vt, lineOf(*vd)};
            if (vd->expression()) {
                auto et = inferExpressionType(*vd->expression(), scope, functions, diagnostics);
                if (vt != SimpleType::Unknown && et != SimpleType::Unknown && !isAssignable(vt, et)) {
                    diagnostics.push_back({lineOf(*vd), "cannot assign expression of type '" + toString(et) + "' to variable of type '" + toString(vt) + "'"});
                }
            }
            continue;
        }

        if (auto *assign = stmt->assignmentStatement()) {
            typeCheckAssignment(*assign, scope, functions, diagnostics);
            continue;
        }

        if (auto *ret = stmt->returnStatement()) {
            sawReturn = true;
            if (ret->expression()) {
                auto rt = inferExpressionType(*ret->expression(), scope, functions, diagnostics);
                if (fnReturnType == SimpleType::Void) {
                    diagnostics.push_back({lineOf(*ret), "void function should not return a value"});
                } else if (rt != SimpleType::Unknown && fnReturnType != SimpleType::Unknown && !isAssignable(fnReturnType, rt)) {
                    diagnostics.push_back({lineOf(*ret), "return type mismatch: expected '" + toString(fnReturnType) + "' got '" + toString(rt) + "'"});
                }
            } else if (fnReturnType != SimpleType::Void) {
                diagnostics.push_back({lineOf(*ret), "missing return value for function returning '" + toString(fnReturnType) + "'"});
            }
            continue;
        }

        if (auto *exprStmt = stmt->expressionStatement()) {
            if (exprStmt->expression()) {
                inferExpressionType(*exprStmt->expression(), scope, functions, diagnostics);
            }
            continue;
        }

        if (auto *friendCall = stmt->friendFunctionCall()) {
            if (auto *args = friendCall->argumentList()) {
                for (auto *ex : args->expression()) {
                    auto t = inferExpressionType(*ex, scope, functions, diagnostics);
                    if (t != SimpleType::Unknown && !isNumeric(t)) {
                        diagnostics.push_back({lineOf(*ex), "friend calls only support numeric arguments"});
                    }
                }
            }
            continue;
        }

        if (auto *ctrl = stmt->controlFlowStatement()) {
            if (auto *ifStmt = ctrl->ifStatement()) {
                typeCheckIf(*ifStmt, scope, locals, functions, fnReturnType, sawReturn, diagnostics);
            } else if (auto *loopStmt = ctrl->loopStatement()) {
                typeCheckLoop(*loopStmt, scope, locals, functions, fnReturnType, sawReturn, diagnostics);
            }
            continue;
        }

        if (stmt->breakStatement() || stmt->continueStatement() || stmt->foreachStatement()) {
            // Structure-level checks for break/continue/foreach are deferred.
            continue;
        }
    }
}

void typeCheckFunction(const FunctionInfo &fn,
                       EZLanguageParser::FunctionDeclarationContext &ctx,
                       const unordered_map<string, VariableInfo> &globals,
                       const unordered_map<string, FunctionInfo> &functions,
                       vector<Diagnostic> &diagnostics)
{
    unordered_map<string, VariableInfo> locals;
    for (const auto &p : fn.params) {
        locals.emplace(p.name, VariableInfo{p.type, p.line});
    }

    unordered_map<string, VariableInfo> scope = globals;
    scope.insert(locals.begin(), locals.end());

    bool sawReturn = false;
    typeCheckStatementList(ctx.statement(), scope, locals, functions, fn.returnType, sawReturn, diagnostics);

    if (fn.returnType != SimpleType::Void && !sawReturn) {
        diagnostics.push_back({lineOf(ctx), "function '" + ctx.IDENTIFIER()->getText() + "' is missing a return"});
    }
}

} // namespace

SemanticModel runSemanticChecks(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics)
{
    SemanticModel model;
    if (!program) return model;

    // First pass: collect globals and function signatures
    for (auto *stmt : program->statement()) {
        if (auto *vd = stmt->variableDeclaration()) {
            if (vd->accessModifier()) {
                diagnostics.push_back({lineOf(*vd), "access modifiers not allowed on top-level variable declarations"});
            }
            const string name = vd->IDENTIFIER()->getText();
            auto type = parseType(vd->type(), diagnostics);
            if (model.globals.count(name)) {
                diagnostics.push_back({lineOf(*vd), "duplicate global variable '" + name + "'"});
            }
            model.globals.emplace(name, VariableInfo{type, lineOf(*vd)});
            continue;
        }

        if (auto *fn = stmt->functionDeclaration()) {
            const string name = fn->IDENTIFIER()->getText();
            if (fn->accessModifier()) {
                const string mod = fn->accessModifier()->getText();
                if (mod == "protected") diagnostics.push_back({lineOf(*fn), "'protected' not supported yet"});
            }
            if (model.functions.count(name)) {
                diagnostics.push_back({lineOf(*fn), "duplicate function '" + name + "'"});
                continue;
            }
            FunctionInfo info;
            info.returnType = parseType(fn->type(), diagnostics);
            info.line = lineOf(*fn);
            if (auto *params = fn->parameterList()) {
                for (auto *p : params->parameter()) {
                    FunctionParam fp;
                    fp.name = p->IDENTIFIER()->getText();
                    fp.type = parseType(p->type(), diagnostics);
                    fp.line = lineOf(*p);
                    info.params.push_back(fp);
                }
            }
            model.functions.emplace(name, std::move(info));
            continue;
        }

        if (auto *ret = stmt->returnStatement()) {
            diagnostics.push_back({lineOf(*ret), "return statement only allowed inside functions"});
        }
    }

    // Add built-in functions
    FunctionInfo printfFunc;
    printfFunc.returnType = SimpleType::Void;
    printfFunc.line = 0;
    // printf accepts variable arguments (for now just one string/int param)
    model.functions.emplace("printf", std::move(printfFunc));

    // Second pass: type-check global initializers and function bodies
    for (auto *stmt : program->statement()) {
        if (auto *vd = stmt->variableDeclaration()) {
            if (vd->expression()) {
                auto t = inferExpressionType(*vd->expression(), model.globals, model.functions, diagnostics);
                auto declared = parseType(vd->type(), diagnostics);
                if (declared != SimpleType::Unknown && t != SimpleType::Unknown && !isAssignable(declared, t)) {
                    diagnostics.push_back({lineOf(*vd), "cannot assign expression of type '" + toString(t) + "' to variable of type '" + toString(declared) + "'"});
                }
            }
            continue;
        }

        if (auto *fn = stmt->functionDeclaration()) {
            const string name = fn->IDENTIFIER()->getText();
            auto it = model.functions.find(name);
            if (it != model.functions.end()) {
                typeCheckFunction(it->second, *fn, model.globals, model.functions, diagnostics);
            }
            continue;
        }
    }

    return model;
}
