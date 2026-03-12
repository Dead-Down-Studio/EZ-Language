
// Generated from EZLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "EZLanguageVisitor.h"


/**
 * This class provides an empty implementation of EZLanguageVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  EZLanguageBaseVisitor : public EZLanguageVisitor {
public:

  virtual std::any visitProgram(EZLanguageParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(EZLanguageParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnvDeclaration(EZLanguageParser::EnvDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIncludeStatement(EZLanguageParser::IncludeStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFriendStatement(EZLanguageParser::FriendStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDeclaration(EZLanguageParser::ClassDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(EZLanguageParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentStatement(EZLanguageParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(EZLanguageParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(EZLanguageParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclaration(EZLanguageParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterList(EZLanguageParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(EZLanguageParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(EZLanguageParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(EZLanguageParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(EZLanguageParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitControlFlowStatement(EZLanguageParser::ControlFlowStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(EZLanguageParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStatement(EZLanguageParser::LoopStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForeachStatement(EZLanguageParser::ForeachStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryCatchStatement(EZLanguageParser::TryCatchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRunStatement(EZLanguageParser::RunStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(EZLanguageParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(EZLanguageParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpression(EZLanguageParser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(EZLanguageParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccessModifier(EZLanguageParser::AccessModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(EZLanguageParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBaseType(EZLanguageParser::BaseTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapType(EZLanguageParser::MapTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

