
// Generated from EZLanguage.g4 by ANTLR 4.13.2


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
      "foreachStatement", "tryCatchStatement", "runStatement", "expressionStatement", 
      "expression", "primaryExpression", "literal", "accessModifier", "type", 
      "baseType", "mapType"
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
  	4,1,49,376,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,1,0,1,0,1,0,1,0,5,0,67,8,0,10,0,12,0,70,9,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,87,8,1,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,3,
  	5,106,8,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,114,8,5,1,5,1,5,1,5,1,5,5,5,120,
  	8,5,10,5,12,5,123,9,5,3,5,125,8,5,1,5,1,5,1,5,5,5,130,8,5,10,5,12,5,133,
  	9,5,1,5,1,5,1,6,3,6,138,8,6,1,6,1,6,1,6,1,6,3,6,144,8,6,1,6,1,6,1,7,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,3,10,160,8,10,1,10,1,10,1,
  	10,1,10,3,10,166,8,10,1,10,1,10,1,10,5,10,171,8,10,10,10,12,10,174,9,
  	10,1,10,1,10,1,11,1,11,1,11,5,11,181,8,11,10,11,12,11,184,9,11,1,12,1,
  	12,1,12,1,13,1,13,3,13,191,8,13,1,13,1,13,1,14,1,14,1,14,3,14,198,8,14,
  	1,14,1,14,1,15,1,15,1,15,1,15,1,15,3,15,207,8,15,1,15,1,15,1,16,1,16,
  	1,16,5,16,214,8,16,10,16,12,16,217,9,16,1,17,1,17,3,17,221,8,17,1,18,
  	1,18,1,18,1,18,1,18,1,18,5,18,229,8,18,10,18,12,18,232,9,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,5,18,241,8,18,10,18,12,18,244,9,18,1,18,1,18,
  	5,18,248,8,18,10,18,12,18,251,9,18,1,18,1,18,1,18,5,18,256,8,18,10,18,
  	12,18,259,9,18,1,18,3,18,262,8,18,1,19,1,19,1,19,3,19,267,8,19,1,19,1,
  	19,1,19,5,19,272,8,19,10,19,12,19,275,9,19,1,19,1,19,1,20,1,20,1,20,1,
  	20,1,20,1,20,5,20,285,8,20,10,20,12,20,288,9,20,1,20,1,20,1,21,1,21,1,
  	21,5,21,295,8,21,10,21,12,21,298,9,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,5,21,307,8,21,10,21,12,21,310,9,21,1,21,3,21,313,8,21,1,21,1,21,1,
  	21,5,21,318,8,21,10,21,12,21,321,9,21,1,21,3,21,324,8,21,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,5,24,338,8,24,10,24,12,
  	24,341,9,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,351,8,25,1,26,
  	1,26,1,27,1,27,1,28,1,28,3,28,359,8,28,1,29,1,29,1,29,1,29,1,29,1,29,
  	3,29,367,8,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,0,0,31,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,0,4,1,0,22,23,1,0,39,41,2,0,43,43,45,46,1,0,29,31,401,0,68,1,
  	0,0,0,2,86,1,0,0,0,4,88,1,0,0,0,6,92,1,0,0,0,8,96,1,0,0,0,10,105,1,0,
  	0,0,12,137,1,0,0,0,14,147,1,0,0,0,16,152,1,0,0,0,18,155,1,0,0,0,20,159,
  	1,0,0,0,22,177,1,0,0,0,24,185,1,0,0,0,26,188,1,0,0,0,28,194,1,0,0,0,30,
  	201,1,0,0,0,32,210,1,0,0,0,34,220,1,0,0,0,36,222,1,0,0,0,38,263,1,0,0,
  	0,40,278,1,0,0,0,42,291,1,0,0,0,44,325,1,0,0,0,46,331,1,0,0,0,48,334,
  	1,0,0,0,50,350,1,0,0,0,52,352,1,0,0,0,54,354,1,0,0,0,56,356,1,0,0,0,58,
  	366,1,0,0,0,60,368,1,0,0,0,62,67,3,2,1,0,63,67,3,10,5,0,64,67,3,42,21,
  	0,65,67,3,44,22,0,66,62,1,0,0,0,66,63,1,0,0,0,66,64,1,0,0,0,66,65,1,0,
  	0,0,67,70,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,71,1,0,0,0,70,68,1,0,
  	0,0,71,72,5,0,0,1,72,1,1,0,0,0,73,87,3,4,2,0,74,87,3,6,3,0,75,87,3,8,
  	4,0,76,87,3,30,15,0,77,87,3,46,23,0,78,87,3,12,6,0,79,87,3,14,7,0,80,
  	87,3,34,17,0,81,87,3,40,20,0,82,87,3,20,10,0,83,87,3,26,13,0,84,87,3,
  	16,8,0,85,87,3,18,9,0,86,73,1,0,0,0,86,74,1,0,0,0,86,75,1,0,0,0,86,76,
  	1,0,0,0,86,77,1,0,0,0,86,78,1,0,0,0,86,79,1,0,0,0,86,80,1,0,0,0,86,81,
  	1,0,0,0,86,82,1,0,0,0,86,83,1,0,0,0,86,84,1,0,0,0,86,85,1,0,0,0,87,3,
  	1,0,0,0,88,89,5,1,0,0,89,90,5,44,0,0,90,91,5,2,0,0,91,5,1,0,0,0,92,93,
  	5,3,0,0,93,94,5,44,0,0,94,95,5,2,0,0,95,7,1,0,0,0,96,97,5,4,0,0,97,98,
  	5,44,0,0,98,99,5,5,0,0,99,100,5,44,0,0,100,101,5,6,0,0,101,102,5,44,0,
  	0,102,103,5,2,0,0,103,9,1,0,0,0,104,106,3,54,27,0,105,104,1,0,0,0,105,
  	106,1,0,0,0,106,107,1,0,0,0,107,108,5,7,0,0,108,109,5,44,0,0,109,110,
  	5,8,0,0,110,113,5,9,0,0,111,112,5,10,0,0,112,114,5,44,0,0,113,111,1,0,
  	0,0,113,114,1,0,0,0,114,124,1,0,0,0,115,116,5,11,0,0,116,121,5,44,0,0,
  	117,118,5,42,0,0,118,120,5,44,0,0,119,117,1,0,0,0,120,123,1,0,0,0,121,
  	119,1,0,0,0,121,122,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,124,115,1,
  	0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,126,131,5,12,0,0,127,130,3,12,6,
  	0,128,130,3,20,10,0,129,127,1,0,0,0,129,128,1,0,0,0,130,133,1,0,0,0,131,
  	129,1,0,0,0,131,132,1,0,0,0,132,134,1,0,0,0,133,131,1,0,0,0,134,135,5,
  	13,0,0,135,11,1,0,0,0,136,138,3,54,27,0,137,136,1,0,0,0,137,138,1,0,0,
  	0,138,139,1,0,0,0,139,140,3,56,28,0,140,143,5,44,0,0,141,142,5,14,0,0,
  	142,144,3,48,24,0,143,141,1,0,0,0,143,144,1,0,0,0,144,145,1,0,0,0,145,
  	146,5,2,0,0,146,13,1,0,0,0,147,148,5,44,0,0,148,149,5,14,0,0,149,150,
  	3,48,24,0,150,151,5,2,0,0,151,15,1,0,0,0,152,153,5,15,0,0,153,154,5,2,
  	0,0,154,17,1,0,0,0,155,156,5,16,0,0,156,157,5,2,0,0,157,19,1,0,0,0,158,
  	160,3,54,27,0,159,158,1,0,0,0,159,160,1,0,0,0,160,161,1,0,0,0,161,162,
  	3,56,28,0,162,163,5,44,0,0,163,165,5,8,0,0,164,166,3,22,11,0,165,164,
  	1,0,0,0,165,166,1,0,0,0,166,167,1,0,0,0,167,168,5,9,0,0,168,172,5,12,
  	0,0,169,171,3,2,1,0,170,169,1,0,0,0,171,174,1,0,0,0,172,170,1,0,0,0,172,
  	173,1,0,0,0,173,175,1,0,0,0,174,172,1,0,0,0,175,176,5,13,0,0,176,21,1,
  	0,0,0,177,182,3,24,12,0,178,179,5,42,0,0,179,181,3,24,12,0,180,178,1,
  	0,0,0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,23,1,0,0,0,
  	184,182,1,0,0,0,185,186,3,56,28,0,186,187,5,44,0,0,187,25,1,0,0,0,188,
  	190,5,17,0,0,189,191,3,48,24,0,190,189,1,0,0,0,190,191,1,0,0,0,191,192,
  	1,0,0,0,192,193,5,2,0,0,193,27,1,0,0,0,194,195,5,44,0,0,195,197,5,8,0,
  	0,196,198,3,32,16,0,197,196,1,0,0,0,197,198,1,0,0,0,198,199,1,0,0,0,199,
  	200,5,9,0,0,200,29,1,0,0,0,201,202,5,44,0,0,202,203,5,18,0,0,203,204,
  	5,44,0,0,204,206,5,8,0,0,205,207,3,32,16,0,206,205,1,0,0,0,206,207,1,
  	0,0,0,207,208,1,0,0,0,208,209,5,9,0,0,209,31,1,0,0,0,210,215,3,48,24,
  	0,211,212,5,42,0,0,212,214,3,48,24,0,213,211,1,0,0,0,214,217,1,0,0,0,
  	215,213,1,0,0,0,215,216,1,0,0,0,216,33,1,0,0,0,217,215,1,0,0,0,218,221,
  	3,36,18,0,219,221,3,38,19,0,220,218,1,0,0,0,220,219,1,0,0,0,221,35,1,
  	0,0,0,222,223,5,19,0,0,223,224,5,8,0,0,224,225,3,48,24,0,225,226,5,9,
  	0,0,226,230,5,12,0,0,227,229,3,2,1,0,228,227,1,0,0,0,229,232,1,0,0,0,
  	230,228,1,0,0,0,230,231,1,0,0,0,231,233,1,0,0,0,232,230,1,0,0,0,233,249,
  	5,13,0,0,234,235,5,20,0,0,235,236,5,8,0,0,236,237,3,48,24,0,237,238,5,
  	9,0,0,238,242,5,12,0,0,239,241,3,2,1,0,240,239,1,0,0,0,241,244,1,0,0,
  	0,242,240,1,0,0,0,242,243,1,0,0,0,243,245,1,0,0,0,244,242,1,0,0,0,245,
  	246,5,13,0,0,246,248,1,0,0,0,247,234,1,0,0,0,248,251,1,0,0,0,249,247,
  	1,0,0,0,249,250,1,0,0,0,250,261,1,0,0,0,251,249,1,0,0,0,252,253,5,21,
  	0,0,253,257,5,12,0,0,254,256,3,2,1,0,255,254,1,0,0,0,256,259,1,0,0,0,
  	257,255,1,0,0,0,257,258,1,0,0,0,258,260,1,0,0,0,259,257,1,0,0,0,260,262,
  	5,13,0,0,261,252,1,0,0,0,261,262,1,0,0,0,262,37,1,0,0,0,263,264,7,0,0,
  	0,264,266,5,8,0,0,265,267,3,48,24,0,266,265,1,0,0,0,266,267,1,0,0,0,267,
  	268,1,0,0,0,268,269,5,9,0,0,269,273,5,12,0,0,270,272,3,2,1,0,271,270,
  	1,0,0,0,272,275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,276,1,0,0,
  	0,275,273,1,0,0,0,276,277,5,13,0,0,277,39,1,0,0,0,278,279,5,23,0,0,279,
  	280,5,44,0,0,280,281,5,24,0,0,281,282,5,44,0,0,282,286,5,12,0,0,283,285,
  	3,2,1,0,284,283,1,0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,286,287,1,0,0,
  	0,287,289,1,0,0,0,288,286,1,0,0,0,289,290,5,13,0,0,290,41,1,0,0,0,291,
  	292,5,25,0,0,292,296,5,12,0,0,293,295,3,2,1,0,294,293,1,0,0,0,295,298,
  	1,0,0,0,296,294,1,0,0,0,296,297,1,0,0,0,297,299,1,0,0,0,298,296,1,0,0,
  	0,299,312,5,13,0,0,300,301,5,26,0,0,301,302,5,8,0,0,302,303,5,44,0,0,
  	303,304,5,9,0,0,304,308,5,12,0,0,305,307,3,2,1,0,306,305,1,0,0,0,307,
  	310,1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,311,1,0,0,0,310,308,1,
  	0,0,0,311,313,5,13,0,0,312,300,1,0,0,0,312,313,1,0,0,0,313,323,1,0,0,
  	0,314,315,5,27,0,0,315,319,5,12,0,0,316,318,3,2,1,0,317,316,1,0,0,0,318,
  	321,1,0,0,0,319,317,1,0,0,0,319,320,1,0,0,0,320,322,1,0,0,0,321,319,1,
  	0,0,0,322,324,5,13,0,0,323,314,1,0,0,0,323,324,1,0,0,0,324,43,1,0,0,0,
  	325,326,5,28,0,0,326,327,5,44,0,0,327,328,5,5,0,0,328,329,5,45,0,0,329,
  	330,5,2,0,0,330,45,1,0,0,0,331,332,3,48,24,0,332,333,5,2,0,0,333,47,1,
  	0,0,0,334,339,3,50,25,0,335,336,7,1,0,0,336,338,3,50,25,0,337,335,1,0,
  	0,0,338,341,1,0,0,0,339,337,1,0,0,0,339,340,1,0,0,0,340,49,1,0,0,0,341,
  	339,1,0,0,0,342,351,5,44,0,0,343,351,3,52,26,0,344,351,3,28,14,0,345,
  	351,3,30,15,0,346,347,5,8,0,0,347,348,3,48,24,0,348,349,5,9,0,0,349,351,
  	1,0,0,0,350,342,1,0,0,0,350,343,1,0,0,0,350,344,1,0,0,0,350,345,1,0,0,
  	0,350,346,1,0,0,0,351,51,1,0,0,0,352,353,7,2,0,0,353,53,1,0,0,0,354,355,
  	7,3,0,0,355,55,1,0,0,0,356,358,3,58,29,0,357,359,5,32,0,0,358,357,1,0,
  	0,0,358,359,1,0,0,0,359,57,1,0,0,0,360,367,5,33,0,0,361,367,5,34,0,0,
  	362,367,5,35,0,0,363,367,5,36,0,0,364,367,5,37,0,0,365,367,3,60,30,0,
  	366,360,1,0,0,0,366,361,1,0,0,0,366,362,1,0,0,0,366,363,1,0,0,0,366,364,
  	1,0,0,0,366,365,1,0,0,0,367,59,1,0,0,0,368,369,5,38,0,0,369,370,5,40,
  	0,0,370,371,3,58,29,0,371,372,5,42,0,0,372,373,3,58,29,0,373,374,5,41,
  	0,0,374,61,1,0,0,0,37,66,68,86,105,113,121,124,129,131,137,143,159,165,
  	172,182,190,197,206,215,220,230,242,249,257,261,266,273,286,296,308,312,
  	319,323,339,350,358,366
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
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486634635674) != 0)) {
      setState(66);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(62);
        statement();
        break;
      }

      case 2: {
        setState(63);
        classDeclaration();
        break;
      }

      case 3: {
        setState(64);
        tryCatchStatement();
        break;
      }

      case 4: {
        setState(65);
        runStatement();
        break;
      }

      default:
        break;
      }
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
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
    setState(86);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(73);
      envDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
      includeStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(75);
      friendStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(76);
      friendFunctionCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(77);
      expressionStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(78);
      variableDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(79);
      assignmentStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(80);
      controlFlowStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(81);
      foreachStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(82);
      functionDeclaration();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(83);
      returnStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(84);
      breakStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(85);
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
    setState(88);
    match(EZLanguageParser::T__0);
    setState(89);
    match(EZLanguageParser::IDENTIFIER);
    setState(90);
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
    setState(92);
    match(EZLanguageParser::T__2);
    setState(93);
    match(EZLanguageParser::IDENTIFIER);
    setState(94);
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
    setState(96);
    match(EZLanguageParser::T__3);
    setState(97);
    match(EZLanguageParser::IDENTIFIER);
    setState(98);
    match(EZLanguageParser::T__4);
    setState(99);
    match(EZLanguageParser::IDENTIFIER);
    setState(100);
    match(EZLanguageParser::T__5);
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
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0)) {
      setState(104);
      accessModifier();
    }
    setState(107);
    match(EZLanguageParser::T__6);
    setState(108);
    match(EZLanguageParser::IDENTIFIER);
    setState(109);
    match(EZLanguageParser::T__7);
    setState(110);
    match(EZLanguageParser::T__8);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__9) {
      setState(111);
      match(EZLanguageParser::T__9);
      setState(112);
      match(EZLanguageParser::IDENTIFIER);
    }
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__10) {
      setState(115);
      match(EZLanguageParser::T__10);
      setState(116);
      match(EZLanguageParser::IDENTIFIER);
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == EZLanguageParser::COMMA) {
        setState(117);
        match(EZLanguageParser::COMMA);
        setState(118);
        match(EZLanguageParser::IDENTIFIER);
        setState(123);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(126);
    match(EZLanguageParser::T__11);
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 544923975680) != 0)) {
      setState(129);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(127);
        variableDeclaration();
        break;
      }

      case 2: {
        setState(128);
        functionDeclaration();
        break;
      }

      default:
        break;
      }
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
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
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0)) {
      setState(136);
      accessModifier();
    }
    setState(139);
    type();
    setState(140);
    match(EZLanguageParser::IDENTIFIER);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__13) {
      setState(141);
      match(EZLanguageParser::T__13);
      setState(142);
      expression();
    }
    setState(145);
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
    setState(147);
    match(EZLanguageParser::IDENTIFIER);
    setState(148);
    match(EZLanguageParser::T__13);
    setState(149);
    expression();
    setState(150);
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
    setState(152);
    match(EZLanguageParser::T__14);
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
    setState(155);
    match(EZLanguageParser::T__15);
    setState(156);
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
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3758096384) != 0)) {
      setState(158);
      accessModifier();
    }
    setState(161);
    type();
    setState(162);
    match(EZLanguageParser::IDENTIFIER);
    setState(163);
    match(EZLanguageParser::T__7);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 541165879296) != 0)) {
      setState(164);
      parameterList();
    }
    setState(167);
    match(EZLanguageParser::T__8);
    setState(168);
    match(EZLanguageParser::T__11);
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(169);
      statement();
      setState(174);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
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
    setState(177);
    parameter();
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EZLanguageParser::COMMA) {
      setState(178);
      match(EZLanguageParser::COMMA);
      setState(179);
      parameter();
      setState(184);
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
    setState(185);
    type();
    setState(186);
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
    setState(188);
    match(EZLanguageParser::T__16);
    setState(190);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(189);
      expression();
    }
    setState(192);
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
    setState(194);
    match(EZLanguageParser::IDENTIFIER);
    setState(195);
    match(EZLanguageParser::T__7);
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(196);
      argumentList();
    }
    setState(199);
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
    setState(201);
    match(EZLanguageParser::IDENTIFIER);
    setState(202);
    match(EZLanguageParser::T__17);
    setState(203);
    match(EZLanguageParser::IDENTIFIER);
    setState(204);
    match(EZLanguageParser::T__7);
    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(205);
      argumentList();
    }
    setState(208);
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
    setState(210);
    expression();
    setState(215);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EZLanguageParser::COMMA) {
      setState(211);
      match(EZLanguageParser::COMMA);
      setState(212);
      expression();
      setState(217);
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
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EZLanguageParser::T__18: {
        enterOuterAlt(_localctx, 1);
        setState(218);
        ifStatement();
        break;
      }

      case EZLanguageParser::T__21:
      case EZLanguageParser::T__22: {
        enterOuterAlt(_localctx, 2);
        setState(219);
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
    setState(222);
    match(EZLanguageParser::T__18);
    setState(223);
    match(EZLanguageParser::T__7);
    setState(224);
    expression();
    setState(225);
    match(EZLanguageParser::T__8);
    setState(226);
    match(EZLanguageParser::T__11);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(227);
      statement();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(EZLanguageParser::T__12);
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EZLanguageParser::T__19) {
      setState(234);
      match(EZLanguageParser::T__19);
      setState(235);
      match(EZLanguageParser::T__7);
      setState(236);
      expression();
      setState(237);
      match(EZLanguageParser::T__8);
      setState(238);
      match(EZLanguageParser::T__11);
      setState(242);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(239);
        statement();
        setState(244);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(245);
      match(EZLanguageParser::T__12);
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(261);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__20) {
      setState(252);
      match(EZLanguageParser::T__20);
      setState(253);
      match(EZLanguageParser::T__11);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(254);
        statement();
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(260);
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

EZLanguageParser::ExpressionContext* EZLanguageParser::LoopStatementContext::expression() {
  return getRuleContext<EZLanguageParser::ExpressionContext>(0);
}

std::vector<EZLanguageParser::StatementContext *> EZLanguageParser::LoopStatementContext::statement() {
  return getRuleContexts<EZLanguageParser::StatementContext>();
}

EZLanguageParser::StatementContext* EZLanguageParser::LoopStatementContext::statement(size_t i) {
  return getRuleContext<EZLanguageParser::StatementContext>(i);
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
    setState(263);
    _la = _input->LA(1);
    if (!(_la == EZLanguageParser::T__21

    || _la == EZLanguageParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(264);
    match(EZLanguageParser::T__7);
    setState(266);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131941395333376) != 0)) {
      setState(265);
      expression();
    }
    setState(268);
    match(EZLanguageParser::T__8);
    setState(269);
    match(EZLanguageParser::T__11);
    setState(273);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(270);
      statement();
      setState(275);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(276);
    match(EZLanguageParser::T__12);
   
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
  enterRule(_localctx, 40, EZLanguageParser::RuleForeachStatement);
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
    setState(278);
    match(EZLanguageParser::T__22);
    setState(279);
    match(EZLanguageParser::IDENTIFIER);
    setState(280);
    match(EZLanguageParser::T__23);
    setState(281);
    match(EZLanguageParser::IDENTIFIER);
    setState(282);
    match(EZLanguageParser::T__11);
    setState(286);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(283);
      statement();
      setState(288);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(289);
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
  enterRule(_localctx, 42, EZLanguageParser::RuleTryCatchStatement);
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
    setState(291);
    match(EZLanguageParser::T__24);
    setState(292);
    match(EZLanguageParser::T__11);
    setState(296);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 132486332645658) != 0)) {
      setState(293);
      statement();
      setState(298);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(299);
    match(EZLanguageParser::T__12);
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__25) {
      setState(300);
      match(EZLanguageParser::T__25);
      setState(301);
      match(EZLanguageParser::T__7);
      setState(302);
      match(EZLanguageParser::IDENTIFIER);
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
    setState(323);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__26) {
      setState(314);
      match(EZLanguageParser::T__26);
      setState(315);
      match(EZLanguageParser::T__11);
      setState(319);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 132486332645658) != 0)) {
        setState(316);
        statement();
        setState(321);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(322);
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
  enterRule(_localctx, 44, EZLanguageParser::RuleRunStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(EZLanguageParser::T__27);
    setState(326);
    match(EZLanguageParser::IDENTIFIER);
    setState(327);
    match(EZLanguageParser::T__4);
    setState(328);
    match(EZLanguageParser::STRING);
    setState(329);
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
  enterRule(_localctx, 46, EZLanguageParser::RuleExpressionStatement);

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
    expression();
    setState(332);
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
  enterRule(_localctx, 48, EZLanguageParser::RuleExpression);
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
    setState(334);
    primaryExpression();
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848290697216) != 0)) {
      setState(335);
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
      setState(336);
      primaryExpression();
      setState(341);
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
  enterRule(_localctx, 50, EZLanguageParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(350);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(342);
      match(EZLanguageParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(343);
      literal();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(344);
      functionCall();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(345);
      friendFunctionCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(346);
      match(EZLanguageParser::T__7);
      setState(347);
      expression();
      setState(348);
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
  enterRule(_localctx, 52, EZLanguageParser::RuleLiteral);
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
    setState(352);
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
  enterRule(_localctx, 54, EZLanguageParser::RuleAccessModifier);
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
    setState(354);
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
  enterRule(_localctx, 56, EZLanguageParser::RuleType);
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
    setState(356);
    baseType();
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EZLanguageParser::T__31) {
      setState(357);
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
  enterRule(_localctx, 58, EZLanguageParser::RuleBaseType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EZLanguageParser::T__32: {
        enterOuterAlt(_localctx, 1);
        setState(360);
        match(EZLanguageParser::T__32);
        break;
      }

      case EZLanguageParser::T__33: {
        enterOuterAlt(_localctx, 2);
        setState(361);
        match(EZLanguageParser::T__33);
        break;
      }

      case EZLanguageParser::T__34: {
        enterOuterAlt(_localctx, 3);
        setState(362);
        match(EZLanguageParser::T__34);
        break;
      }

      case EZLanguageParser::T__35: {
        enterOuterAlt(_localctx, 4);
        setState(363);
        match(EZLanguageParser::T__35);
        break;
      }

      case EZLanguageParser::T__36: {
        enterOuterAlt(_localctx, 5);
        setState(364);
        match(EZLanguageParser::T__36);
        break;
      }

      case EZLanguageParser::T__37: {
        enterOuterAlt(_localctx, 6);
        setState(365);
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
  enterRule(_localctx, 60, EZLanguageParser::RuleMapType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(EZLanguageParser::T__37);
    setState(369);
    match(EZLanguageParser::LT);
    setState(370);
    baseType();
    setState(371);
    match(EZLanguageParser::COMMA);
    setState(372);
    baseType();
    setState(373);
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
