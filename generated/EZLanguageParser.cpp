
// Generated from grammar/EZLanguage.g4 by ANTLR 4.13.2


#include "EZLanguageListener.h"
#include "EZLanguageVisitor.h"

#include "EZLanguageParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct EZLanguageParserStaticData final {
  EZLanguageParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  EZLanguageParserStaticData(const EZLanguageParserStaticData&) = delete;
  EZLanguageParserStaticData(EZLanguageParserStaticData&&) = delete;
  EZLanguageParserStaticData& operator=(const EZLanguageParserStaticData&) = delete;
  EZLanguageParserStaticData& operator=(EZLanguageParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ezlanguageParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<EZLanguageParserStaticData> ezlanguageParserStaticData = nullptr;

void ezlanguageParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ezlanguageParserStaticData != nullptr) {
    return;
  }
#else
  assert(ezlanguageParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<EZLanguageParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "envDeclaration", "includeStatement", "friendStatement", 
      "classDeclaration", "variableDeclaration", "assignmentStatement", 
      "breakStatement", "continueStatement", "functionDeclaration", "parameterList", 
      "parameter", "returnStatement", "functionCall", "friendFunctionCall", 
      "argumentList", "controlFlowStatement", "ifStatement", "loopStatement", 
      "whileLoop", "forLoop", "forInit", "forUpdate", "foreachStatement", 
      "tryCatchStatement", "runStatement", "expressionStatement", "expression", 
      "primaryExpression", "literal", "accessModifier", "type", "baseType", 
      "mapType"
    },
    std::vector<std::string>{
      "", "'env'", "';'", "'import'", "'friend'", "':'", "'as'", "'class'", 
      "'('", "')'", "'extends'", "'implements'", "'{'", "'}'", "'='", "'break'", 
      "'continue'", "'return'", "'.'", "'if'", "'else if'", "'else'", "'while'", 
      "'for'", "'in'", "'try'", "'catch'", "'finally'", "'run'", "'public'", 
      "'private'", "'protected'", "'[]'", "'int'", "'float'", "'boolean'", 
      "'string'", "'void'", "'map'", "", "'<'", "'>'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "OPERATOR", "LT", "GT", "COMMA", "BOOLEAN", "IDENTIFIER", 
      "STRING", "NUMBER", "LINE_COMMENT", "BLOCK_COMMENT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,49,429,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,1,
  	0,1,0,1,0,5,0,75,8,0,10,0,12,0,78,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,95,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,
  	3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,3,5,114,8,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,3,5,122,8,5,1,5,1,5,1,5,1,5,5,5,128,8,5,10,5,12,5,131,9,5,3,5,133,
  	8,5,1,5,1,5,1,5,5,5,138,8,5,10,5,12,5,141,9,5,1,5,1,5,1,6,3,6,146,8,6,
  	1,6,1,6,1,6,1,6,3,6,152,8,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,
  	9,1,9,1,9,1,10,3,10,168,8,10,1,10,1,10,1,10,1,10,3,10,174,8,10,1,10,1,
  	10,1,10,5,10,179,8,10,10,10,12,10,182,9,10,1,10,1,10,1,11,1,11,1,11,5,
  	11,189,8,11,10,11,12,11,192,9,11,1,12,1,12,1,12,1,13,1,13,3,13,199,8,
  	13,1,13,1,13,1,14,1,14,1,14,3,14,206,8,14,1,14,1,14,1,15,1,15,1,15,1,
  	15,1,15,3,15,215,8,15,1,15,1,15,1,16,1,16,1,16,5,16,222,8,16,10,16,12,
  	16,225,9,16,1,17,1,17,3,17,229,8,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,
  	237,8,18,10,18,12,18,240,9,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,
  	249,8,18,10,18,12,18,252,9,18,1,18,1,18,5,18,256,8,18,10,18,12,18,259,
  	9,18,1,18,1,18,1,18,5,18,264,8,18,10,18,12,18,267,9,18,1,18,3,18,270,
  	8,18,1,19,1,19,3,19,274,8,19,1,20,1,20,1,20,3,20,279,8,20,1,20,1,20,1,
  	20,5,20,284,8,20,10,20,12,20,287,9,20,1,20,1,20,1,21,1,21,1,21,3,21,294,
  	8,21,1,21,1,21,3,21,298,8,21,1,21,1,21,3,21,302,8,21,1,21,1,21,1,21,5,
  	21,307,8,21,10,21,12,21,310,9,21,1,21,1,21,1,22,1,22,1,22,1,22,3,22,318,
  	8,22,1,22,1,22,1,22,1,22,3,22,324,8,22,1,23,1,23,1,23,1,23,3,23,330,8,
  	23,1,24,1,24,1,24,1,24,1,24,1,24,5,24,338,8,24,10,24,12,24,341,9,24,1,
  	24,1,24,1,25,1,25,1,25,5,25,348,8,25,10,25,12,25,351,9,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,5,25,360,8,25,10,25,12,25,363,9,25,1,25,3,25,366,
  	8,25,1,25,1,25,1,25,5,25,371,8,25,10,25,12,25,374,9,25,1,25,3,25,377,
  	8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,5,28,
  	391,8,28,10,28,12,28,394,9,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	3,29,404,8,29,1,30,1,30,1,31,1,31,1,32,1,32,3,32,412,8,32,1,33,1,33,1,
  	33,1,33,1,33,1,33,3,33,420,8,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,0,0,35,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
  	44,46,48,50,52,54,56,58,60,62,64,66,68,0,3,1,0,39,41,2,0,43,43,45,46,
  	1,0,29,31,459,0,76,1,0,0,0,2,94,1,0,0,0,4,96,1,0,0,0,6,100,1,0,0,0,8,
  	104,1,0,0,0,10,113,1,0,0,0,12,145,1,0,0,0,14,155,1,0,0,0,16,160,1,0,0,
  	0,18,163,1,0,0,0,20,167,1,0,0,0,22,185,1,0,0,0,24,193,1,0,0,0,26,196,
  	1,0,0,0,28,202,1,0,0,0,30,209,1,0,0,0,32,218,1,0,0,0,34,228,1,0,0,0,36,
  	230,1,0,0,0,38,273,1,0,0,0,40,275,1,0,0,0,42,290,1,0,0,0,44,323,1,0,0,
  	0,46,329,1,0,0,0,48,331,1,0,0,0,50,344,1,0,0,0,52,378,1,0,0,0,54,384,
  	1,0,0,0,56,387,1,0,0,0,58,403,1,0,0,0,60,405,1,0,0,0,62,407,1,0,0,0,64,
  	409,1,0,0,0,66,419,1,0,0,0,68,421,1,0,0,0,70,75,3,2,1,0,71,75,3,10,5,
  	0,72,75,3,50,25,0,73,75,3,52,26,0,74,70,1,0,0,0,74,71,1,0,0,0,74,72,1,
  	0,0,0,74,73,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,79,1,
  	0,0,0,78,76,1,0,0,0,79,80,5,0,0,1,80,1,1,0,0,0,81,95,3,4,2,0,82,95,3,
  	6,3,0,83,95,3,8,4,0,84,95,3,30,15,0,85,95,3,54,27,0,86,95,3,12,6,0,87,
  	95,3,14,7,0,88,95,3,34,17,0,89,95,3,48,24,0,90,95,3,20,10,0,91,95,3,26,
  	13,0,92,95,3,16,8,0,93,95,3,18,9,0,94,81,1,0,0,0,94,82,1,0,0,0,94,83,
  	1,0,0,0,94,84,1,0,0,0,94,85,1,0,0,0,94,86,1,0,0,0,94,87,1,0,0,0,94,88,
  	1,0,0,0,94,89,1,0,0,0,94,90,1,0,0,0,94,91,1,0,0,0,94,92,1,0,0,0,94,93,
  	1,0,0,0,95,3,1,0,0,0,96,97,5,1,0,0,97,98,5,44,0,0,98,99,5,2,0,0,99,5,
  	1,0,0,0,100,101,5,3,0,0,101,102,5,44,0,0,102,103,5,2,0,0,103,7,1,0,0,
  	0,104,105,5,4,0,0,105,106,5,44,0,0,106,107,5,5,0,0,107,108,5,44,0,0,108,
  	109,5,6,0,0,109,110,5,44,0,0,110,111,5,2,0,0,111,9,1,0,0,0,112,114,3,
  	62,31,0,113,112,1,0,0,0,113,114,1,0,0,0,114,115,1,0,0,0,115,116,5,7,0,
  	0,116,117,5,44,0,0,117,118,5,8,0,0,118,121,5,9,0,0,119,120,5,10,0,0,120,
  	122,5,44,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,132,1,0,0,0,123,124,
  	5,11,0,0,124,129,5,44,0,0,125,126,5,42,0,0,126,128,5,44,0,0,127,125,1,
  	0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,133,1,0,0,0,
  	131,129,1,0,0,0,132,123,1,0,0,0,132,133,1,0,0,0,133,134,1,0,0,0,134,139,
  	5,12,0,0,135,138,3,12,6,0,136,138,3,20,10,0,137,135,1,0,0,0,137,136,1,
  	0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,142,1,0,0,0,
  	141,139,1,0,0,0,142,143,5,13,0,0,143,11,1,0,0,0,144,146,3,62,31,0,145,
  	144,1,0,0,0,145,146,1,0,0,0,146,147,1,0,0,0,147,148,3,64,32,0,148,151,
  	5,44,0,0,149,150,5,14,0,0,150,152,3,56,28,0,151,149,1,0,0,0,151,152,1,
  	0,0,0,152,153,1,0,0,0,153,154,5,2,0,0,154,13,1,0,0,0,155,156,5,44,0,0,
  	156,157,5,14,0,0,157,158,3,56,28,0,158,159,5,2,0,0,159,15,1,0,0,0,160,
  	161,5,15,0,0,161,162,5,2,0,0,162,17,1,0,0,0,163,164,5,16,0,0,164,165,
  	5,2,0,0,165,19,1,0,0,0,166,168,3,62,31,0,167,166,1,0,0,0,167,168,1,0,
  	0,0,168,169,1,0,0,0,169,170,3,64,32,0,170,171,5,44,0,0,171,173,5,8,0,
  	0,172,174,3,22,11,0,173,172,1,0,0,0,173,174,1,0,0,0,174,175,1,0,0,0,175,
  	176,5,9,0,0,176,180,5,12,0,0,177,179,3,2,1,0,178,177,1,0,0,0,179,182,
  	1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,0,181,183,1,0,0,0,182,180,1,0,0,
  	0,183,184,5,13,0,0,184,21,1,0,0,0,185,190,3,24,12,0,186,187,5,42,0,0,
  	187,189,3,24,12,0,188,186,1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,
  	191,1,0,0,0,191,23,1,0,0,0,192,190,1,0,0,0,193,194,3,64,32,0,194,195,
  	5,44,0,0,195,25,1,0,0,0,196,198,5,17,0,0,197,199,3,56,28,0,198,197,1,
  	0,0,0,198,199,1,0,0,0,199,200,1,0,0,0,200,201,5,2,0,0,201,27,1,0,0,0,
  	202,203,5,44,0,0,203,205,5,8,0,0,204,206,3,32,16,0,205,204,1,0,0,0,205,
  	206,1,0,0,0,206,207,1,0,0,0,207,208,5,9,0,0,208,29,1,0,0,0,209,210,5,
  	44,0,0,210,211,5,18,0,0,211,212,5,44,0,0,212,214,5,8,0,0,213,215,3,32,
  	16,0,214,213,1,0,0,0,214,215,1,0,0,0,215,216,1,0,0,0,216,217,5,9,0,0,
  	217,31,1,0,0,0,218,223,3,56,28,0,219,220,5,42,0,0,220,222,3,56,28,0,221,
  	219,1,0,0,0,222,225,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,224,33,1,
  	0,0,0,225,223,1,0,0,0,226,229,3,36,18,0,227,229,3,38,19,0,228,226,1,0,
  	0,0,228,227,1,0,0,0,229,35,1,0,0,0,230,231,5,19,0,0,231,232,5,8,0,0,232,
  	233,3,56,28,0,233,234,5,9,0,0,234,238,5,12,0,0,235,237,3,2,1,0,236,235,
  	1,0,0,0,237,240,1,0,0,0,238,236,1,0,0,0,238,239,1,0,0,0,239,241,1,0,0,
  	0,240,238,1,0,0,0,241,257,5,13,0,0,242,243,5,20,0,0,243,244,5,8,0,0,244,
  	245,3,56,28,0,245,246,5,9,0,0,246,250,5,12,0,0,247,249,3,2,1,0,248,247,
  	1,0,0,0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,253,1,0,0,
  	0,252,250,1,0,0,0,253,254,5,13,0,0,254,256,1,0,0,0,255,242,1,0,0,0,256,
  	259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,269,1,0,0,0,259,257,1,
  	0,0,0,260,261,5,21,0,0,261,265,5,12,0,0,262,264,3,2,1,0,263,262,1,0,0,
  	0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,268,1,0,0,0,267,
  	265,1,0,0,0,268,270,5,13,0,0,269,260,1,0,0,0,269,270,1,0,0,0,270,37,1,
  	0,0,0,271,274,3,40,20,0,272,274,3,42,21,0,273,271,1,0,0,0,273,272,1,0,
  	0,0,274,39,1,0,0,0,275,276,5,22,0,0,276,278,5,8,0,0,277,279,3,56,28,0,
  	278,277,1,0,0,0,278,279,1,0,0,0,279,280,1,0,0,0,280,281,5,9,0,0,281,285,
  	5,12,0,0,282,284,3,2,1,0,283,282,1,0,0,0,284,287,1,0,0,0,285,283,1,0,
  	0,0,285,286,1,0,0,0,286,288,1,0,0,0,287,285,1,0,0,0,288,289,5,13,0,0,
  	289,41,1,0,0,0,290,291,5,23,0,0,291,293,5,8,0,0,292,294,3,44,22,0,293,
  	292,1,0,0,0,293,294,1,0,0,0,294,295,1,0,0,0,295,297,5,2,0,0,296,298,3,
  	56,28,0,297,296,1,0,0,0,297,298,1,0,0,0,298,299,1,0,0,0,299,301,5,2,0,
  	0,300,302,3,46,23,0,301,300,1,0,0,0,301,302,1,0,0,0,302,303,1,0,0,0,303,
  	304,5,9,0,0,304,308,5,12,0,0,305,307,3,2,1,0,306,305,1,0,0,0,307,310,
  	1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,311,1,0,0,0,310,308,1,0,0,
  	0,311,312,5,13,0,0,312,43,1,0,0,0,313,314,3,64,32,0,314,317,5,44,0,0,
  	315,316,5,14,0,0,316,318,3,56,28,0,317,315,1,0,0,0,317,318,1,0,0,0,318,
  	324,1,0,0,0,319,320,5,44,0,0,320,321,5,14,0,0,321,324,3,56,28,0,322,324,
  	3,56,28,0,323,313,1,0,0,0,323,319,1,0,0,0,323,322,1,0,0,0,324,45,1,0,
  	0,0,325,326,5,44,0,0,326,327,5,14,0,0,327,330,3,56,28,0,328,330,3,56,
  	28,0,329,325,1,0,0,0,329,328,1,0,0,0,330,47,1,0,0,0,331,332,5,23,0,0,
  	332,333,5,44,0,0,333,334,5,24,0,0,334,335,5,44,0,0,335,339,5,12,0,0,336,
  	338,3,2,1,0,337,336,1,0,0,0,338,341,1,0,0,0,339,337,1,0,0,0,339,340,1,
  	0,0,0,340,342,1,0,0,0,341,339,1,0,0,0,342,343,5,13,0,0,343,49,1,0,0,0,
  	344,345,5,25,0,0,345,349,5,12,0,0,346,348,3,2,1,0,347,346,1,0,0,0,348,
  	351,1,0,0,0,349,347,1,0,0,0,349,350,1,0,0,0,350,352,1,0,0,0,351,349,1,
  	0,0,0,352,365,5,13,0,0,353,354,5,26,0,0,354,355,5,8,0,0,355,356,5,44,
  	0,0,356,357,5,9,0,0,357,361,5,12,0,0,358,360,3,2,1,0,359,358,1,0,0,0,
  	360,363,1,0,0,0,361,359,1,0,0,0,361,362,1,0,0,0,362,364,1,0,0,0,363,361,
  	1,0,0,0,364,366,5,13,0,0,365,353,1,0,0,0,365,366,1,0,0,0,366,376,1,0,
  	0,0,367,368,5,27,0,0,368,372,5,12,0,0,369,371,3,2,1,0,370,369,1,0,0,0,
  	371,374,1,0,0,0,372,370,1,0,0,0,372,373,1,0,0,0,373,375,1,0,0,0,374,372,
  	1,0,0,0,375,377,5,13,0,0,376,367,1,0,0,0,376,377,1,0,0,0,377,51,1,0,0,
  	0,378,379,5,28,0,0,379,380,5,44,0,0,380,381,5,5,0,0,381,382,5,45,0,0,
  	382,383,5,2,0,0,383,53,1,0,0,0,384,385,3,56,28,0,385,386,5,2,0,0,386,
  	55,1,0,0,0,387,392,3,58,29,0,388,389,7,0,0,0,389,391,3,58,29,0,390,388,
  	1,0,0,0,391,394,1,0,0,0,392,390,1,0,0,0,392,393,1,0,0,0,393,57,1,0,0,
  	0,394,392,1,0,0,0,395,404,5,44,0,0,396,404,3,60,30,0,397,404,3,28,14,
  	0,398,404,3,30,15,0,399,400,5,8,0,0,400,401,3,56,28,0,401,402,5,9,0,0,
  	402,404,1,0,0,0,403,395,1,0,0,0,403,396,1,0,0,0,403,397,1,0,0,0,403,398,
  	1,0,0,0,403,399,1,0,0,0,404,59,1,0,0,0,405,406,7,1,0,0,406,61,1,0,0,0,
  	407,408,7,2,0,0,408,63,1,0,0,0,409,411,3,66,33,0,410,412,5,32,0,0,411,
  	410,1,0,0,0,411,412,1,0,0,0,412,65,1,0,0,0,413,420,5,33,0,0,414,420,5,
  	34,0,0,415,420,5,35,0,0,416,420,5,36,0,0,417,420,5,37,0,0,418,420,3,68,
  	34,0,419,413,1,0,0,0,419,414,1,0,0,0,419,415,1,0,0,0,419,416,1,0,0,0,
  	419,417,1,0,0,0,419,418,1,0,0,0,420,67,1,0,0,0,421,422,5,38,0,0,422,423,
  	5,40,0,0,423,424,3,66,33,0,424,425,5,42,0,0,425,426,3,66,33,0,426,427,
  	5,41,0,0,427,69,1,0,0,0,45,74,76,94,113,121,129,132,137,139,145,151,167,
  	173,180,190,198,205,214,223,228,238,250,257,265,269,273,278,285,293,297,
  	301,308,317,323,329,339,349,361,365,372,376,392,403,411,419
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ezlanguageParserStaticData = std::move(staticData);
}

}

EZLanguageParser::EZLanguageParser(TokenStream *input) : EZLanguageParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

EZLanguageParser::EZLanguageParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  EZLanguageParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ezlanguageParserStaticData->atn, ezlanguageParserStaticData->decisionToDFA, ezlanguageParserStaticData->sharedContextCache, options);
}

EZLanguageParser::~EZLanguageParser() {
  delete _interpreter;
}

const atn::ATN& EZLanguageParser::getATN() const {
  return *ezlanguageParserStaticData->atn;
}

std::string EZLanguageParser::getGrammarFileName() const {
  return "EZLanguage.g4";
}

const std::vector<std::string>& EZLanguageParser::getRuleNames() const {
  return ezlanguageParserStaticData->ruleNames;
}

const dfa::Vocabulary& EZLanguageParser::getVocabulary() const {
  return ezlanguageParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView EZLanguageParser::getSerializedATN() const {
  return ezlanguageParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

EZLanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::ProgramContext::EOF() {
  return getToken(EZLanguageParser::EOF, 0);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::ProgramContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::ProgramContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}

std::vector<EZLanguageParser::ClassDeclarationContext *> EZLanguageParser::ProgramContext::classDeclaration() {
  return getRuleContexts<EZLanguageParser::ClassDeclarationContext>();
}

EZLanguageParser::ClassDeclarationContext* EZLanguageParser::ProgramContext::classDeclaration(size_t i) {
  return getRuleContext<EZLanguageParser::ClassDeclarationContext>(i);
}

std::vector<EZLanguageParser::TryCatchStatementContext *> EZLanguageParser::ProgramContext::tryCatchStatement() {
  return getRuleContexts<EZLanguageParser::TryCatchStatementContext>();
}

EZLanguageParser::TryCatchStatementContext* EZLanguageParser::ProgramContext::tryCatchStatement(size_t i) {
  return getRuleContext<EZLanguageParser::TryCatchStatementContext>(i);
}

std::vector<EZLanguageParser::RunStatementContext *> EZLanguageParser::ProgramContext::runStatement() {
  return getRuleContexts<EZLanguageParser::RunStatementContext>();
}

EZLanguageParser::RunStatementContext* EZLanguageParser::ProgramContext::runStatement(size_t i) {
  return getRuleContext<EZLanguageParser::RunStatementContext>(i);
}


size_t EZLanguageParser::ProgramContext::getRuleIndex() const {
  return EZLanguageParser::RuleProgram;
}

void EZLanguageParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void EZLanguageParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any EZLanguageParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ProgramContext* EZLanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, EZLanguageParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486634635674) != 0)) {
      setState(74);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(70);
        statement();
        break;
      }

      case 2: {
        setState(71);
        classDeclaration();
        break;
      }

      case 3: {
        setState(72);
        tryCatchStatement();
        break;
      }

      case 4: {
        setState(73);
        runStatement();
        break;
      }

      default:
        break;
      }
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(EZLanguageParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

EZLanguageParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::EnvDeclarationContext* EZLanguageParser::StatementContext::envDeclaration() {
  return getRuleContext<EZLanguageParser::EnvDeclarationContext>(0);
}

EZLanguageParser::IncludeStatementContext* EZLanguageParser::StatementContext::includeStatement() {
  return getRuleContext<EZLanguageParser::IncludeStatementContext>(0);
}

EZLanguageParser::FriendStatementContext* EZLanguageParser::StatementContext::friendStatement() {
  return getRuleContext<EZLanguageParser::FriendStatementContext>(0);
}

EZLanguageParser::FriendFunctionCallContext* EZLanguageParser::StatementContext::friendFunctionCall() {
  return getRuleContext<EZLanguageParser::FriendFunctionCallContext>(0);
}

EZLanguageParser::ExpressionStatementContext* EZLanguageParser::StatementContext::expressionStatement() {
  return getRuleContext<EZLanguageParser::ExpressionStatementContext>(0);
}

EZLanguageParser::VariableDeclarationContext* EZLanguageParser::StatementContext::variableDeclaration() {
  return getRuleContext<EZLanguageParser::VariableDeclarationContext>(0);
}

EZLanguageParser::AssignmentStatementContext* EZLanguageParser::StatementContext::assignmentStatement() {
  return getRuleContext<EZLanguageParser::AssignmentStatementContext>(0);
}

EZLanguageParser::ControlFlowStatementContext* EZLanguageParser::StatementContext::controlFlowStatement() {
  return getRuleContext<EZLanguageParser::ControlFlowStatementContext>(0);
}

EZLanguageParser::ForeachStatementContext* EZLanguageParser::StatementContext::foreachStatement() {
  return getRuleContext<EZLanguageParser::ForeachStatementContext>(0);
}

EZLanguageParser::FunctionDeclarationContext* EZLanguageParser::StatementContext::functionDeclaration() {
  return getRuleContext<EZLanguageParser::FunctionDeclarationContext>(0);
}

EZLanguageParser::ReturnStatementContext* EZLanguageParser::StatementContext::returnStatement() {
  return getRuleContext<EZLanguageParser::ReturnStatementContext>(0);
}

EZLanguageParser::BreakStatementContext* EZLanguageParser::StatementContext::breakStatement() {
  return getRuleContext<EZLanguageParser::BreakStatementContext>(0);
}

EZLanguageParser::ContinueStatementContext* EZLanguageParser::StatementContext::continueStatement() {
  return getRuleContext<EZLanguageParser::ContinueStatementContext>(0);
}


size_t EZLanguageParser::StatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleStatement;
}

void EZLanguageParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void EZLanguageParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any EZLanguageParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::StatementContext* EZLanguageParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, EZLanguageParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      envDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
      includeStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(83);
      friendStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(84);
      friendFunctionCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(85);
      expressionStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(86);
      variableDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(87);
      assignmentStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(88);
      controlFlowStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(89);
      foreachStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(90);
      functionDeclaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(91);
      returnStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(92);
      breakStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(93);
      continueStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnvDeclarationContext ------------------------------------------------------------------

EZLanguageParser::EnvDeclarationContext::EnvDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::EnvDeclarationContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}


size_t EZLanguageParser::EnvDeclarationContext::getRuleIndex() const {
  return EZLanguageParser::RuleEnvDeclaration;
}

void EZLanguageParser::EnvDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnvDeclaration(this);
}

void EZLanguageParser::EnvDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnvDeclaration(this);
}


std::any EZLanguageParser::EnvDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitEnvDeclaration(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::EnvDeclarationContext* EZLanguageParser::envDeclaration() {
  EnvDeclarationContext *_localctx = _tracker.createInstance<EnvDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, EZLanguageParser::RuleEnvDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(EZLanguageParser::T__0);
    setState(97);
    match(EZLanguageParser::IDENTIFIER);
    setState(98);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeStatementContext ------------------------------------------------------------------

EZLanguageParser::IncludeStatementContext::IncludeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::IncludeStatementContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}


size_t EZLanguageParser::IncludeStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleIncludeStatement;
}

void EZLanguageParser::IncludeStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncludeStatement(this);
}

void EZLanguageParser::IncludeStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncludeStatement(this);
}


std::any EZLanguageParser::IncludeStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitIncludeStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::IncludeStatementContext* EZLanguageParser::includeStatement() {
  IncludeStatementContext *_localctx = _tracker.createInstance<IncludeStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, EZLanguageParser::RuleIncludeStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(EZLanguageParser::T__2);
    setState(101);
    match(EZLanguageParser::IDENTIFIER);
    setState(102);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FriendStatementContext ------------------------------------------------------------------

EZLanguageParser::FriendStatementContext::FriendStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EZLanguageParser::FriendStatementContext::IDENTIFIER() {
  return getTokens(EZLanguageParser::IDENTIFIER);
}

tree::TerminalNode* EZLanguageParser::FriendStatementContext::IDENTIFIER(size_t i) {
  return getToken(EZLanguageParser::IDENTIFIER, i);
}


size_t EZLanguageParser::FriendStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleFriendStatement;
}

void EZLanguageParser::FriendStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFriendStatement(this);
}

void EZLanguageParser::FriendStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFriendStatement(this);
}


std::any EZLanguageParser::FriendStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitFriendStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::FriendStatementContext* EZLanguageParser::friendStatement() {
  FriendStatementContext *_localctx = _tracker.createInstance<FriendStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, EZLanguageParser::RuleFriendStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(EZLanguageParser::T__3);
    setState(105);
    match(EZLanguageParser::IDENTIFIER);
    setState(106);
    match(EZLanguageParser::T__4);
    setState(107);
    match(EZLanguageParser::IDENTIFIER);
    setState(108);
    match(EZLanguageParser::T__5);
    setState(109);
    match(EZLanguageParser::IDENTIFIER);
    setState(110);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

EZLanguageParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EZLanguageParser::ClassDeclarationContext::IDENTIFIER() {
  return getTokens(EZLanguageParser::IDENTIFIER);
}

tree::TerminalNode* EZLanguageParser::ClassDeclarationContext::IDENTIFIER(size_t i) {
  return getToken(EZLanguageParser::IDENTIFIER, i);
}

EZLanguageParser::AccessModifierContext* EZLanguageParser::ClassDeclarationContext::accessModifier() {
  return getRuleContext<EZLanguageParser::AccessModifierContext>(0);
}

std::vector<EZLanguageParser::VariableDeclarationContext *> EZLanguageParser::ClassDeclarationContext::variableDeclaration() {
  return getRuleContexts<EZLanguageParser::VariableDeclarationContext>();
}

EZLanguageParser::VariableDeclarationContext* EZLanguageParser::ClassDeclarationContext::variableDeclaration(size_t i) {
  return getRuleContext<EZLanguageParser::VariableDeclarationContext>(i);
}

std::vector<EZLanguageParser::FunctionDeclarationContext *> EZLanguageParser::ClassDeclarationContext::functionDeclaration() {
  return getRuleContexts<EZLanguageParser::FunctionDeclarationContext>();
}

EZLanguageParser::FunctionDeclarationContext* EZLanguageParser::ClassDeclarationContext::functionDeclaration(size_t i) {
  return getRuleContext<EZLanguageParser::FunctionDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> EZLanguageParser::ClassDeclarationContext::COMMA() {
  return getTokens(EZLanguageParser::COMMA);
}

tree::TerminalNode* EZLanguageParser::ClassDeclarationContext::COMMA(size_t i) {
  return getToken(EZLanguageParser::COMMA, i);
}


size_t EZLanguageParser::ClassDeclarationContext::getRuleIndex() const {
  return EZLanguageParser::RuleClassDeclaration;
}

void EZLanguageParser::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void EZLanguageParser::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}


std::any EZLanguageParser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitClassDeclaration(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ClassDeclarationContext* EZLanguageParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, EZLanguageParser::RuleClassDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0)) {
      setState(112);
      accessModifier();
    }
    setState(115);
    match(EZLanguageParser::T__6);
    setState(116);
    match(EZLanguageParser::IDENTIFIER);
    setState(117);
    match(EZLanguageParser::T__7);
    setState(118);
    match(EZLanguageParser::T__8);
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__9) {
      setState(119);
      match(EZLanguageParser::T__9);
      setState(120);
      match(EZLanguageParser::IDENTIFIER);
    }
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__10) {
      setState(123);
      match(EZLanguageParser::T__10);
      setState(124);
      match(EZLanguageParser::IDENTIFIER);
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == EZLanguageParser::COMMA) {
        setState(125);
        match(EZLanguageParser::COMMA);
        setState(126);
        match(EZLanguageParser::IDENTIFIER);
        setState(131);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(134);
    match(EZLanguageParser::T__11);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 544923975680) != 0)) {
      setState(137);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(135);
        variableDeclaration();
        break;
      }

      case 2: {
        setState(136);
        functionDeclaration();
        break;
      }

      default:
        break;
      }
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    match(EZLanguageParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

EZLanguageParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::TypeContext* EZLanguageParser::VariableDeclarationContext::type() {
  return getRuleContext<EZLanguageParser::TypeContext>(0);
}

tree::TerminalNode* EZLanguageParser::VariableDeclarationContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::AccessModifierContext* EZLanguageParser::VariableDeclarationContext::accessModifier() {
  return getRuleContext<EZLanguageParser::AccessModifierContext>(0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::VariableDeclarationContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}


size_t EZLanguageParser::VariableDeclarationContext::getRuleIndex() const {
  return EZLanguageParser::RuleVariableDeclaration;
}

void EZLanguageParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void EZLanguageParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


std::any EZLanguageParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::VariableDeclarationContext* EZLanguageParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, EZLanguageParser::RuleVariableDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0)) {
      setState(144);
      accessModifier();
    }
    setState(147);
    type();
    setState(148);
    match(EZLanguageParser::IDENTIFIER);
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__13) {
      setState(149);
      match(EZLanguageParser::T__13);
      setState(150);
      expression();
    }
    setState(153);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

EZLanguageParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::AssignmentStatementContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::AssignmentStatementContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}


size_t EZLanguageParser::AssignmentStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleAssignmentStatement;
}

void EZLanguageParser::AssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentStatement(this);
}

void EZLanguageParser::AssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentStatement(this);
}


std::any EZLanguageParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::AssignmentStatementContext* EZLanguageParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, EZLanguageParser::RuleAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(EZLanguageParser::IDENTIFIER);
    setState(156);
    match(EZLanguageParser::T__13);
    setState(157);
    expression();
    setState(158);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

EZLanguageParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t EZLanguageParser::BreakStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleBreakStatement;
}

void EZLanguageParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void EZLanguageParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}


std::any EZLanguageParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::BreakStatementContext* EZLanguageParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, EZLanguageParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(EZLanguageParser::T__14);
    setState(161);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

EZLanguageParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t EZLanguageParser::ContinueStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleContinueStatement;
}

void EZLanguageParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void EZLanguageParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}


std::any EZLanguageParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ContinueStatementContext* EZLanguageParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, EZLanguageParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(EZLanguageParser::T__15);
    setState(164);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

EZLanguageParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::TypeContext* EZLanguageParser::FunctionDeclarationContext::type() {
  return getRuleContext<EZLanguageParser::TypeContext>(0);
}

tree::TerminalNode* EZLanguageParser::FunctionDeclarationContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::AccessModifierContext* EZLanguageParser::FunctionDeclarationContext::accessModifier() {
  return getRuleContext<EZLanguageParser::AccessModifierContext>(0);
}

EZLanguageParser::ParameterListContext* EZLanguageParser::FunctionDeclarationContext::parameterList() {
  return getRuleContext<EZLanguageParser::ParameterListContext>(0);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::FunctionDeclarationContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::FunctionDeclarationContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}


size_t EZLanguageParser::FunctionDeclarationContext::getRuleIndex() const {
  return EZLanguageParser::RuleFunctionDeclaration;
}

void EZLanguageParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void EZLanguageParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}


std::any EZLanguageParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::FunctionDeclarationContext* EZLanguageParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 20, EZLanguageParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0)) {
      setState(166);
      accessModifier();
    }
    setState(169);
    type();
    setState(170);
    match(EZLanguageParser::IDENTIFIER);
    setState(171);
    match(EZLanguageParser::T__7);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 541165879296) != 0)) {
      setState(172);
      parameterList();
    }
    setState(175);
    match(EZLanguageParser::T__8);
    setState(176);
    match(EZLanguageParser::T__11);
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(177);
      statement();
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(183);
    match(EZLanguageParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

EZLanguageParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EZLanguageParser::ParameterContext *> EZLanguageParser::ParameterListContext::parameter() {
  return getRuleContexts<EZLanguageParser::ParameterContext>();
}

EZLanguageParser::ParameterContext* EZLanguageParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<EZLanguageParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> EZLanguageParser::ParameterListContext::COMMA() {
  return getTokens(EZLanguageParser::COMMA);
}

tree::TerminalNode* EZLanguageParser::ParameterListContext::COMMA(size_t i) {
  return getToken(EZLanguageParser::COMMA, i);
}


size_t EZLanguageParser::ParameterListContext::getRuleIndex() const {
  return EZLanguageParser::RuleParameterList;
}

void EZLanguageParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void EZLanguageParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


std::any EZLanguageParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ParameterListContext* EZLanguageParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 22, EZLanguageParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    parameter();
    setState(190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EZLanguageParser::COMMA) {
      setState(186);
      match(EZLanguageParser::COMMA);
      setState(187);
      parameter();
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

EZLanguageParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::TypeContext* EZLanguageParser::ParameterContext::type() {
  return getRuleContext<EZLanguageParser::TypeContext>(0);
}

tree::TerminalNode* EZLanguageParser::ParameterContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}


size_t EZLanguageParser::ParameterContext::getRuleIndex() const {
  return EZLanguageParser::RuleParameter;
}

void EZLanguageParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void EZLanguageParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


std::any EZLanguageParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ParameterContext* EZLanguageParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 24, EZLanguageParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    type();
    setState(194);
    match(EZLanguageParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

EZLanguageParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ReturnStatementContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}


size_t EZLanguageParser::ReturnStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleReturnStatement;
}

void EZLanguageParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void EZLanguageParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any EZLanguageParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ReturnStatementContext* EZLanguageParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, EZLanguageParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(EZLanguageParser::T__16);
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(197);
      expression();
    }
    setState(200);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

EZLanguageParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::FunctionCallContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::ArgumentListContext* EZLanguageParser::FunctionCallContext::argumentList() {
  return getRuleContext<EZLanguageParser::ArgumentListContext>(0);
}


size_t EZLanguageParser::FunctionCallContext::getRuleIndex() const {
  return EZLanguageParser::RuleFunctionCall;
}

void EZLanguageParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void EZLanguageParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any EZLanguageParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::FunctionCallContext* EZLanguageParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 28, EZLanguageParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(EZLanguageParser::IDENTIFIER);
    setState(203);
    match(EZLanguageParser::T__7);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(204);
      argumentList();
    }
    setState(207);
    match(EZLanguageParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FriendFunctionCallContext ------------------------------------------------------------------

EZLanguageParser::FriendFunctionCallContext::FriendFunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EZLanguageParser::FriendFunctionCallContext::IDENTIFIER() {
  return getTokens(EZLanguageParser::IDENTIFIER);
}

tree::TerminalNode* EZLanguageParser::FriendFunctionCallContext::IDENTIFIER(size_t i) {
  return getToken(EZLanguageParser::IDENTIFIER, i);
}

EZLanguageParser::ArgumentListContext* EZLanguageParser::FriendFunctionCallContext::argumentList() {
  return getRuleContext<EZLanguageParser::ArgumentListContext>(0);
}


size_t EZLanguageParser::FriendFunctionCallContext::getRuleIndex() const {
  return EZLanguageParser::RuleFriendFunctionCall;
}

void EZLanguageParser::FriendFunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFriendFunctionCall(this);
}

void EZLanguageParser::FriendFunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFriendFunctionCall(this);
}


std::any EZLanguageParser::FriendFunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitFriendFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::FriendFunctionCallContext* EZLanguageParser::friendFunctionCall() {
  FriendFunctionCallContext *_localctx = _tracker.createInstance<FriendFunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 30, EZLanguageParser::RuleFriendFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(EZLanguageParser::IDENTIFIER);
    setState(210);
    match(EZLanguageParser::T__17);
    setState(211);
    match(EZLanguageParser::IDENTIFIER);
    setState(212);
    match(EZLanguageParser::T__7);
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(213);
      argumentList();
    }
    setState(216);
    match(EZLanguageParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

EZLanguageParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EZLanguageParser::ExpressionContext *> EZLanguageParser::ArgumentListContext::expression() {
  return getRuleContexts<EZLanguageParser::ExpressionContext>();
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<EZLanguageParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> EZLanguageParser::ArgumentListContext::COMMA() {
  return getTokens(EZLanguageParser::COMMA);
}

tree::TerminalNode* EZLanguageParser::ArgumentListContext::COMMA(size_t i) {
  return getToken(EZLanguageParser::COMMA, i);
}


size_t EZLanguageParser::ArgumentListContext::getRuleIndex() const {
  return EZLanguageParser::RuleArgumentList;
}

void EZLanguageParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void EZLanguageParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}


std::any EZLanguageParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ArgumentListContext* EZLanguageParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 32, EZLanguageParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    expression();
    setState(223);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EZLanguageParser::COMMA) {
      setState(219);
      match(EZLanguageParser::COMMA);
      setState(220);
      expression();
      setState(225);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlFlowStatementContext ------------------------------------------------------------------

EZLanguageParser::ControlFlowStatementContext::ControlFlowStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::IfStatementContext* EZLanguageParser::ControlFlowStatementContext::ifStatement() {
  return getRuleContext<EZLanguageParser::IfStatementContext>(0);
}

EZLanguageParser::LoopStatementContext* EZLanguageParser::ControlFlowStatementContext::loopStatement() {
  return getRuleContext<EZLanguageParser::LoopStatementContext>(0);
}


size_t EZLanguageParser::ControlFlowStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleControlFlowStatement;
}

void EZLanguageParser::ControlFlowStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterControlFlowStatement(this);
}

void EZLanguageParser::ControlFlowStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitControlFlowStatement(this);
}


std::any EZLanguageParser::ControlFlowStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitControlFlowStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ControlFlowStatementContext* EZLanguageParser::controlFlowStatement() {
  ControlFlowStatementContext *_localctx = _tracker.createInstance<ControlFlowStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, EZLanguageParser::RuleControlFlowStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EZLanguageParser::T__18: {
        enterOuterAlt(_localctx, 1);
        setState(226);
        ifStatement();
        break;
      }

      case EZLanguageParser::T__21:
      case EZLanguageParser::T__22: {
        enterOuterAlt(_localctx, 2);
        setState(227);
        loopStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

EZLanguageParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EZLanguageParser::ExpressionContext *> EZLanguageParser::IfStatementContext::expression() {
  return getRuleContexts<EZLanguageParser::ExpressionContext>();
}

EZLanguageParser::ExpressionContext* EZLanguageParser::IfStatementContext::expression(size_t i) {
  return getRuleContext<EZLanguageParser::ExpressionContext>(i);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::IfStatementContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}


size_t EZLanguageParser::IfStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleIfStatement;
}

void EZLanguageParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void EZLanguageParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any EZLanguageParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::IfStatementContext* EZLanguageParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, EZLanguageParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(EZLanguageParser::T__18);
    setState(231);
    match(EZLanguageParser::T__7);
    setState(232);
    expression();
    setState(233);
    match(EZLanguageParser::T__8);
    setState(234);
    match(EZLanguageParser::T__11);
    setState(238);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(235);
      statement();
      setState(240);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(241);
    match(EZLanguageParser::T__12);
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EZLanguageParser::T__19) {
      setState(242);
      match(EZLanguageParser::T__19);
      setState(243);
      match(EZLanguageParser::T__7);
      setState(244);
      expression();
      setState(245);
      match(EZLanguageParser::T__8);
      setState(246);
      match(EZLanguageParser::T__11);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(247);
        statement();
        setState(252);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(253);
      match(EZLanguageParser::T__12);
      setState(259);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__20) {
      setState(260);
      match(EZLanguageParser::T__20);
      setState(261);
      match(EZLanguageParser::T__11);
      setState(265);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(262);
        statement();
        setState(267);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(268);
      match(EZLanguageParser::T__12);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStatementContext ------------------------------------------------------------------

EZLanguageParser::LoopStatementContext::LoopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::WhileLoopContext* EZLanguageParser::LoopStatementContext::whileLoop() {
  return getRuleContext<EZLanguageParser::WhileLoopContext>(0);
}

EZLanguageParser::ForLoopContext* EZLanguageParser::LoopStatementContext::forLoop() {
  return getRuleContext<EZLanguageParser::ForLoopContext>(0);
}


size_t EZLanguageParser::LoopStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleLoopStatement;
}

void EZLanguageParser::LoopStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopStatement(this);
}

void EZLanguageParser::LoopStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopStatement(this);
}


std::any EZLanguageParser::LoopStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitLoopStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::LoopStatementContext* EZLanguageParser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, EZLanguageParser::RuleLoopStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EZLanguageParser::T__21: {
        enterOuterAlt(_localctx, 1);
        setState(271);
        whileLoop();
        break;
      }

      case EZLanguageParser::T__22: {
        enterOuterAlt(_localctx, 2);
        setState(272);
        forLoop();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLoopContext ------------------------------------------------------------------

EZLanguageParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::ExpressionContext* EZLanguageParser::WhileLoopContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::WhileLoopContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::WhileLoopContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}


size_t EZLanguageParser::WhileLoopContext::getRuleIndex() const {
  return EZLanguageParser::RuleWhileLoop;
}

void EZLanguageParser::WhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoop(this);
}

void EZLanguageParser::WhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoop(this);
}


std::any EZLanguageParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::WhileLoopContext* EZLanguageParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 40, EZLanguageParser::RuleWhileLoop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(EZLanguageParser::T__21);
    setState(276);
    match(EZLanguageParser::T__7);
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(277);
      expression();
    }
    setState(280);
    match(EZLanguageParser::T__8);
    setState(281);
    match(EZLanguageParser::T__11);
    setState(285);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(282);
      statement();
      setState(287);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(288);
    match(EZLanguageParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForLoopContext ------------------------------------------------------------------

EZLanguageParser::ForLoopContext::ForLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::ForInitContext* EZLanguageParser::ForLoopContext::forInit() {
  return getRuleContext<EZLanguageParser::ForInitContext>(0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ForLoopContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

EZLanguageParser::ForUpdateContext* EZLanguageParser::ForLoopContext::forUpdate() {
  return getRuleContext<EZLanguageParser::ForUpdateContext>(0);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::ForLoopContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::ForLoopContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}


size_t EZLanguageParser::ForLoopContext::getRuleIndex() const {
  return EZLanguageParser::RuleForLoop;
}

void EZLanguageParser::ForLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForLoop(this);
}

void EZLanguageParser::ForLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForLoop(this);
}


std::any EZLanguageParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ForLoopContext* EZLanguageParser::forLoop() {
  ForLoopContext *_localctx = _tracker.createInstance<ForLoopContext>(_ctx, getState());
  enterRule(_localctx, 42, EZLanguageParser::RuleForLoop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    match(EZLanguageParser::T__22);
    setState(291);
    match(EZLanguageParser::T__7);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132482561212672) != 0)) {
      setState(292);
      forInit();
    }
    setState(295);
    match(EZLanguageParser::T__1);
    setState(297);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(296);
      expression();
    }
    setState(299);
    match(EZLanguageParser::T__1);
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(300);
      forUpdate();
    }
    setState(303);
    match(EZLanguageParser::T__8);
    setState(304);
    match(EZLanguageParser::T__11);
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(305);
      statement();
      setState(310);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(311);
    match(EZLanguageParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

EZLanguageParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t EZLanguageParser::ForInitContext::getRuleIndex() const {
  return EZLanguageParser::RuleForInit;
}

void EZLanguageParser::ForInitContext::copyFrom(ForInitContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForInitVarDeclContext ------------------------------------------------------------------

EZLanguageParser::TypeContext* EZLanguageParser::ForInitVarDeclContext::type() {
  return getRuleContext<EZLanguageParser::TypeContext>(0);
}

tree::TerminalNode* EZLanguageParser::ForInitVarDeclContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ForInitVarDeclContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

EZLanguageParser::ForInitVarDeclContext::ForInitVarDeclContext(ForInitContext *ctx) { copyFrom(ctx); }

void EZLanguageParser::ForInitVarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInitVarDecl(this);
}
void EZLanguageParser::ForInitVarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInitVarDecl(this);
}

std::any EZLanguageParser::ForInitVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForInitVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForInitAssignContext ------------------------------------------------------------------

tree::TerminalNode* EZLanguageParser::ForInitAssignContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ForInitAssignContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

EZLanguageParser::ForInitAssignContext::ForInitAssignContext(ForInitContext *ctx) { copyFrom(ctx); }

void EZLanguageParser::ForInitAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInitAssign(this);
}
void EZLanguageParser::ForInitAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInitAssign(this);
}

std::any EZLanguageParser::ForInitAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForInitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForInitExprContext ------------------------------------------------------------------

EZLanguageParser::ExpressionContext* EZLanguageParser::ForInitExprContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

EZLanguageParser::ForInitExprContext::ForInitExprContext(ForInitContext *ctx) { copyFrom(ctx); }

void EZLanguageParser::ForInitExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInitExpr(this);
}
void EZLanguageParser::ForInitExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInitExpr(this);
}

std::any EZLanguageParser::ForInitExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForInitExpr(this);
  else
    return visitor->visitChildren(this);
}
EZLanguageParser::ForInitContext* EZLanguageParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 44, EZLanguageParser::RuleForInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<EZLanguageParser::ForInitVarDeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(313);
      type();
      setState(314);
      match(EZLanguageParser::IDENTIFIER);
      setState(317);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == EZLanguageParser::T__13) {
        setState(315);
        match(EZLanguageParser::T__13);
        setState(316);
        expression();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<EZLanguageParser::ForInitAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(319);
      match(EZLanguageParser::IDENTIFIER);
      setState(320);
      match(EZLanguageParser::T__13);
      setState(321);
      expression();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<EZLanguageParser::ForInitExprContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(322);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForUpdateContext ------------------------------------------------------------------

EZLanguageParser::ForUpdateContext::ForUpdateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t EZLanguageParser::ForUpdateContext::getRuleIndex() const {
  return EZLanguageParser::RuleForUpdate;
}

void EZLanguageParser::ForUpdateContext::copyFrom(ForUpdateContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForUpdateAssignContext ------------------------------------------------------------------

tree::TerminalNode* EZLanguageParser::ForUpdateAssignContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ForUpdateAssignContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

EZLanguageParser::ForUpdateAssignContext::ForUpdateAssignContext(ForUpdateContext *ctx) { copyFrom(ctx); }

void EZLanguageParser::ForUpdateAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForUpdateAssign(this);
}
void EZLanguageParser::ForUpdateAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForUpdateAssign(this);
}

std::any EZLanguageParser::ForUpdateAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForUpdateAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForUpdateExprContext ------------------------------------------------------------------

EZLanguageParser::ExpressionContext* EZLanguageParser::ForUpdateExprContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

EZLanguageParser::ForUpdateExprContext::ForUpdateExprContext(ForUpdateContext *ctx) { copyFrom(ctx); }

void EZLanguageParser::ForUpdateExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForUpdateExpr(this);
}
void EZLanguageParser::ForUpdateExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForUpdateExpr(this);
}

std::any EZLanguageParser::ForUpdateExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForUpdateExpr(this);
  else
    return visitor->visitChildren(this);
}
EZLanguageParser::ForUpdateContext* EZLanguageParser::forUpdate() {
  ForUpdateContext *_localctx = _tracker.createInstance<ForUpdateContext>(_ctx, getState());
  enterRule(_localctx, 46, EZLanguageParser::RuleForUpdate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<EZLanguageParser::ForUpdateAssignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(325);
      match(EZLanguageParser::IDENTIFIER);
      setState(326);
      match(EZLanguageParser::T__13);
      setState(327);
      expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<EZLanguageParser::ForUpdateExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(328);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForeachStatementContext ------------------------------------------------------------------

EZLanguageParser::ForeachStatementContext::ForeachStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EZLanguageParser::ForeachStatementContext::IDENTIFIER() {
  return getTokens(EZLanguageParser::IDENTIFIER);
}

tree::TerminalNode* EZLanguageParser::ForeachStatementContext::IDENTIFIER(size_t i) {
  return getToken(EZLanguageParser::IDENTIFIER, i);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::ForeachStatementContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::ForeachStatementContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}


size_t EZLanguageParser::ForeachStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleForeachStatement;
}

void EZLanguageParser::ForeachStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeachStatement(this);
}

void EZLanguageParser::ForeachStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeachStatement(this);
}


std::any EZLanguageParser::ForeachStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitForeachStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ForeachStatementContext* EZLanguageParser::foreachStatement() {
  ForeachStatementContext *_localctx = _tracker.createInstance<ForeachStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, EZLanguageParser::RuleForeachStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    match(EZLanguageParser::T__22);
    setState(332);
    match(EZLanguageParser::IDENTIFIER);
    setState(333);
    match(EZLanguageParser::T__23);
    setState(334);
    match(EZLanguageParser::IDENTIFIER);
    setState(335);
    match(EZLanguageParser::T__11);
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(336);
      statement();
      setState(341);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(342);
    match(EZLanguageParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryCatchStatementContext ------------------------------------------------------------------

EZLanguageParser::TryCatchStatementContext::TryCatchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::TryCatchStatementContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::TryCatchStatementContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
}

tree::TerminalNode* EZLanguageParser::TryCatchStatementContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}


size_t EZLanguageParser::TryCatchStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleTryCatchStatement;
}

void EZLanguageParser::TryCatchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryCatchStatement(this);
}

void EZLanguageParser::TryCatchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryCatchStatement(this);
}


std::any EZLanguageParser::TryCatchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitTryCatchStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::TryCatchStatementContext* EZLanguageParser::tryCatchStatement() {
  TryCatchStatementContext *_localctx = _tracker.createInstance<TryCatchStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, EZLanguageParser::RuleTryCatchStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(EZLanguageParser::T__24);
    setState(345);
    match(EZLanguageParser::T__11);
    setState(349);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(346);
      statement();
      setState(351);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(352);
    match(EZLanguageParser::T__12);
    setState(365);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__25) {
      setState(353);
      match(EZLanguageParser::T__25);
      setState(354);
      match(EZLanguageParser::T__7);
      setState(355);
      match(EZLanguageParser::IDENTIFIER);
      setState(356);
      match(EZLanguageParser::T__8);
      setState(357);
      match(EZLanguageParser::T__11);
      setState(361);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(358);
        statement();
        setState(363);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(364);
      match(EZLanguageParser::T__12);
    }
    setState(376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__26) {
      setState(367);
      match(EZLanguageParser::T__26);
      setState(368);
      match(EZLanguageParser::T__11);
      setState(372);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(369);
        statement();
        setState(374);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(375);
      match(EZLanguageParser::T__12);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RunStatementContext ------------------------------------------------------------------

EZLanguageParser::RunStatementContext::RunStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::RunStatementContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

tree::TerminalNode* EZLanguageParser::RunStatementContext::STRING() {
  return getToken(EZLanguageParser::STRING, 0);
}


size_t EZLanguageParser::RunStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleRunStatement;
}

void EZLanguageParser::RunStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRunStatement(this);
}

void EZLanguageParser::RunStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRunStatement(this);
}


std::any EZLanguageParser::RunStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitRunStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::RunStatementContext* EZLanguageParser::runStatement() {
  RunStatementContext *_localctx = _tracker.createInstance<RunStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, EZLanguageParser::RuleRunStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(EZLanguageParser::T__27);
    setState(379);
    match(EZLanguageParser::IDENTIFIER);
    setState(380);
    match(EZLanguageParser::T__4);
    setState(381);
    match(EZLanguageParser::STRING);
    setState(382);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

EZLanguageParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::ExpressionContext* EZLanguageParser::ExpressionStatementContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}


size_t EZLanguageParser::ExpressionStatementContext::getRuleIndex() const {
  return EZLanguageParser::RuleExpressionStatement;
}

void EZLanguageParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void EZLanguageParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


std::any EZLanguageParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ExpressionStatementContext* EZLanguageParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, EZLanguageParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    expression();
    setState(385);
    match(EZLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

EZLanguageParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EZLanguageParser::PrimaryExpressionContext *> EZLanguageParser::ExpressionContext::primaryExpression() {
  return getRuleContexts<EZLanguageParser::PrimaryExpressionContext>();
}

EZLanguageParser::PrimaryExpressionContext* EZLanguageParser::ExpressionContext::primaryExpression(size_t i) {
  return getRuleContext<EZLanguageParser::PrimaryExpressionContext>(i);
}

std::vector<tree::TerminalNode *> EZLanguageParser::ExpressionContext::OPERATOR() {
  return getTokens(EZLanguageParser::OPERATOR);
}

tree::TerminalNode* EZLanguageParser::ExpressionContext::OPERATOR(size_t i) {
  return getToken(EZLanguageParser::OPERATOR, i);
}

std::vector<tree::TerminalNode *> EZLanguageParser::ExpressionContext::LT() {
  return getTokens(EZLanguageParser::LT);
}

tree::TerminalNode* EZLanguageParser::ExpressionContext::LT(size_t i) {
  return getToken(EZLanguageParser::LT, i);
}

std::vector<tree::TerminalNode *> EZLanguageParser::ExpressionContext::GT() {
  return getTokens(EZLanguageParser::GT);
}

tree::TerminalNode* EZLanguageParser::ExpressionContext::GT(size_t i) {
  return getToken(EZLanguageParser::GT, i);
}


size_t EZLanguageParser::ExpressionContext::getRuleIndex() const {
  return EZLanguageParser::RuleExpression;
}

void EZLanguageParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void EZLanguageParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any EZLanguageParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 56, EZLanguageParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    primaryExpression();
    setState(392);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848290697216) != 0)) {
      setState(388);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3848290697216) != 0))) {
        antlrcpp::downCast<ExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(389);
      primaryExpression();
      setState(394);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

EZLanguageParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::PrimaryExpressionContext::IDENTIFIER() {
  return getToken(EZLanguageParser::IDENTIFIER, 0);
}

EZLanguageParser::LiteralContext* EZLanguageParser::PrimaryExpressionContext::literal() {
  return getRuleContext<EZLanguageParser::LiteralContext>(0);
}

EZLanguageParser::FunctionCallContext* EZLanguageParser::PrimaryExpressionContext::functionCall() {
  return getRuleContext<EZLanguageParser::FunctionCallContext>(0);
}

EZLanguageParser::FriendFunctionCallContext* EZLanguageParser::PrimaryExpressionContext::friendFunctionCall() {
  return getRuleContext<EZLanguageParser::FriendFunctionCallContext>(0);
}

EZLanguageParser::ExpressionContext* EZLanguageParser::PrimaryExpressionContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}


size_t EZLanguageParser::PrimaryExpressionContext::getRuleIndex() const {
  return EZLanguageParser::RulePrimaryExpression;
}

void EZLanguageParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void EZLanguageParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


std::any EZLanguageParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::PrimaryExpressionContext* EZLanguageParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 58, EZLanguageParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(403);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(395);
      match(EZLanguageParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(396);
      literal();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(397);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(398);
      friendFunctionCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(399);
      match(EZLanguageParser::T__7);
      setState(400);
      expression();
      setState(401);
      match(EZLanguageParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

EZLanguageParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::LiteralContext::STRING() {
  return getToken(EZLanguageParser::STRING, 0);
}

tree::TerminalNode* EZLanguageParser::LiteralContext::NUMBER() {
  return getToken(EZLanguageParser::NUMBER, 0);
}

tree::TerminalNode* EZLanguageParser::LiteralContext::BOOLEAN() {
  return getToken(EZLanguageParser::BOOLEAN, 0);
}


size_t EZLanguageParser::LiteralContext::getRuleIndex() const {
  return EZLanguageParser::RuleLiteral;
}

void EZLanguageParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void EZLanguageParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


std::any EZLanguageParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::LiteralContext* EZLanguageParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 60, EZLanguageParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114349209288704) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessModifierContext ------------------------------------------------------------------

EZLanguageParser::AccessModifierContext::AccessModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t EZLanguageParser::AccessModifierContext::getRuleIndex() const {
  return EZLanguageParser::RuleAccessModifier;
}

void EZLanguageParser::AccessModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessModifier(this);
}

void EZLanguageParser::AccessModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessModifier(this);
}


std::any EZLanguageParser::AccessModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitAccessModifier(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::AccessModifierContext* EZLanguageParser::accessModifier() {
  AccessModifierContext *_localctx = _tracker.createInstance<AccessModifierContext>(_ctx, getState());
  enterRule(_localctx, 62, EZLanguageParser::RuleAccessModifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

EZLanguageParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::BaseTypeContext* EZLanguageParser::TypeContext::baseType() {
  return getRuleContext<EZLanguageParser::BaseTypeContext>(0);
}


size_t EZLanguageParser::TypeContext::getRuleIndex() const {
  return EZLanguageParser::RuleType;
}

void EZLanguageParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void EZLanguageParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any EZLanguageParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::TypeContext* EZLanguageParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 64, EZLanguageParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    baseType();
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__31) {
      setState(410);
      match(EZLanguageParser::T__31);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseTypeContext ------------------------------------------------------------------

EZLanguageParser::BaseTypeContext::BaseTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EZLanguageParser::MapTypeContext* EZLanguageParser::BaseTypeContext::mapType() {
  return getRuleContext<EZLanguageParser::MapTypeContext>(0);
}


size_t EZLanguageParser::BaseTypeContext::getRuleIndex() const {
  return EZLanguageParser::RuleBaseType;
}

void EZLanguageParser::BaseTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseType(this);
}

void EZLanguageParser::BaseTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseType(this);
}


std::any EZLanguageParser::BaseTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitBaseType(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::BaseTypeContext* EZLanguageParser::baseType() {
  BaseTypeContext *_localctx = _tracker.createInstance<BaseTypeContext>(_ctx, getState());
  enterRule(_localctx, 66, EZLanguageParser::RuleBaseType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(419);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EZLanguageParser::T__32: {
        enterOuterAlt(_localctx, 1);
        setState(413);
        match(EZLanguageParser::T__32);
        break;
      }

      case EZLanguageParser::T__33: {
        enterOuterAlt(_localctx, 2);
        setState(414);
        match(EZLanguageParser::T__33);
        break;
      }

      case EZLanguageParser::T__34: {
        enterOuterAlt(_localctx, 3);
        setState(415);
        match(EZLanguageParser::T__34);
        break;
      }

      case EZLanguageParser::T__35: {
        enterOuterAlt(_localctx, 4);
        setState(416);
        match(EZLanguageParser::T__35);
        break;
      }

      case EZLanguageParser::T__36: {
        enterOuterAlt(_localctx, 5);
        setState(417);
        match(EZLanguageParser::T__36);
        break;
      }

      case EZLanguageParser::T__37: {
        enterOuterAlt(_localctx, 6);
        setState(418);
        mapType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapTypeContext ------------------------------------------------------------------

EZLanguageParser::MapTypeContext::MapTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EZLanguageParser::MapTypeContext::LT() {
  return getToken(EZLanguageParser::LT, 0);
}

std::vector<EZLanguageParser::BaseTypeContext *> EZLanguageParser::MapTypeContext::baseType() {
  return getRuleContexts<EZLanguageParser::BaseTypeContext>();
}

EZLanguageParser::BaseTypeContext* EZLanguageParser::MapTypeContext::baseType(size_t i) {
  return getRuleContext<EZLanguageParser::BaseTypeContext>(i);
}

tree::TerminalNode* EZLanguageParser::MapTypeContext::COMMA() {
  return getToken(EZLanguageParser::COMMA, 0);
}

tree::TerminalNode* EZLanguageParser::MapTypeContext::GT() {
  return getToken(EZLanguageParser::GT, 0);
}


size_t EZLanguageParser::MapTypeContext::getRuleIndex() const {
  return EZLanguageParser::RuleMapType;
}

void EZLanguageParser::MapTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapType(this);
}

void EZLanguageParser::MapTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<EZLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapType(this);
}


std::any EZLanguageParser::MapTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EZLanguageVisitor*>(visitor))
    return parserVisitor->visitMapType(this);
  else
    return visitor->visitChildren(this);
}

EZLanguageParser::MapTypeContext* EZLanguageParser::mapType() {
  MapTypeContext *_localctx = _tracker.createInstance<MapTypeContext>(_ctx, getState());
  enterRule(_localctx, 68, EZLanguageParser::RuleMapType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(EZLanguageParser::T__37);
    setState(422);
    match(EZLanguageParser::LT);
    setState(423);
    baseType();
    setState(424);
    match(EZLanguageParser::COMMA);
    setState(425);
    baseType();
    setState(426);
    match(EZLanguageParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void EZLanguageParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ezlanguageParserInitialize();
#else
  ::antlr4::internal::call_once(ezlanguageParserOnceFlag, ezlanguageParserInitialize);
#endif
}
