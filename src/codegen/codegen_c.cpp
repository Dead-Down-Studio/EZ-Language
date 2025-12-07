#include "codegen_c.h"
#include <optional>
#include <sstream>

class CCodegenImpl {
public:
    std::string generate(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics)
    {
        std::ostringstream out;
        out << "#include <stdio.h>\n";
        out << "int main(){\n";

        for (auto *stmt : program->statement()) {
            if (auto *v = stmt->variableDeclaration()) {
                emitVarDecl(*v, out, diagnostics);
            } else if (auto *e = stmt->expressionStatement()) {
                emitExprStmt(*e, out, diagnostics);
            } else if (stmt->friendFunctionCall()) {
                diagnostics.push_back({lineOf(*stmt), "friend calls are not supported in C codegen yet"});
            }
        }

        out << "return 0;\n";
        out << "}\n";
        return out.str();
    }

private:
    static size_t lineOf(const antlr4::ParserRuleContext &ctx)
    {
        return static_cast<size_t>(ctx.getStart()->getLine());
    }

    void emitVarDecl(EZLanguageParser::VariableDeclarationContext &ctx, std::ostream &out, std::vector<Diagnostic> &diagnostics)
    {
        auto *type = ctx.type();
        if (!type) { diagnostics.push_back({lineOf(ctx), "missing type in variable declaration"}); return; }
        const std::string t = type->getText();
        if (t != "int") { diagnostics.push_back({lineOf(ctx), "only 'int' supported in C codegen"}); return; }
        const std::string name = ctx.IDENTIFIER()->getText();
        out << "int " << name;
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
        out << "printf(\"%d\\n\", (int)(" << ce.value() << "));\n";
    }

    std::optional<std::string> emitExpression(EZLanguageParser::ExpressionContext &expr, std::vector<Diagnostic> &diagnostics)
    {
        const auto &primaries = expr.primaryExpression();
        if (primaries.empty()) { diagnostics.push_back({lineOf(expr), "empty expression"}); return std::nullopt; }
        auto left = emitPrimary(*primaries.front(), diagnostics);
        if (!left.has_value()) return std::nullopt;
        std::string result = left.value();
        const auto &ops = expr.OPERATOR();
        for (size_t i = 0; i < ops.size(); ++i) {
            std::string op = ops[i]->getText();
            if (op != "+" && op != "-" && op != "*" && op != "/") {
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
            diagnostics.push_back({lineOf(p), "only numeric literals supported"});
            return std::nullopt;
        }
        if (auto *call = p.functionCall()) {
            diagnostics.push_back({lineOf(p), "function calls not supported in C codegen"});
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

std::string CCodeGenerator::generate(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics)
{
    CCodegenImpl impl;
    return impl.generate(program, diagnostics);
}
