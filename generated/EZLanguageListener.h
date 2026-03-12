
// Generated from EZLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "EZLanguageParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by EZLanguageParser.
 */
class  EZLanguageListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(EZLanguageParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(EZLanguageParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(EZLanguageParser::StatementContext *ctx) = 0;
  virtual void exitStatement(EZLanguageParser::StatementContext *ctx) = 0;

  virtual void enterEnvDeclaration(EZLanguageParser::EnvDeclarationContext *ctx) = 0;
  virtual void exitEnvDeclaration(EZLanguageParser::EnvDeclarationContext *ctx) = 0;

  virtual void enterIncludeStatement(EZLanguageParser::IncludeStatementContext *ctx) = 0;
  virtual void exitIncludeStatement(EZLanguageParser::IncludeStatementContext *ctx) = 0;

  virtual void enterFriendStatement(EZLanguageParser::FriendStatementContext *ctx) = 0;
  virtual void exitFriendStatement(EZLanguageParser::FriendStatementContext *ctx) = 0;

  virtual void enterClassDeclaration(EZLanguageParser::ClassDeclarationContext *ctx) = 0;
  virtual void exitClassDeclaration(EZLanguageParser::ClassDeclarationContext *ctx) = 0;

  virtual void enterVariableDeclaration(EZLanguageParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(EZLanguageParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterAssignmentStatement(EZLanguageParser::AssignmentStatementContext *ctx) = 0;
  virtual void exitAssignmentStatement(EZLanguageParser::AssignmentStatementContext *ctx) = 0;

  virtual void enterBreakStatement(EZLanguageParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(EZLanguageParser::BreakStatementContext *ctx) = 0;

  virtual void enterContinueStatement(EZLanguageParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(EZLanguageParser::ContinueStatementContext *ctx) = 0;

  virtual void enterFunctionDeclaration(EZLanguageParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(EZLanguageParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterParameterList(EZLanguageParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(EZLanguageParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(EZLanguageParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(EZLanguageParser::ParameterContext *ctx) = 0;

  virtual void enterReturnStatement(EZLanguageParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(EZLanguageParser::ReturnStatementContext *ctx) = 0;

  virtual void enterFunctionCall(EZLanguageParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(EZLanguageParser::FunctionCallContext *ctx) = 0;

  virtual void enterFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext *ctx) = 0;
  virtual void exitFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext *ctx) = 0;

  virtual void enterArgumentList(EZLanguageParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(EZLanguageParser::ArgumentListContext *ctx) = 0;

  virtual void enterControlFlowStatement(EZLanguageParser::ControlFlowStatementContext *ctx) = 0;
  virtual void exitControlFlowStatement(EZLanguageParser::ControlFlowStatementContext *ctx) = 0;

  virtual void enterIfStatement(EZLanguageParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(EZLanguageParser::IfStatementContext *ctx) = 0;

  virtual void enterLoopStatement(EZLanguageParser::LoopStatementContext *ctx) = 0;
  virtual void exitLoopStatement(EZLanguageParser::LoopStatementContext *ctx) = 0;

  virtual void enterForeachStatement(EZLanguageParser::ForeachStatementContext *ctx) = 0;
  virtual void exitForeachStatement(EZLanguageParser::ForeachStatementContext *ctx) = 0;

  virtual void enterTryCatchStatement(EZLanguageParser::TryCatchStatementContext *ctx) = 0;
  virtual void exitTryCatchStatement(EZLanguageParser::TryCatchStatementContext *ctx) = 0;

  virtual void enterRunStatement(EZLanguageParser::RunStatementContext *ctx) = 0;
  virtual void exitRunStatement(EZLanguageParser::RunStatementContext *ctx) = 0;

  virtual void enterExpressionStatement(EZLanguageParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(EZLanguageParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterExpression(EZLanguageParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(EZLanguageParser::ExpressionContext *ctx) = 0;

  virtual void enterPrimaryExpression(EZLanguageParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(EZLanguageParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterLiteral(EZLanguageParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(EZLanguageParser::LiteralContext *ctx) = 0;

  virtual void enterAccessModifier(EZLanguageParser::AccessModifierContext *ctx) = 0;
  virtual void exitAccessModifier(EZLanguageParser::AccessModifierContext *ctx) = 0;

  virtual void enterType(EZLanguageParser::TypeContext *ctx) = 0;
  virtual void exitType(EZLanguageParser::TypeContext *ctx) = 0;

  virtual void enterBaseType(EZLanguageParser::BaseTypeContext *ctx) = 0;
  virtual void exitBaseType(EZLanguageParser::BaseTypeContext *ctx) = 0;

  virtual void enterMapType(EZLanguageParser::MapTypeContext *ctx) = 0;
  virtual void exitMapType(EZLanguageParser::MapTypeContext *ctx) = 0;


};

