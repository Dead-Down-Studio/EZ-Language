#pragma once
#include <filesystem>
#include <optional>
#include <string>
#include <vector>
#include "../diagnostics/diagnostics.h"

#include "../../generated/EZLanguageBaseListener.h"
#include "../../generated/EZLanguageParser.h"
#include "antlr4-runtime.h"

class BootstrapListener : public EZLanguageBaseListener {
public:
    explicit BootstrapListener(std::filesystem::path baseDir);

    void enterEnvDeclaration(EZLanguageParser::EnvDeclarationContext *ctx) override;
    void enterFriendStatement(EZLanguageParser::FriendStatementContext *ctx) override;
    void enterFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext *ctx) override;

    const std::optional<std::string> &getEnvironment() const { return environment; }
    std::optional<size_t> getEnvironmentLine() const { return environmentLine; }

    struct FriendModule {
        std::string sourceToken;
        std::string language;
        std::string alias;
        size_t line;
    };

    struct FriendCall { std::string alias; std::string func; size_t argc; size_t line; };

    const std::vector<FriendModule> &getFriendModules() const { return friendModules; }
    const std::vector<FriendCall> &getFriendCalls() const { return friendCalls; }
    const std::vector<Diagnostic> &getDiagnostics() const { return diagnostics; }
    const std::filesystem::path &getBaseDirectory() const { return baseDirectory; }

private:
    std::filesystem::path baseDirectory;
    std::optional<std::string> environment;
    std::optional<size_t> environmentLine;
    std::vector<FriendModule> friendModules;
    std::vector<FriendCall> friendCalls;
    std::vector<Diagnostic> diagnostics;
};
