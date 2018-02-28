
// Generated from C.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    NullPtr = 15, Tree_find_key = 16, Tree_add_key = 17, Tree_enum = 18, 
    Tree_set_key = 19, Tree_get_key = 20, Auto = 21, Break = 22, Case = 23, 
    Char = 24, Const = 25, Continue = 26, Default = 27, Do = 28, Double = 29, 
    Else = 30, Enum = 31, Extern = 32, Float = 33, For = 34, Goto = 35, 
    If = 36, Inline = 37, Int = 38, Long = 39, Register = 40, Restrict = 41, 
    Return = 42, Short = 43, Signed = 44, Sizeof = 45, Static = 46, Struct = 47, 
    Switch = 48, Typedef = 49, Union = 50, Unsigned = 51, Void = 52, Volatile = 53, 
    While = 54, Alignas = 55, Alignof = 56, Atomic = 57, Bool = 58, Complex = 59, 
    Generic = 60, Imaginary = 61, Noreturn = 62, StaticAssert = 63, ThreadLocal = 64, 
    LeftParen = 65, RightParen = 66, LeftBracket = 67, RightBracket = 68, 
    LeftBrace = 69, RightBrace = 70, Less = 71, LessEqual = 72, Greater = 73, 
    GreaterEqual = 74, LeftShift = 75, RightShift = 76, Plus = 77, PlusPlus = 78, 
    Minus = 79, MinusMinus = 80, Star = 81, Div = 82, Mod = 83, And = 84, 
    Or = 85, AndAnd = 86, OrOr = 87, Caret = 88, Not = 89, Tilde = 90, Question = 91, 
    Colon = 92, Semi = 93, Comma = 94, Assign = 95, StarAssign = 96, DivAssign = 97, 
    ModAssign = 98, PlusAssign = 99, MinusAssign = 100, LeftShiftAssign = 101, 
    RightShiftAssign = 102, AndAssign = 103, XorAssign = 104, OrAssign = 105, 
    Equal = 106, NotEqual = 107, Arrow = 108, Dot = 109, Ellipsis = 110, 
    Identifier = 111, Constant = 112, DigitSequence = 113, StringLiteral = 114, 
    ComplexDefine = 115, AsmBlock = 116, LineAfterPreprocessing = 117, LineDirective = 118, 
    PragmaDirective = 119, Whitespace = 120, Newline = 121, BlockComment = 122, 
    LineComment = 123
  };

  CLexer(antlr4::CharStream *input);
  ~CLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
