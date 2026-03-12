
// Generated from grammar/EZLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "EZLanguageParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by EZLanguageParser.
 */
class  EZLanguageVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by EZLanguageParser.
   */
    virtual std::any visitProgram(EZLanguageParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(EZLanguageParser::StatementContext *context) = 0;

    virtual std::any visitEnvDeclaration(EZLanguageParser::EnvDeclarationContext *context) = 0;

    virtual std::any visitIncludeStatement(EZLanguageParser::IncludeStatementContext *context) = 0;

    virtual std::any visitFriendStatement(EZLanguageParser::FriendStatementContext *context) = 0;

    virtual std::any visitClassDeclaration(EZLanguageParser::ClassDeclarationContext *context) = 0;

    virtual std::any visitVariableDeclaration(EZLanguageParser::VariableDeclarationContext *context) = 0;

    virtual std::any visitAssignmentStatement(EZLanguageParser::AssignmentStatementContext *context) = 0;

    virtual std::any visitBreakStatement(EZLanguageParser::BreakStatementContext *context) = 0;

    virtual std::any visitContinueStatement(EZLanguageParser::ContinueStatementContext *context) = 0;

    virtual std::any visitFunctionDeclaration(EZLanguageParser::FunctionDeclarationContext *context) = 0;

    virtual std::any visitParameterList(EZLanguageParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(EZLanguageParser::ParameterContext *context) = 0;

    virtual std::any visitReturnStatement(EZLanguageParser::ReturnStatementContext *context) = 0;

    virtual std::any visitFunctionCall(EZLanguageParser::FunctionCallContext *context) = 0;

    virtual std::any visitFriendFunctionCall(EZLanguageParser::FriendFunctionCallContext *context) = 0;

    virtual std::any visitArgumentList(EZLanguageParser::ArgumentListContext *context) = 0;

    virtual std::any visitControlFlowStatement(EZLanguageParser::ControlFlowStatementContext *context) = 0;

    virtual std::any visitIfStatement(EZLanguageParser::IfStatementContext *context) = 0;

    virtual std::any visitLoopStatement(EZLanguageParser::LoopStatementContext *context) = 0;

    virtual std::any visitWhileLoop(EZLanguageParser::WhileLoopContext *context) = 0;

    virtual std::any visitForLoop(EZLanguageParser::ForLoopContext *context) = 0;

    virtual std::any visitForInitVarDecl(EZLanguageParser::ForInitVarDeclContext *context) = 0;

    virtual std::any visitForInitAssign(EZLanguageParser::ForInitAssignContext *context) = 0;

    virtual std::any visitForInitExpr(EZLanguageParser::ForInitExprContext *context) = 0;

    virtual std::any visitForUpdateAssign(EZLanguageParser::ForUpdateAssignContext *context) = 0;

    virtual std::any visitForUpdateExpr(EZLanguageParser::ForUpdateExprContext *context) = 0;

    virtual std::any visitForeachStatement(EZLanguageParser::ForeachStatementContext *context) = 0;

    virtual std::any visitTryCatchStatement(EZLanguageParser::TryCatchStatementContext *context) = 0;

    virtual std::any visitRunStatement(EZLanguageParser::RunStatementContext *context) = 0;

    virtual std::any visitExpressionStatement(EZLanguageParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitExpression(EZLanguageParser::ExpressionContext *context) = 0;

    virtual std::any visitPrimaryExpression(EZLanguageParser::PrimaryExpressionContext *context) = 0;

    virtual std::any visitLiteral(EZLanguageParser::LiteralContext *context) = 0;

    virtual std::any visitAccessModifier(EZLanguageParser::AccessModifierContext *context) = 0;

    virtual std::any visitType(EZLanguageParser::TypeContext *context) = 0;

    virtual std::any visitBaseType(EZLanguageParser::BaseTypeContext *context) = 0;

    virtual std::any visitMapType(EZLanguageParser::MapTypeContext *context) = 0;


};

