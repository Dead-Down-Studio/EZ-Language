#include "codegen_c.h"
#include <optional>
#include <sstream>

namespace {

size_t lineOf(const antlr4::ParserRuleContext &ctx)
{
    return static_cast<size_t>(ctx.getStart()->getLine());
}

std::string toCType(SimpleType t)
{
    switch (t) {
        case SimpleType::Int: return "int";
        case SimpleType::Bool: return "bool";
        case SimpleType::String: return "const char*";
        case SimpleType::Void: return "void";
        case SimpleType::Unknown: default: return "/*unknown*/ int";
    }
}

} // namespace

class CCodegenImpl {
public:
    std::string generate(EZLanguageParser::ProgramContext *program,
                         const SemanticModel &model,
                         std::vector<Diagnostic> &diagnostics)
    {
        std::ostringstream out;
        out << "#include <stdio.h>\n";
        out << "#include <stdbool.h>\n";

        // Emit function definitions before main
        for (auto *stmt : program->statement()) {
            if (auto *fn = stmt->functionDeclaration()) {
                emitFunction(*fn, model, out, diagnostics);
            }
        }

        out << "int main(){\n";
        for (auto *stmt : program->statement()) {
            if (stmt->functionDeclaration()) continue; // already emitted

            if (auto *v = stmt->variableDeclaration()) {
                emitVarDecl(*v, out, diagnostics);
            } else if (auto *e = stmt->expressionStatement()) {
                emitExprStmt(*e, out, diagnostics);
            } else if (auto *f = stmt->friendFunctionCall()) {
                diagnostics.push_back({lineOf(*f), "friend calls are not supported in C codegen yet"});
            } else if (auto *r = stmt->returnStatement()) {
                diagnostics.push_back({lineOf(*r), "return not allowed at top level"});
            }
        }

        out << "return 0;\n";
        out << "}\n";
        return out.str();
    }

private:
    void emitFunction(EZLanguageParser::FunctionDeclarationContext &fn,
                      const SemanticModel &model,
                      std::ostream &out,
                      std::vector<Diagnostic> &diagnostics)
    {
        const std::string name = fn.IDENTIFIER()->getText();
        auto it = model.functions.find(name);
        if (it == model.functions.end()) {
            diagnostics.push_back({lineOf(fn), "missing signature information for function '" + name + "'"});
            return;
        }

        out << toCType(it->second.returnType) << ' ' << name << '(';
        for (size_t i = 0; i < it->second.params.size(); ++i) {
            if (i) out << ", ";
            out << toCType(it->second.params[i].type) << ' ' << it->second.params[i].name;
        }
        out << ") {\n";

        for (auto *stmt : fn.statement()) {
            if (auto *v = stmt->variableDeclaration()) {
                emitVarDecl(*v, out, diagnostics);
            } else if (auto *e = stmt->expressionStatement()) {
                emitExprStmt(*e, out, diagnostics);
            } else if (auto *f = stmt->friendFunctionCall()) {
                diagnostics.push_back({lineOf(*f), "friend calls are not supported in C codegen yet"});
            } else if (auto *r = stmt->returnStatement()) {
                emitReturn(*r, out, diagnostics);
            }
        }

        out << "}\n\n";
    }

    void emitVarDecl(EZLanguageParser::VariableDeclarationContext &ctx, std::ostream &out, std::vector<Diagnostic> &diagnostics)
    {
        auto *type = ctx.type();
        if (!type) { diagnostics.push_back({lineOf(ctx), "missing type in variable declaration"}); return; }
        const std::string t = type->getText();
        if (t != "int" && t != "boolean" && t != "string") { 
            diagnostics.push_back({lineOf(ctx), "only 'int', 'boolean', and 'string' supported in C codegen"}); 
            return; 
        }
        const std::string name = ctx.IDENTIFIER()->getText();
        std::string ctype = "int";
        if (t == "boolean") ctype = "bool";
        else if (t == "string") ctype = "const char*";
        out << ctype << ' ' << name;
        if (auto *expr = ctx.expression()) {
            auto ce = emitExpression(*expr, diagnostics);
            if (!ce.has_value()) return;
            out << " = " << ce.value();
        }
        out << ";\n";
    }

    void emitExprStmt(EZLanguageParser::ExpressionStatementContext &ctx, std::ostream &out, std::vector<Diagnostic> &diagnostics)
    {
        auto *expr = ctx.expression();
        if (!expr) { diagnostics.push_back({lineOf(ctx), "missing expression"}); return; }
        auto ce = emitExpression(*expr, diagnostics);
        if (!ce.has_value()) return;
        
        // If the expression is already a print/printf call, don't wrap it
        if (ce.value().find("printf(") == 0) {
            out << ce.value() << ";\n";
        } else {
            // For other expressions, print their result
            out << "printf(\"%lld\\n\", (long long)(" << ce.value() << "));\n";
        }
    }

    void emitReturn(EZLanguageParser::ReturnStatementContext &ctx, std::ostream &out, std::vector<Diagnostic> &diagnostics)
    {
        if (auto *expr = ctx.expression()) {
            auto ce = emitExpression(*expr, diagnostics);
            if (!ce.has_value()) return;
            out << "return " << ce.value() << ";\n";
        } else {
            out << "return;\n";
        }
    }

    std::optional<std::string> emitExpression(EZLanguageParser::ExpressionContext &expr, std::vector<Diagnostic> &diagnostics)
    {
        const auto &primaries = expr.primaryExpression();
        if (primaries.empty()) { diagnostics.push_back({lineOf(expr), "empty expression"}); return std::nullopt; }
        auto left = emitPrimary(*primaries.front(), diagnostics);
        if (!left.has_value()) return std::nullopt;
        std::string result = left.value();
        
        // Collect all operators from OPERATOR tokens, LT, and GT tokens
        std::vector<std::string> operators;
        for (auto *child : expr.children) {
            auto *terminal = dynamic_cast<antlr4::tree::TerminalNode *>(child);
            if (!terminal) continue;
            const auto type = terminal->getSymbol()->getType();
            if (type == EZLanguageParser::OPERATOR || type == EZLanguageParser::LT || type == EZLanguageParser::GT) {
                operators.push_back(terminal->getText());
            }
        }
        
        for (size_t i = 0; i < operators.size(); ++i) {
            std::string op = operators[i];
            if (op != "+" && op != "-" && op != "*" && op != "/" && 
                op != "&&" && op != "||" && op != "==" && op != "!=" && 
                op != ">" && op != "<" && op != ">=" && op != "<=") {
                diagnostics.push_back({lineOf(expr), "operator '" + op + "' not supported in C codegen"});
                return std::nullopt;
            }
            auto right = emitPrimary(*primaries[i+1], diagnostics);
            if (!right.has_value()) return std::nullopt;
            result = "(" + result + " " + op + " " + right.value() + ")";
        }
        return result;
    }

    std::optional<std::string> emitPrimary(EZLanguageParser::PrimaryExpressionContext &p, std::vector<Diagnostic> &diagnostics)
    {
        if (auto *id = p.IDENTIFIER()) {
            return id->getText();
        }
        if (auto *lit = p.literal()) {
            if (auto *num = lit->NUMBER()) return num->getText();
            if (auto *b = lit->BOOLEAN()) return b->getText();
            if (auto *str = lit->STRING()) {
                // Return the string literal as-is (already has quotes)
                return str->getText();
            }
            diagnostics.push_back({lineOf(p), "literal not supported"});
            return std::nullopt;
        }
        if (auto *call = p.functionCall()) {
            const std::string fname = call->IDENTIFIER()->getText();
            
            // Handle built-in print/printf functions
            if (fname == "print" || fname == "printf") {
                std::string rendered = "printf(\"";
                std::vector<std::string> args;
                if (auto *argList = call->argumentList()) {
                    for (auto *expr : argList->expression()) {
                        auto a = emitExpression(*expr, diagnostics);
                        if (!a.has_value()) return std::nullopt;
                        args.push_back(a.value());
                    }
                }
                // Generate format string based on number of arguments
                for (size_t i = 0; i < args.size(); ++i) {
                    if (i > 0) rendered += " ";
                    rendered += "%s";
                }
                rendered += "\\n\"";
                // Add arguments - wrap them for conversion
                for (const auto &arg : args) {
                    rendered += ", " + arg;
                }
                rendered += ")";
                return rendered;
            }
            
            // Regular function call
            std::string rendered = fname + "(";
            if (auto *args = call->argumentList()) {
                for (size_t i = 0; i < args->expression().size(); ++i) {
                    if (i) rendered += ", ";
                    auto a = emitExpression(*args->expression(i), diagnostics);
                    if (!a.has_value()) return std::nullopt;
                    rendered += a.value();
                }
            }
            rendered += ")";
            return rendered;
        }
        if (auto *friendCall = p.friendFunctionCall()) {
            diagnostics.push_back({lineOf(*friendCall), "friend calls are not supported in C codegen yet"});
            return std::nullopt;
        }
        if (auto *inner = p.expression()) {
            auto e = emitExpression(*inner, diagnostics);
            if (!e.has_value()) return std::nullopt;
            return "(" + e.value() + ")";
        }
        diagnostics.push_back({lineOf(p), "unsupported primary expression"});
        return std::nullopt;
    }
};

std::string CCodeGenerator::generate(EZLanguageParser::ProgramContext *program,
                                     const SemanticModel &model,
                                     std::vector<Diagnostic> &diagnostics)
{
    CCodegenImpl impl;
    return impl.generate(program, model, diagnostics);
}
