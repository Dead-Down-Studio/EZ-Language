#include "bootstrap_listener.h"

using namespace antlr4;

BootstrapListener::BootstrapListener(std::filesystem::path baseDir)
    : baseDirectory(std::move(baseDir)) {}

void BootstrapListener::enterEnvDeclaration(EZLanguageParser::EnvDeclarationContext *ctx)
{
    auto *identifier = ctx->IDENTIFIER();
    if (identifier == nullptr) {
        diagnostics.push_back({static_cast<size_t>(ctx->getStart()->getLine()), "environment declaration missing identifier"});
        return;
    }

    const std::string value = identifier->getText();
    const size_t line = static_cast<size_t>(ctx->getStart()->getLine());

    if (!environment.has_value()) {
        environment = value;
        environmentLine = line;
    } else {
        diagnostics.push_back({line, "environment already declared as '" + environment.value() + "'"});
    }
}

void BootstrapListener::enterFriendStatement(EZLanguageParser::FriendStatementContext *ctx)
{
    const auto &identifiers = ctx->IDENTIFIER();
    const size_t line = static_cast<size_t>(ctx->getStart()->getLine());

    if (identifiers.size() < 3) {
        diagnostics.push_back({line, "friend statement requires module, language, and alias"});
        return;
    }

    FriendModule module;
    module.sourceToken = identifiers[0]->getText();
    module.language = identifiers[1]->getText();
    module.alias = identifiers[2]->getText();
    module.line = line;

    friendModules.push_back(std::move(module));
}

void BootstrapListener::enterFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext *ctx)
{
    const size_t line = static_cast<size_t>(ctx->getStart()->getLine());
    if (ctx->IDENTIFIER().size() < 2) {
        diagnostics.push_back({line, "invalid friend call"});
        return;
    }
    std::string alias = ctx->IDENTIFIER(0)->getText();
    std::string func = ctx->IDENTIFIER(1)->getText();
    size_t argc = 0;
    if (auto *args = ctx->argumentList()) {
        argc = args->expression().size();
    }
    friendCalls.push_back({std::move(alias), std::move(func), argc, line});
}
