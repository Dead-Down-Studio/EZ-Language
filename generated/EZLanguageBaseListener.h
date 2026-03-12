
// Generated from grammar/EZLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "EZLanguageListener.h"


/**
 * This class provides an empty implementation of EZLanguageListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  EZLanguageBaseListener : public EZLanguageListener {
public:

  virtual void enterProgram(EZLanguageParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(EZLanguageParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(EZLanguageParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(EZLanguageParser::StatementContext * /*ctx*/) override { }

  virtual void enterEnvDeclaration(EZLanguageParser::EnvDeclarationContext * /*ctx*/) override { }
  virtual void exitEnvDeclaration(EZLanguageParser::EnvDeclarationContext * /*ctx*/) override { }

  virtual void enterIncludeStatement(EZLanguageParser::IncludeStatementContext * /*ctx*/) override { }
  virtual void exitIncludeStatement(EZLanguageParser::IncludeStatementContext * /*ctx*/) override { }

  virtual void enterFriendStatement(EZLanguageParser::FriendStatementContext * /*ctx*/) override { }
  virtual void exitFriendStatement(EZLanguageParser::FriendStatementContext * /*ctx*/) override { }

  virtual void enterClassDeclaration(EZLanguageParser::ClassDeclarationContext * /*ctx*/) override { }
  virtual void exitClassDeclaration(EZLanguageParser::ClassDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(EZLanguageParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(EZLanguageParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterAssignmentStatement(EZLanguageParser::AssignmentStatementContext * /*ctx*/) override { }
  virtual void exitAssignmentStatement(EZLanguageParser::AssignmentStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(EZLanguageParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(EZLanguageParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(EZLanguageParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(EZLanguageParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(EZLanguageParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(EZLanguageParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterParameterList(EZLanguageParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(EZLanguageParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(EZLanguageParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(EZLanguageParser::ParameterContext * /*ctx*/) override { }

  virtual void enterReturnStatement(EZLanguageParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(EZLanguageParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterFunctionCall(EZLanguageParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(EZLanguageParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext * /*ctx*/) override { }
  virtual void exitFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext * /*ctx*/) override { }

  virtual void enterArgumentList(EZLanguageParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(EZLanguageParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterControlFlowStatement(EZLanguageParser::ControlFlowStatementContext * /*ctx*/) override { }
  virtual void exitControlFlowStatement(EZLanguageParser::ControlFlowStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(EZLanguageParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(EZLanguageParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterLoopStatement(EZLanguageParser::LoopStatementContext * /*ctx*/) override { }
  virtual void exitLoopStatement(EZLanguageParser::LoopStatementContext * /*ctx*/) override { }

  virtual void enterWhileLoop(EZLanguageParser::WhileLoopContext * /*ctx*/) override { }
  virtual void exitWhileLoop(EZLanguageParser::WhileLoopContext * /*ctx*/) override { }

  virtual void enterForLoop(EZLanguageParser::ForLoopContext * /*ctx*/) override { }
  virtual void exitForLoop(EZLanguageParser::ForLoopContext * /*ctx*/) override { }

  virtual void enterForInitVarDecl(EZLanguageParser::ForInitVarDeclContext * /*ctx*/) override { }
  virtual void exitForInitVarDecl(EZLanguageParser::ForInitVarDeclContext * /*ctx*/) override { }

  virtual void enterForInitAssign(EZLanguageParser::ForInitAssignContext * /*ctx*/) override { }
  virtual void exitForInitAssign(EZLanguageParser::ForInitAssignContext * /*ctx*/) override { }

  virtual void enterForInitExpr(EZLanguageParser::ForInitExprContext * /*ctx*/) override { }
  virtual void exitForInitExpr(EZLanguageParser::ForInitExprContext * /*ctx*/) override { }

  virtual void enterForUpdateAssign(EZLanguageParser::ForUpdateAssignContext * /*ctx*/) override { }
  virtual void exitForUpdateAssign(EZLanguageParser::ForUpdateAssignContext * /*ctx*/) override { }

  virtual void enterForUpdateExpr(EZLanguageParser::ForUpdateExprContext * /*ctx*/) override { }
  virtual void exitForUpdateExpr(EZLanguageParser::ForUpdateExprContext * /*ctx*/) override { }

  virtual void enterForeachStatement(EZLanguageParser::ForeachStatementContext * /*ctx*/) override { }
  virtual void exitForeachStatement(EZLanguageParser::ForeachStatementContext * /*ctx*/) override { }

  virtual void enterTryCatchStatement(EZLanguageParser::TryCatchStatementContext * /*ctx*/) override { }
  virtual void exitTryCatchStatement(EZLanguageParser::TryCatchStatementContext * /*ctx*/) override { }

  virtual void enterRunStatement(EZLanguageParser::RunStatementContext * /*ctx*/) override { }
  virtual void exitRunStatement(EZLanguageParser::RunStatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(EZLanguageParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(EZLanguageParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterExpression(EZLanguageParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(EZLanguageParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(EZLanguageParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(EZLanguageParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterLiteral(EZLanguageParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(EZLanguageParser::LiteralContext * /*ctx*/) override { }

  virtual void enterAccessModifier(EZLanguageParser::AccessModifierContext * /*ctx*/) override { }
  virtual void exitAccessModifier(EZLanguageParser::AccessModifierContext * /*ctx*/) override { }

  virtual void enterType(EZLanguageParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(EZLanguageParser::TypeContext * /*ctx*/) override { }

  virtual void enterBaseType(EZLanguageParser::BaseTypeContext * /*ctx*/) override { }
  virtual void exitBaseType(EZLanguageParser::BaseTypeContext * /*ctx*/) override { }

  virtual void enterMapType(EZLanguageParser::MapTypeContext * /*ctx*/) override { }
  virtual void exitMapType(EZLanguageParser::MapTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

