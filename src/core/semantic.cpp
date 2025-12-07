#include "semantic.h"
#include "../../generated/EZLanguageParser.h"

#include <unordered_set>

using namespace std;

static void collectClassMethods(EZLanguageParser::ProgramContext *program,
                                unordered_set<string> &privateMethods,
                                unordered_set<string> &publicMethods,
                                vector<Diagnostic> &diagnostics)
{
    for (auto *child : program->children) {
        auto *cls = dynamic_cast<EZLanguageParser::ClassDeclarationContext *>(child);
        if (!cls) continue;
        // Iterate variable or function declarations inside class
        for (auto *member : cls->children) {
            if (auto *fn = dynamic_cast<EZLanguageParser::FunctionDeclarationContext *>(member)) {
                string name = fn->IDENTIFIER()->getText();
                auto *access = fn->accessModifier();
                if (access) {
                    string mod = access->getText();
                    if (mod == "private") privateMethods.insert(name);
                    else if (mod == "public") publicMethods.insert(name);
                    else if (mod == "protected") diagnostics.push_back({(size_t)fn->getStart()->getLine(), "'protected' not supported yet"});
                } else {
                    // Default public if no modifier given
                    publicMethods.insert(name);
                }
            }
        }
    }
}

void runSemanticChecks(EZLanguageParser::ProgramContext *program, std::vector<Diagnostic> &diagnostics)
{
    if (!program) return;

    unordered_set<string> privateMethods;
    unordered_set<string> publicMethods;
    collectClassMethods(program, privateMethods, publicMethods, diagnostics);

    // Examine top-level statements
    for (auto *stmt : program->statement()) {
        if (auto *varDecl = stmt->variableDeclaration()) {
            if (varDecl->accessModifier()) {
                diagnostics.push_back({(size_t)varDecl->getStart()->getLine(), "access modifiers not allowed on top-level variable declarations"});
            }
            continue;
        }

        // Direct friend function calls are fine
        if (stmt->friendFunctionCall()) continue;

        if (auto *exprStmt = stmt->expressionStatement()) {
            auto *expr = exprStmt->expression();
            if (!expr) continue;
            for (auto *prim : expr->primaryExpression()) {
                if (auto *call = prim->functionCall()) {
                    string name = call->IDENTIFIER()->getText();
                    if (privateMethods.count(name)) {
                        diagnostics.push_back({(size_t)call->getStart()->getLine(), "cannot call private method '" + name + "' outside class scope"});
                    }
                }
            }
        }
    }
}
