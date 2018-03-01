
// Generated from C.g4 by ANTLR 4.7.1


#include "CListener.h"
#include "CVisitor.h"

#include "CParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;

CParser::CParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CParser::~CParser() {
  delete _interpreter;
}

std::string CParser::getGrammarFileName() const {
  return "C.g4";
}

const std::vector<std::string>& CParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PrimaryExpressionContext ------------------------------------------------------------------

CParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Constant() {
  return getToken(CParser::Constant, 0);
}

std::vector<tree::TerminalNode *> CParser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::NullPtr() {
  return getToken(CParser::NullPtr, 0);
}

CParser::ExpressionContext* CParser::PrimaryExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::GenericSelectionContext* CParser::PrimaryExpressionContext::genericSelection() {
  return getRuleContext<CParser::GenericSelectionContext>(0);
}

CParser::CompoundStatementContext* CParser::PrimaryExpressionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::UnaryExpressionContext* CParser::PrimaryExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::TypeNameContext* CParser::PrimaryExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}


size_t CParser::PrimaryExpressionContext::getRuleIndex() const {
  return CParser::RulePrimaryExpression;
}

void CParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void CParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


antlrcpp::Any CParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrimaryExpressionContext* CParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, CParser::RulePrimaryExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(186);
      match(CParser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      match(CParser::Constant);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(189); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(188);
                match(CParser::StringLiteral);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(191); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(193);
      match(CParser::NullPtr);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(194);
      match(CParser::LeftParen);
      setState(195);
      expression(0);
      setState(196);
      match(CParser::RightParen);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(198);
      genericSelection();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(200);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::T__0) {
        setState(199);
        match(CParser::T__0);
      }
      setState(202);
      match(CParser::LeftParen);
      setState(203);
      compoundStatement();
      setState(204);
      match(CParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(206);
      match(CParser::T__1);
      setState(207);
      match(CParser::LeftParen);
      setState(208);
      unaryExpression();
      setState(209);
      match(CParser::Comma);
      setState(210);
      typeName();
      setState(211);
      match(CParser::RightParen);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(213);
      match(CParser::T__2);
      setState(214);
      match(CParser::LeftParen);
      setState(215);
      typeName();
      setState(216);
      match(CParser::Comma);
      setState(217);
      unaryExpression();
      setState(218);
      match(CParser::RightParen);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericSelectionContext ------------------------------------------------------------------

CParser::GenericSelectionContext::GenericSelectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::GenericSelectionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::GenericAssocListContext* CParser::GenericSelectionContext::genericAssocList() {
  return getRuleContext<CParser::GenericAssocListContext>(0);
}


size_t CParser::GenericSelectionContext::getRuleIndex() const {
  return CParser::RuleGenericSelection;
}

void CParser::GenericSelectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericSelection(this);
}

void CParser::GenericSelectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericSelection(this);
}


antlrcpp::Any CParser::GenericSelectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGenericSelection(this);
  else
    return visitor->visitChildren(this);
}

CParser::GenericSelectionContext* CParser::genericSelection() {
  GenericSelectionContext *_localctx = _tracker.createInstance<GenericSelectionContext>(_ctx, getState());
  enterRule(_localctx, 2, CParser::RuleGenericSelection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(CParser::Generic);
    setState(223);
    match(CParser::LeftParen);
    setState(224);
    assignmentExpression();
    setState(225);
    match(CParser::Comma);
    setState(226);
    genericAssocList(0);
    setState(227);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericAssocListContext ------------------------------------------------------------------

CParser::GenericAssocListContext::GenericAssocListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::GenericAssociationContext* CParser::GenericAssocListContext::genericAssociation() {
  return getRuleContext<CParser::GenericAssociationContext>(0);
}

CParser::GenericAssocListContext* CParser::GenericAssocListContext::genericAssocList() {
  return getRuleContext<CParser::GenericAssocListContext>(0);
}


size_t CParser::GenericAssocListContext::getRuleIndex() const {
  return CParser::RuleGenericAssocList;
}

void CParser::GenericAssocListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericAssocList(this);
}

void CParser::GenericAssocListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericAssocList(this);
}


antlrcpp::Any CParser::GenericAssocListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGenericAssocList(this);
  else
    return visitor->visitChildren(this);
}


CParser::GenericAssocListContext* CParser::genericAssocList() {
   return genericAssocList(0);
}

CParser::GenericAssocListContext* CParser::genericAssocList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::GenericAssocListContext *_localctx = _tracker.createInstance<GenericAssocListContext>(_ctx, parentState);
  CParser::GenericAssocListContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CParser::RuleGenericAssocList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(230);
    genericAssociation();
    _ctx->stop = _input->LT(-1);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<GenericAssocListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleGenericAssocList);
        setState(232);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(233);
        match(CParser::Comma);
        setState(234);
        genericAssociation(); 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GenericAssociationContext ------------------------------------------------------------------

CParser::GenericAssociationContext::GenericAssociationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::GenericAssociationContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::AssignmentExpressionContext* CParser::GenericAssociationContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}


size_t CParser::GenericAssociationContext::getRuleIndex() const {
  return CParser::RuleGenericAssociation;
}

void CParser::GenericAssociationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGenericAssociation(this);
}

void CParser::GenericAssociationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGenericAssociation(this);
}


antlrcpp::Any CParser::GenericAssociationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGenericAssociation(this);
  else
    return visitor->visitChildren(this);
}

CParser::GenericAssociationContext* CParser::genericAssociation() {
  GenericAssociationContext *_localctx = _tracker.createInstance<GenericAssociationContext>(_ctx, getState());
  enterRule(_localctx, 6, CParser::RuleGenericAssociation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(247);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__3:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::Char:
      case CParser::Const:
      case CParser::Double:
      case CParser::Enum:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Restrict:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Struct:
      case CParser::Union:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Volatile:
      case CParser::Atomic:
      case CParser::Bool:
      case CParser::Complex:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(240);
        typeName();
        setState(241);
        match(CParser::Colon);
        setState(242);
        assignmentExpression();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 2);
        setState(244);
        match(CParser::Default);
        setState(245);
        match(CParser::Colon);
        setState(246);
        assignmentExpression();
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

//----------------- TreeSetKeyContext ------------------------------------------------------------------

CParser::TreeSetKeyContext::TreeSetKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TreeSetKeyContext::Tree_set_key() {
  return getToken(CParser::Tree_set_key, 0);
}

tree::TerminalNode* CParser::TreeSetKeyContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::TreeSetKeyContext::StringLiteral() {
  return getToken(CParser::StringLiteral, 0);
}

CParser::UnaryExpressionContext* CParser::TreeSetKeyContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}


size_t CParser::TreeSetKeyContext::getRuleIndex() const {
  return CParser::RuleTreeSetKey;
}

void CParser::TreeSetKeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTreeSetKey(this);
}

void CParser::TreeSetKeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTreeSetKey(this);
}


antlrcpp::Any CParser::TreeSetKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTreeSetKey(this);
  else
    return visitor->visitChildren(this);
}

CParser::TreeSetKeyContext* CParser::treeSetKey() {
  TreeSetKeyContext *_localctx = _tracker.createInstance<TreeSetKeyContext>(_ctx, getState());
  enterRule(_localctx, 8, CParser::RuleTreeSetKey);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(CParser::Tree_set_key);
    setState(250);
    match(CParser::LeftParen);
    setState(252);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(251);
      match(CParser::And);
    }
    setState(254);
    match(CParser::Identifier);
    setState(255);
    match(CParser::Comma);
    setState(256);
    match(CParser::StringLiteral);
    setState(257);
    match(CParser::Comma);
    setState(259);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(258);
      match(CParser::And);
      break;
    }

    }
    setState(261);
    unaryExpression();
    setState(262);
    match(CParser::RightParen);
    setState(264);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(263);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TreeAddKeyContext ------------------------------------------------------------------

CParser::TreeAddKeyContext::TreeAddKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TreeAddKeyContext::Tree_add_key() {
  return getToken(CParser::Tree_add_key, 0);
}

std::vector<tree::TerminalNode *> CParser::TreeAddKeyContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::TreeAddKeyContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}

tree::TerminalNode* CParser::TreeAddKeyContext::StringLiteral() {
  return getToken(CParser::StringLiteral, 0);
}

tree::TerminalNode* CParser::TreeAddKeyContext::Constant() {
  return getToken(CParser::Constant, 0);
}

tree::TerminalNode* CParser::TreeAddKeyContext::NullPtr() {
  return getToken(CParser::NullPtr, 0);
}


size_t CParser::TreeAddKeyContext::getRuleIndex() const {
  return CParser::RuleTreeAddKey;
}

void CParser::TreeAddKeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTreeAddKey(this);
}

void CParser::TreeAddKeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTreeAddKey(this);
}


antlrcpp::Any CParser::TreeAddKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTreeAddKey(this);
  else
    return visitor->visitChildren(this);
}

CParser::TreeAddKeyContext* CParser::treeAddKey() {
  TreeAddKeyContext *_localctx = _tracker.createInstance<TreeAddKeyContext>(_ctx, getState());
  enterRule(_localctx, 10, CParser::RuleTreeAddKey);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(CParser::Tree_add_key);
    setState(267);
    match(CParser::LeftParen);
    setState(269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(268);
      match(CParser::And);
    }
    setState(271);
    match(CParser::Identifier);
    setState(272);
    match(CParser::Comma);
    setState(273);
    _la = _input->LA(1);
    if (!(_la == CParser::Identifier

    || _la == CParser::StringLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(274);
    match(CParser::Comma);
    setState(275);
    _la = _input->LA(1);
    if (!(_la == CParser::Identifier

    || _la == CParser::Constant)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(276);
    match(CParser::Comma);
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::And:
      case CParser::Identifier: {
        setState(278);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::And) {
          setState(277);
          match(CParser::And);
        }
        setState(280);
        match(CParser::Identifier);
        break;
      }

      case CParser::NullPtr: {
        setState(281);
        match(CParser::NullPtr);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(284);
    match(CParser::RightParen);
    setState(286);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(285);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TreeGetKeyContext ------------------------------------------------------------------

CParser::TreeGetKeyContext::TreeGetKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TreeGetKeyContext::Tree_get_key() {
  return getToken(CParser::Tree_get_key, 0);
}

std::vector<tree::TerminalNode *> CParser::TreeGetKeyContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::TreeGetKeyContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}

CParser::UnaryExpressionContext* CParser::TreeGetKeyContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::TreeGetKeyContext::StringLiteral() {
  return getToken(CParser::StringLiteral, 0);
}

std::vector<tree::TerminalNode *> CParser::TreeGetKeyContext::Constant() {
  return getTokens(CParser::Constant);
}

tree::TerminalNode* CParser::TreeGetKeyContext::Constant(size_t i) {
  return getToken(CParser::Constant, i);
}


size_t CParser::TreeGetKeyContext::getRuleIndex() const {
  return CParser::RuleTreeGetKey;
}

void CParser::TreeGetKeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTreeGetKey(this);
}

void CParser::TreeGetKeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTreeGetKey(this);
}


antlrcpp::Any CParser::TreeGetKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTreeGetKey(this);
  else
    return visitor->visitChildren(this);
}

CParser::TreeGetKeyContext* CParser::treeGetKey() {
  TreeGetKeyContext *_localctx = _tracker.createInstance<TreeGetKeyContext>(_ctx, getState());
  enterRule(_localctx, 12, CParser::RuleTreeGetKey);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(CParser::Tree_get_key);
    setState(289);
    match(CParser::LeftParen);
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(290);
      match(CParser::And);
    }
    setState(293);
    match(CParser::Identifier);
    setState(294);
    match(CParser::Comma);
    setState(295);
    match(CParser::Identifier);
    setState(296);
    match(CParser::LeftParen);
    setState(297);
    _la = _input->LA(1);
    if (!(_la == CParser::Identifier

    || _la == CParser::StringLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(298);
    match(CParser::RightParen);
    setState(299);
    match(CParser::Comma);
    setState(301);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(300);
      match(CParser::And);
      break;
    }

    }
    setState(303);
    unaryExpression();
    setState(310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Comma) {
      setState(306);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(304);
        match(CParser::Comma);
        setState(305);
        match(CParser::Constant);
        break;
      }

      }
      setState(308);
      match(CParser::Comma);
      setState(309);
      match(CParser::Constant);
    }
    setState(312);
    match(CParser::RightParen);
    setState(314);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(313);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TreeFindKeyContext ------------------------------------------------------------------

CParser::TreeFindKeyContext::TreeFindKeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TreeFindKeyContext::Tree_find_key() {
  return getToken(CParser::Tree_find_key, 0);
}

std::vector<tree::TerminalNode *> CParser::TreeFindKeyContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::TreeFindKeyContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}

tree::TerminalNode* CParser::TreeFindKeyContext::StringLiteral() {
  return getToken(CParser::StringLiteral, 0);
}

tree::TerminalNode* CParser::TreeFindKeyContext::Constant() {
  return getToken(CParser::Constant, 0);
}

tree::TerminalNode* CParser::TreeFindKeyContext::NullPtr() {
  return getToken(CParser::NullPtr, 0);
}


size_t CParser::TreeFindKeyContext::getRuleIndex() const {
  return CParser::RuleTreeFindKey;
}

void CParser::TreeFindKeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTreeFindKey(this);
}

void CParser::TreeFindKeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTreeFindKey(this);
}


antlrcpp::Any CParser::TreeFindKeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTreeFindKey(this);
  else
    return visitor->visitChildren(this);
}

CParser::TreeFindKeyContext* CParser::treeFindKey() {
  TreeFindKeyContext *_localctx = _tracker.createInstance<TreeFindKeyContext>(_ctx, getState());
  enterRule(_localctx, 14, CParser::RuleTreeFindKey);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(CParser::Tree_find_key);
    setState(317);
    match(CParser::LeftParen);
    setState(319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(318);
      match(CParser::And);
    }
    setState(321);
    match(CParser::Identifier);
    setState(322);
    match(CParser::Comma);
    setState(323);
    match(CParser::Identifier);
    setState(324);
    match(CParser::LeftParen);
    setState(325);
    _la = _input->LA(1);
    if (!(_la == CParser::Identifier

    || _la == CParser::StringLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(326);
    match(CParser::RightParen);
    setState(327);
    match(CParser::Comma);
    setState(328);
    _la = _input->LA(1);
    if (!(_la == CParser::Identifier

    || _la == CParser::Constant)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(329);
    match(CParser::Comma);
    setState(335);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::And:
      case CParser::Identifier: {
        setState(331);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::And) {
          setState(330);
          match(CParser::And);
        }
        setState(333);
        match(CParser::Identifier);
        break;
      }

      case CParser::NullPtr: {
        setState(334);
        match(CParser::NullPtr);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(337);
    match(CParser::RightParen);
    setState(339);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(338);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TreeEnumContext ------------------------------------------------------------------

CParser::TreeEnumContext::TreeEnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TreeEnumContext::Tree_enum() {
  return getToken(CParser::Tree_enum, 0);
}

std::vector<tree::TerminalNode *> CParser::TreeEnumContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::TreeEnumContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}


size_t CParser::TreeEnumContext::getRuleIndex() const {
  return CParser::RuleTreeEnum;
}

void CParser::TreeEnumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTreeEnum(this);
}

void CParser::TreeEnumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTreeEnum(this);
}


antlrcpp::Any CParser::TreeEnumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTreeEnum(this);
  else
    return visitor->visitChildren(this);
}

CParser::TreeEnumContext* CParser::treeEnum() {
  TreeEnumContext *_localctx = _tracker.createInstance<TreeEnumContext>(_ctx, getState());
  enterRule(_localctx, 16, CParser::RuleTreeEnum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    match(CParser::Tree_enum);
    setState(342);
    match(CParser::LeftParen);
    setState(344);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(343);
      match(CParser::And);
    }
    setState(346);
    match(CParser::Identifier);
    setState(347);
    match(CParser::Comma);
    setState(349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(348);
      match(CParser::And);
    }
    setState(351);
    match(CParser::Identifier);
    setState(352);
    match(CParser::Comma);
    setState(354);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::And) {
      setState(353);
      match(CParser::And);
    }
    setState(356);
    match(CParser::Identifier);
    setState(357);
    match(CParser::RightParen);
    setState(359);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(358);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

CParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::FuncCallContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::ArgumentExpressionListContext* CParser::FuncCallContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}


size_t CParser::FuncCallContext::getRuleIndex() const {
  return CParser::RuleFuncCall;
}

void CParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}

void CParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}


antlrcpp::Any CParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}

CParser::FuncCallContext* CParser::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 18, CParser::RuleFuncCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(CParser::Identifier);
    setState(362);
    match(CParser::LeftParen);
    setState(364);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::NullPtr)
      | (1ULL << CParser::Tree_find_key)
      | (1ULL << CParser::Tree_add_key)
      | (1ULL << CParser::Tree_enum)
      | (1ULL << CParser::Tree_set_key)
      | (1ULL << CParser::Tree_get_key)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
      | (1ULL << (CParser::Plus - 65))
      | (1ULL << (CParser::PlusPlus - 65))
      | (1ULL << (CParser::Minus - 65))
      | (1ULL << (CParser::MinusMinus - 65))
      | (1ULL << (CParser::Star - 65))
      | (1ULL << (CParser::And - 65))
      | (1ULL << (CParser::AndAnd - 65))
      | (1ULL << (CParser::Not - 65))
      | (1ULL << (CParser::Tilde - 65))
      | (1ULL << (CParser::Identifier - 65))
      | (1ULL << (CParser::Constant - 65))
      | (1ULL << (CParser::DigitSequence - 65))
      | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
      setState(363);
      argumentExpressionList(0);
    }
    setState(366);
    match(CParser::RightParen);
    setState(368);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(367);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

CParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PrimaryExpressionContext* CParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<CParser::PrimaryExpressionContext>(0);
}

CParser::TreeGetKeyContext* CParser::PostfixExpressionContext::treeGetKey() {
  return getRuleContext<CParser::TreeGetKeyContext>(0);
}

CParser::TreeSetKeyContext* CParser::PostfixExpressionContext::treeSetKey() {
  return getRuleContext<CParser::TreeSetKeyContext>(0);
}

CParser::TreeFindKeyContext* CParser::PostfixExpressionContext::treeFindKey() {
  return getRuleContext<CParser::TreeFindKeyContext>(0);
}

CParser::TreeAddKeyContext* CParser::PostfixExpressionContext::treeAddKey() {
  return getRuleContext<CParser::TreeAddKeyContext>(0);
}

CParser::TreeEnumContext* CParser::PostfixExpressionContext::treeEnum() {
  return getRuleContext<CParser::TreeEnumContext>(0);
}

CParser::FuncCallContext* CParser::PostfixExpressionContext::funcCall() {
  return getRuleContext<CParser::FuncCallContext>(0);
}

CParser::TypeNameContext* CParser::PostfixExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::InitializerListContext* CParser::PostfixExpressionContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

CParser::PostfixExpressionContext* CParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

CParser::ExpressionContext* CParser::PostfixExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::PostfixExpressionContext::getRuleIndex() const {
  return CParser::RulePostfixExpression;
}

void CParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void CParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


antlrcpp::Any CParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::PostfixExpressionContext* CParser::postfixExpression() {
   return postfixExpression(0);
}

CParser::PostfixExpressionContext* CParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  CParser::PostfixExpressionContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CParser::RulePostfixExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(410);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(371);
      primaryExpression();
      break;
    }

    case 2: {
      setState(372);
      treeGetKey();
      break;
    }

    case 3: {
      setState(373);
      treeSetKey();
      break;
    }

    case 4: {
      setState(374);
      treeFindKey();
      break;
    }

    case 5: {
      setState(375);
      treeAddKey();
      break;
    }

    case 6: {
      setState(376);
      treeEnum();
      break;
    }

    case 7: {
      setState(377);
      funcCall();
      break;
    }

    case 8: {
      setState(378);
      match(CParser::LeftParen);
      setState(379);
      typeName();
      setState(380);
      match(CParser::RightParen);
      setState(381);
      match(CParser::LeftBrace);
      setState(382);
      initializerList(0);
      setState(383);
      match(CParser::RightBrace);
      break;
    }

    case 9: {
      setState(385);
      match(CParser::LeftParen);
      setState(386);
      typeName();
      setState(387);
      match(CParser::RightParen);
      setState(388);
      match(CParser::LeftBrace);
      setState(389);
      initializerList(0);
      setState(390);
      match(CParser::Comma);
      setState(391);
      match(CParser::RightBrace);
      break;
    }

    case 10: {
      setState(393);
      match(CParser::T__0);
      setState(394);
      match(CParser::LeftParen);
      setState(395);
      typeName();
      setState(396);
      match(CParser::RightParen);
      setState(397);
      match(CParser::LeftBrace);
      setState(398);
      initializerList(0);
      setState(399);
      match(CParser::RightBrace);
      break;
    }

    case 11: {
      setState(401);
      match(CParser::T__0);
      setState(402);
      match(CParser::LeftParen);
      setState(403);
      typeName();
      setState(404);
      match(CParser::RightParen);
      setState(405);
      match(CParser::LeftBrace);
      setState(406);
      initializerList(0);
      setState(407);
      match(CParser::Comma);
      setState(408);
      match(CParser::RightBrace);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(429);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(427);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(412);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(413);
          match(CParser::LeftBracket);
          setState(414);
          expression(0);
          setState(415);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(417);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(418);
          match(CParser::Dot);
          setState(419);
          match(CParser::Identifier);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(420);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(421);
          match(CParser::Arrow);
          setState(422);
          match(CParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(423);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(424);
          match(CParser::PlusPlus);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(425);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(426);
          match(CParser::MinusMinus);
          break;
        }

        } 
      }
      setState(431);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

CParser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ArgumentExpressionListContext* CParser::ArgumentExpressionListContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}


size_t CParser::ArgumentExpressionListContext::getRuleIndex() const {
  return CParser::RuleArgumentExpressionList;
}

void CParser::ArgumentExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentExpressionList(this);
}

void CParser::ArgumentExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentExpressionList(this);
}


antlrcpp::Any CParser::ArgumentExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitArgumentExpressionList(this);
  else
    return visitor->visitChildren(this);
}


CParser::ArgumentExpressionListContext* CParser::argumentExpressionList() {
   return argumentExpressionList(0);
}

CParser::ArgumentExpressionListContext* CParser::argumentExpressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, parentState);
  CParser::ArgumentExpressionListContext *previousContext = _localctx;
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, CParser::RuleArgumentExpressionList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(433);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(440);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(435);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(436);
        match(CParser::Comma);
        setState(437);
        assignmentExpression(); 
      }
      setState(442);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

CParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PostfixExpressionContext* CParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::UnaryOperatorContext* CParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<CParser::UnaryOperatorContext>(0);
}

CParser::CastExpressionContext* CParser::UnaryExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::TypeNameContext* CParser::UnaryExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::UnaryExpressionContext::getRuleIndex() const {
  return CParser::RuleUnaryExpression;
}

void CParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void CParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


antlrcpp::Any CParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnaryExpressionContext* CParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 24, CParser::RuleUnaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(465);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(443);
      postfixExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(444);
      match(CParser::PlusPlus);
      setState(445);
      unaryExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(446);
      match(CParser::MinusMinus);
      setState(447);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(448);
      unaryOperator();
      setState(449);
      castExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(451);
      match(CParser::Sizeof);
      setState(452);
      unaryExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(453);
      match(CParser::Sizeof);
      setState(454);
      match(CParser::LeftParen);
      setState(455);
      typeName();
      setState(456);
      match(CParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(458);
      match(CParser::Alignof);
      setState(459);
      match(CParser::LeftParen);
      setState(460);
      typeName();
      setState(461);
      match(CParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(463);
      match(CParser::AndAnd);
      setState(464);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

CParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::UnaryOperatorContext::getRuleIndex() const {
  return CParser::RuleUnaryOperator;
}

void CParser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void CParser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}


antlrcpp::Any CParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnaryOperatorContext* CParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 26, CParser::RuleUnaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    _la = _input->LA(1);
    if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 77)) & ((1ULL << (CParser::Plus - 77))
      | (1ULL << (CParser::Minus - 77))
      | (1ULL << (CParser::Star - 77))
      | (1ULL << (CParser::And - 77))
      | (1ULL << (CParser::Not - 77))
      | (1ULL << (CParser::Tilde - 77)))) != 0))) {
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

//----------------- CastExpressionContext ------------------------------------------------------------------

CParser::CastExpressionContext::CastExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::UnaryExpressionContext* CParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::TypeNameContext* CParser::CastExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::CastExpressionContext* CParser::CastExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}


size_t CParser::CastExpressionContext::getRuleIndex() const {
  return CParser::RuleCastExpression;
}

void CParser::CastExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastExpression(this);
}

void CParser::CastExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastExpression(this);
}


antlrcpp::Any CParser::CastExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCastExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::CastExpressionContext* CParser::castExpression() {
  CastExpressionContext *_localctx = _tracker.createInstance<CastExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CParser::RuleCastExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(482);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(469);
      unaryExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(470);
      match(CParser::LeftParen);
      setState(471);
      typeName();
      setState(472);
      match(CParser::RightParen);
      setState(473);
      castExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(475);
      match(CParser::T__0);
      setState(476);
      match(CParser::LeftParen);
      setState(477);
      typeName();
      setState(478);
      match(CParser::RightParen);
      setState(479);
      castExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(481);
      match(CParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

CParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::CastExpressionContext* CParser::MultiplicativeExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::MultiplicativeExpressionContext* CParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(0);
}


size_t CParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return CParser::RuleMultiplicativeExpression;
}

void CParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void CParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any CParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  CParser::MultiplicativeExpressionContext *previousContext = _localctx;
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, CParser::RuleMultiplicativeExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(485);
    castExpression();
    _ctx->stop = _input->LT(-1);
    setState(498);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(496);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(487);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(488);
          match(CParser::Star);
          setState(489);
          castExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(490);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(491);
          match(CParser::Div);
          setState(492);
          castExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(493);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(494);
          match(CParser::Mod);
          setState(495);
          castExpression();
          break;
        }

        } 
      }
      setState(500);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

CParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::MultiplicativeExpressionContext* CParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(0);
}

CParser::AdditiveExpressionContext* CParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<CParser::AdditiveExpressionContext>(0);
}


size_t CParser::AdditiveExpressionContext::getRuleIndex() const {
  return CParser::RuleAdditiveExpression;
}

void CParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void CParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any CParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::AdditiveExpressionContext* CParser::additiveExpression() {
   return additiveExpression(0);
}

CParser::AdditiveExpressionContext* CParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  CParser::AdditiveExpressionContext *previousContext = _localctx;
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, CParser::RuleAdditiveExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(502);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(512);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(510);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(504);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(505);
          match(CParser::Plus);
          setState(506);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(507);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(508);
          match(CParser::Minus);
          setState(509);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(514);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ShiftExpressionContext ------------------------------------------------------------------

CParser::ShiftExpressionContext::ShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AdditiveExpressionContext* CParser::ShiftExpressionContext::additiveExpression() {
  return getRuleContext<CParser::AdditiveExpressionContext>(0);
}

CParser::ShiftExpressionContext* CParser::ShiftExpressionContext::shiftExpression() {
  return getRuleContext<CParser::ShiftExpressionContext>(0);
}


size_t CParser::ShiftExpressionContext::getRuleIndex() const {
  return CParser::RuleShiftExpression;
}

void CParser::ShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftExpression(this);
}

void CParser::ShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftExpression(this);
}


antlrcpp::Any CParser::ShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ShiftExpressionContext* CParser::shiftExpression() {
   return shiftExpression(0);
}

CParser::ShiftExpressionContext* CParser::shiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ShiftExpressionContext *_localctx = _tracker.createInstance<ShiftExpressionContext>(_ctx, parentState);
  CParser::ShiftExpressionContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CParser::RuleShiftExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(516);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(526);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(524);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(518);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(519);
          match(CParser::LeftShift);
          setState(520);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(521);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(522);
          match(CParser::RightShift);
          setState(523);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(528);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

CParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ShiftExpressionContext* CParser::RelationalExpressionContext::shiftExpression() {
  return getRuleContext<CParser::ShiftExpressionContext>(0);
}

CParser::RelationalExpressionContext* CParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<CParser::RelationalExpressionContext>(0);
}


size_t CParser::RelationalExpressionContext::getRuleIndex() const {
  return CParser::RuleRelationalExpression;
}

void CParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void CParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


antlrcpp::Any CParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::RelationalExpressionContext* CParser::relationalExpression() {
   return relationalExpression(0);
}

CParser::RelationalExpressionContext* CParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  CParser::RelationalExpressionContext *previousContext = _localctx;
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CParser::RuleRelationalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(530);
    shiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(546);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(544);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(532);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(533);
          match(CParser::Less);
          setState(534);
          shiftExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(535);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(536);
          match(CParser::Greater);
          setState(537);
          shiftExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(538);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(539);
          match(CParser::LessEqual);
          setState(540);
          shiftExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(541);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(542);
          match(CParser::GreaterEqual);
          setState(543);
          shiftExpression(0);
          break;
        }

        } 
      }
      setState(548);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

CParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::RelationalExpressionContext* CParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<CParser::RelationalExpressionContext>(0);
}

CParser::EqualityExpressionContext* CParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<CParser::EqualityExpressionContext>(0);
}


size_t CParser::EqualityExpressionContext::getRuleIndex() const {
  return CParser::RuleEqualityExpression;
}

void CParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void CParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


antlrcpp::Any CParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::EqualityExpressionContext* CParser::equalityExpression() {
   return equalityExpression(0);
}

CParser::EqualityExpressionContext* CParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  CParser::EqualityExpressionContext *previousContext = _localctx;
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, CParser::RuleEqualityExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(550);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(560);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(558);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(552);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(553);
          match(CParser::Equal);
          setState(554);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(555);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(556);
          match(CParser::NotEqual);
          setState(557);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(562);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndExpressionContext ------------------------------------------------------------------

CParser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EqualityExpressionContext* CParser::AndExpressionContext::equalityExpression() {
  return getRuleContext<CParser::EqualityExpressionContext>(0);
}

CParser::AndExpressionContext* CParser::AndExpressionContext::andExpression() {
  return getRuleContext<CParser::AndExpressionContext>(0);
}


size_t CParser::AndExpressionContext::getRuleIndex() const {
  return CParser::RuleAndExpression;
}

void CParser::AndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpression(this);
}

void CParser::AndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpression(this);
}


antlrcpp::Any CParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::AndExpressionContext* CParser::andExpression() {
   return andExpression(0);
}

CParser::AndExpressionContext* CParser::andExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, parentState);
  CParser::AndExpressionContext *previousContext = _localctx;
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, CParser::RuleAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(564);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(571);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(566);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(567);
        match(CParser::And);
        setState(568);
        equalityExpression(0); 
      }
      setState(573);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

CParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AndExpressionContext* CParser::ExclusiveOrExpressionContext::andExpression() {
  return getRuleContext<CParser::AndExpressionContext>(0);
}

CParser::ExclusiveOrExpressionContext* CParser::ExclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(0);
}


size_t CParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleExclusiveOrExpression;
}

void CParser::ExclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusiveOrExpression(this);
}

void CParser::ExclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusiveOrExpression(this);
}


antlrcpp::Any CParser::ExclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression() {
   return exclusiveOrExpression(0);
}

CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, parentState);
  CParser::ExclusiveOrExpressionContext *previousContext = _localctx;
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, CParser::RuleExclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(575);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(582);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(577);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(578);
        match(CParser::Caret);
        setState(579);
        andExpression(0); 
      }
      setState(584);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InclusiveOrExpressionContext ------------------------------------------------------------------

CParser::InclusiveOrExpressionContext::InclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(0);
}

CParser::InclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::inclusiveOrExpression() {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(0);
}


size_t CParser::InclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleInclusiveOrExpression;
}

void CParser::InclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclusiveOrExpression(this);
}

void CParser::InclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclusiveOrExpression(this);
}


antlrcpp::Any CParser::InclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression() {
   return inclusiveOrExpression(0);
}

CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InclusiveOrExpressionContext *_localctx = _tracker.createInstance<InclusiveOrExpressionContext>(_ctx, parentState);
  CParser::InclusiveOrExpressionContext *previousContext = _localctx;
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CParser::RuleInclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(586);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(593);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(588);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(589);
        match(CParser::Or);
        setState(590);
        exclusiveOrExpression(0); 
      }
      setState(595);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

CParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InclusiveOrExpressionContext* CParser::LogicalAndExpressionContext::inclusiveOrExpression() {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(0);
}

CParser::LogicalAndExpressionContext* CParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<CParser::LogicalAndExpressionContext>(0);
}


size_t CParser::LogicalAndExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalAndExpression;
}

void CParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void CParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


antlrcpp::Any CParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::LogicalAndExpressionContext* CParser::logicalAndExpression() {
   return logicalAndExpression(0);
}

CParser::LogicalAndExpressionContext* CParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  CParser::LogicalAndExpressionContext *previousContext = _localctx;
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CParser::RuleLogicalAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(597);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(604);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(599);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(600);
        match(CParser::AndAnd);
        setState(601);
        inclusiveOrExpression(0); 
      }
      setState(606);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

CParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalAndExpressionContext* CParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<CParser::LogicalAndExpressionContext>(0);
}

CParser::LogicalOrExpressionContext* CParser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}


size_t CParser::LogicalOrExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalOrExpression;
}

void CParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void CParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}


antlrcpp::Any CParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::LogicalOrExpressionContext* CParser::logicalOrExpression() {
   return logicalOrExpression(0);
}

CParser::LogicalOrExpressionContext* CParser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  CParser::LogicalOrExpressionContext *previousContext = _localctx;
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, CParser::RuleLogicalOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(608);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(615);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(610);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(611);
        match(CParser::OrOr);
        setState(612);
        logicalAndExpression(0); 
      }
      setState(617);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

CParser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalOrExpressionContext* CParser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}

CParser::ExpressionContext* CParser::ConditionalExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ConditionalExpressionContext* CParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConditionalExpressionContext::getRuleIndex() const {
  return CParser::RuleConditionalExpression;
}

void CParser::ConditionalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalExpression(this);
}

void CParser::ConditionalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalExpression(this);
}


antlrcpp::Any CParser::ConditionalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitConditionalExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ConditionalExpressionContext* CParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 50, CParser::RuleConditionalExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(618);
    logicalOrExpression(0);
    setState(624);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      setState(619);
      match(CParser::Question);
      setState(620);
      expression(0);
      setState(621);
      match(CParser::Colon);
      setState(622);
      conditionalExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

CParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::AssignmentOperatorContext* CParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<CParser::AssignmentOperatorContext>(0);
}

CParser::AssignmentExpressionContext* CParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::AssignmentExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}


size_t CParser::AssignmentExpressionContext::getRuleIndex() const {
  return CParser::RuleAssignmentExpression;
}

void CParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void CParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any CParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::AssignmentExpressionContext* CParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 52, CParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(632);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(626);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(627);
      unaryExpression();
      setState(628);
      assignmentOperator();
      setState(629);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(631);
      match(CParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

CParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::AssignmentOperatorContext::getRuleIndex() const {
  return CParser::RuleAssignmentOperator;
}

void CParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void CParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any CParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AssignmentOperatorContext* CParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 54, CParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    _la = _input->LA(1);
    if (!(((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & ((1ULL << (CParser::Assign - 95))
      | (1ULL << (CParser::StarAssign - 95))
      | (1ULL << (CParser::DivAssign - 95))
      | (1ULL << (CParser::ModAssign - 95))
      | (1ULL << (CParser::PlusAssign - 95))
      | (1ULL << (CParser::MinusAssign - 95))
      | (1ULL << (CParser::LeftShiftAssign - 95))
      | (1ULL << (CParser::RightShiftAssign - 95))
      | (1ULL << (CParser::AndAssign - 95))
      | (1ULL << (CParser::XorAssign - 95))
      | (1ULL << (CParser::OrAssign - 95)))) != 0))) {
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

//----------------- ExpressionContext ------------------------------------------------------------------

CParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ExpressionContext* CParser::ExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ExpressionContext::getRuleIndex() const {
  return CParser::RuleExpression;
}

void CParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any CParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ExpressionContext* CParser::expression() {
   return expression(0);
}

CParser::ExpressionContext* CParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  CParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(637);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(644);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(639);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(640);
        match(CParser::Comma);
        setState(641);
        assignmentExpression(); 
      }
      setState(646);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstantExpressionContext ------------------------------------------------------------------

CParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::ConstantExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConstantExpressionContext::getRuleIndex() const {
  return CParser::RuleConstantExpression;
}

void CParser::ConstantExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpression(this);
}

void CParser::ConstantExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpression(this);
}


antlrcpp::Any CParser::ConstantExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitConstantExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ConstantExpressionContext* CParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 58, CParser::RuleConstantExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(647);
    conditionalExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

CParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::InitDeclaratorListContext* CParser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}

CParser::StaticAssertDeclarationContext* CParser::DeclarationContext::staticAssertDeclaration() {
  return getRuleContext<CParser::StaticAssertDeclarationContext>(0);
}


size_t CParser::DeclarationContext::getRuleIndex() const {
  return CParser::RuleDeclaration;
}

void CParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void CParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any CParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationContext* CParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 60, CParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(657);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(649);
      declarationSpecifiers();
      setState(650);
      initDeclaratorList(0);
      setState(651);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(653);
      declarationSpecifiers();
      setState(654);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(656);
      staticAssertDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

CParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers;
}

void CParser::DeclarationSpecifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers(this);
}

void CParser::DeclarationSpecifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers(this);
}


antlrcpp::Any CParser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifiersContext* CParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 62, CParser::RuleDeclarationSpecifiers);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(660); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(659);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(662); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiers2Context ------------------------------------------------------------------

CParser::DeclarationSpecifiers2Context::DeclarationSpecifiers2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifiers2Context::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifiers2Context::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifiers2Context::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers2;
}

void CParser::DeclarationSpecifiers2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers2(this);
}

void CParser::DeclarationSpecifiers2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers2(this);
}


antlrcpp::Any CParser::DeclarationSpecifiers2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers2(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifiers2Context* CParser::declarationSpecifiers2() {
  DeclarationSpecifiers2Context *_localctx = _tracker.createInstance<DeclarationSpecifiers2Context>(_ctx, getState());
  enterRule(_localctx, 64, CParser::RuleDeclarationSpecifiers2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(665); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(664);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(667); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

CParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StorageClassSpecifierContext* CParser::DeclarationSpecifierContext::storageClassSpecifier() {
  return getRuleContext<CParser::StorageClassSpecifierContext>(0);
}

CParser::TypeSpecifierContext* CParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::TypeQualifierContext* CParser::DeclarationSpecifierContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}

CParser::FunctionSpecifierContext* CParser::DeclarationSpecifierContext::functionSpecifier() {
  return getRuleContext<CParser::FunctionSpecifierContext>(0);
}

CParser::AlignmentSpecifierContext* CParser::DeclarationSpecifierContext::alignmentSpecifier() {
  return getRuleContext<CParser::AlignmentSpecifierContext>(0);
}


size_t CParser::DeclarationSpecifierContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifier;
}

void CParser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void CParser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}


antlrcpp::Any CParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifierContext* CParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 66, CParser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(674);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(669);
      storageClassSpecifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(670);
      typeSpecifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(671);
      typeQualifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(672);
      functionSpecifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(673);
      alignmentSpecifier();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

CParser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InitDeclaratorContext* CParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContext<CParser::InitDeclaratorContext>(0);
}

CParser::InitDeclaratorListContext* CParser::InitDeclaratorListContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::InitDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleInitDeclaratorList;
}

void CParser::InitDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclaratorList(this);
}

void CParser::InitDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclaratorList(this);
}


antlrcpp::Any CParser::InitDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::InitDeclaratorListContext* CParser::initDeclaratorList() {
   return initDeclaratorList(0);
}

CParser::InitDeclaratorListContext* CParser::initDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, parentState);
  CParser::InitDeclaratorListContext *previousContext = _localctx;
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, CParser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(677);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(684);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(679);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(680);
        match(CParser::Comma);
        setState(681);
        initDeclarator(); 
      }
      setState(686);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

CParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::InitDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::InitializerContext* CParser::InitDeclaratorContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}


size_t CParser::InitDeclaratorContext::getRuleIndex() const {
  return CParser::RuleInitDeclarator;
}

void CParser::InitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclarator(this);
}

void CParser::InitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclarator(this);
}


antlrcpp::Any CParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitDeclaratorContext* CParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 70, CParser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(692);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(687);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(688);
      declarator();
      setState(689);
      match(CParser::Assign);
      setState(690);
      initializer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StorageClassSpecifierContext ------------------------------------------------------------------

CParser::StorageClassSpecifierContext::StorageClassSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::StorageClassSpecifierContext::getRuleIndex() const {
  return CParser::RuleStorageClassSpecifier;
}

void CParser::StorageClassSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStorageClassSpecifier(this);
}

void CParser::StorageClassSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStorageClassSpecifier(this);
}


antlrcpp::Any CParser::StorageClassSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStorageClassSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::StorageClassSpecifierContext* CParser::storageClassSpecifier() {
  StorageClassSpecifierContext *_localctx = _tracker.createInstance<StorageClassSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 72, CParser::RuleStorageClassSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(694);
    _la = _input->LA(1);
    if (!(((((_la - 21) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 21)) & ((1ULL << (CParser::Auto - 21))
      | (1ULL << (CParser::Extern - 21))
      | (1ULL << (CParser::Register - 21))
      | (1ULL << (CParser::Static - 21))
      | (1ULL << (CParser::Typedef - 21))
      | (1ULL << (CParser::ThreadLocal - 21)))) != 0))) {
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

//----------------- TypeSpecifierContext ------------------------------------------------------------------

CParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AtomicTypeSpecifierContext* CParser::TypeSpecifierContext::atomicTypeSpecifier() {
  return getRuleContext<CParser::AtomicTypeSpecifierContext>(0);
}

CParser::StructOrUnionSpecifierContext* CParser::TypeSpecifierContext::structOrUnionSpecifier() {
  return getRuleContext<CParser::StructOrUnionSpecifierContext>(0);
}

CParser::EnumSpecifierContext* CParser::TypeSpecifierContext::enumSpecifier() {
  return getRuleContext<CParser::EnumSpecifierContext>(0);
}

CParser::TypedefNameContext* CParser::TypeSpecifierContext::typedefName() {
  return getRuleContext<CParser::TypedefNameContext>(0);
}

CParser::ConstantExpressionContext* CParser::TypeSpecifierContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::TypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleTypeSpecifier;
}

void CParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void CParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any CParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeSpecifierContext* CParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 74, CParser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(710);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__3:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::Char:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Bool:
      case CParser::Complex: {
        enterOuterAlt(_localctx, 1);
        setState(696);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__3)
          | (1ULL << CParser::T__4)
          | (1ULL << CParser::T__5)
          | (1ULL << CParser::Char)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void)
          | (1ULL << CParser::Bool)
          | (1ULL << CParser::Complex))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(697);
        match(CParser::T__0);
        setState(698);
        match(CParser::LeftParen);
        setState(699);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__3)
          | (1ULL << CParser::T__4)
          | (1ULL << CParser::T__5))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(700);
        match(CParser::RightParen);
        break;
      }

      case CParser::Atomic: {
        enterOuterAlt(_localctx, 3);
        setState(701);
        atomicTypeSpecifier();
        break;
      }

      case CParser::Struct:
      case CParser::Union: {
        enterOuterAlt(_localctx, 4);
        setState(702);
        structOrUnionSpecifier();
        break;
      }

      case CParser::Enum: {
        enterOuterAlt(_localctx, 5);
        setState(703);
        enumSpecifier();
        break;
      }

      case CParser::Identifier: {
        enterOuterAlt(_localctx, 6);
        setState(704);
        typedefName();
        break;
      }

      case CParser::T__6: {
        enterOuterAlt(_localctx, 7);
        setState(705);
        match(CParser::T__6);
        setState(706);
        match(CParser::LeftParen);
        setState(707);
        constantExpression();
        setState(708);
        match(CParser::RightParen);
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

//----------------- StructOrUnionSpecifierContext ------------------------------------------------------------------

CParser::StructOrUnionSpecifierContext::StructOrUnionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructOrUnionContext* CParser::StructOrUnionSpecifierContext::structOrUnion() {
  return getRuleContext<CParser::StructOrUnionContext>(0);
}

CParser::StructDeclarationListContext* CParser::StructOrUnionSpecifierContext::structDeclarationList() {
  return getRuleContext<CParser::StructDeclarationListContext>(0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::StructOrUnionSpecifierContext::getRuleIndex() const {
  return CParser::RuleStructOrUnionSpecifier;
}

void CParser::StructOrUnionSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructOrUnionSpecifier(this);
}

void CParser::StructOrUnionSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructOrUnionSpecifier(this);
}


antlrcpp::Any CParser::StructOrUnionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructOrUnionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructOrUnionSpecifierContext* CParser::structOrUnionSpecifier() {
  StructOrUnionSpecifierContext *_localctx = _tracker.createInstance<StructOrUnionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 76, CParser::RuleStructOrUnionSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(723);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(712);
      structOrUnion();
      setState(714);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(713);
        match(CParser::Identifier);
      }
      setState(716);
      match(CParser::LeftBrace);
      setState(717);
      structDeclarationList(0);
      setState(718);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(720);
      structOrUnion();
      setState(721);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructOrUnionContext ------------------------------------------------------------------

CParser::StructOrUnionContext::StructOrUnionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::StructOrUnionContext::getRuleIndex() const {
  return CParser::RuleStructOrUnion;
}

void CParser::StructOrUnionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructOrUnion(this);
}

void CParser::StructOrUnionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructOrUnion(this);
}


antlrcpp::Any CParser::StructOrUnionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructOrUnion(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructOrUnionContext* CParser::structOrUnion() {
  StructOrUnionContext *_localctx = _tracker.createInstance<StructOrUnionContext>(_ctx, getState());
  enterRule(_localctx, 78, CParser::RuleStructOrUnion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    _la = _input->LA(1);
    if (!(_la == CParser::Struct

    || _la == CParser::Union)) {
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

//----------------- StructDeclarationListContext ------------------------------------------------------------------

CParser::StructDeclarationListContext::StructDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructDeclarationContext* CParser::StructDeclarationListContext::structDeclaration() {
  return getRuleContext<CParser::StructDeclarationContext>(0);
}

CParser::StructDeclarationListContext* CParser::StructDeclarationListContext::structDeclarationList() {
  return getRuleContext<CParser::StructDeclarationListContext>(0);
}


size_t CParser::StructDeclarationListContext::getRuleIndex() const {
  return CParser::RuleStructDeclarationList;
}

void CParser::StructDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarationList(this);
}

void CParser::StructDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarationList(this);
}


antlrcpp::Any CParser::StructDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


CParser::StructDeclarationListContext* CParser::structDeclarationList() {
   return structDeclarationList(0);
}

CParser::StructDeclarationListContext* CParser::structDeclarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::StructDeclarationListContext *_localctx = _tracker.createInstance<StructDeclarationListContext>(_ctx, parentState);
  CParser::StructDeclarationListContext *previousContext = _localctx;
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, CParser::RuleStructDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(728);
    structDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(734);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclarationList);
        setState(730);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(731);
        structDeclaration(); 
      }
      setState(736);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

CParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::StructDeclarationContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::StructDeclaratorListContext* CParser::StructDeclarationContext::structDeclaratorList() {
  return getRuleContext<CParser::StructDeclaratorListContext>(0);
}

CParser::StaticAssertDeclarationContext* CParser::StructDeclarationContext::staticAssertDeclaration() {
  return getRuleContext<CParser::StaticAssertDeclarationContext>(0);
}


size_t CParser::StructDeclarationContext::getRuleIndex() const {
  return CParser::RuleStructDeclaration;
}

void CParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void CParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}


antlrcpp::Any CParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclarationContext* CParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 82, CParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(744);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__3:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::Char:
      case CParser::Const:
      case CParser::Double:
      case CParser::Enum:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Restrict:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Struct:
      case CParser::Union:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Volatile:
      case CParser::Atomic:
      case CParser::Bool:
      case CParser::Complex:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(737);
        specifierQualifierList();
        setState(739);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 65) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
          | (1ULL << (CParser::Star - 65))
          | (1ULL << (CParser::Caret - 65))
          | (1ULL << (CParser::Colon - 65))
          | (1ULL << (CParser::Identifier - 65)))) != 0)) {
          setState(738);
          structDeclaratorList(0);
        }
        setState(741);
        match(CParser::Semi);
        break;
      }

      case CParser::StaticAssert: {
        enterOuterAlt(_localctx, 2);
        setState(743);
        staticAssertDeclaration();
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

//----------------- SpecifierQualifierListContext ------------------------------------------------------------------

CParser::SpecifierQualifierListContext::SpecifierQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeSpecifierContext* CParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::SpecifierQualifierListContext* CParser::SpecifierQualifierListContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::TypeQualifierContext* CParser::SpecifierQualifierListContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}


size_t CParser::SpecifierQualifierListContext::getRuleIndex() const {
  return CParser::RuleSpecifierQualifierList;
}

void CParser::SpecifierQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecifierQualifierList(this);
}

void CParser::SpecifierQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecifierQualifierList(this);
}


antlrcpp::Any CParser::SpecifierQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSpecifierQualifierList(this);
  else
    return visitor->visitChildren(this);
}

CParser::SpecifierQualifierListContext* CParser::specifierQualifierList() {
  SpecifierQualifierListContext *_localctx = _tracker.createInstance<SpecifierQualifierListContext>(_ctx, getState());
  enterRule(_localctx, 84, CParser::RuleSpecifierQualifierList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(754);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(746);
      typeSpecifier();
      setState(748);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
      case 1: {
        setState(747);
        specifierQualifierList();
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(750);
      typeQualifier();
      setState(752);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
      case 1: {
        setState(751);
        specifierQualifierList();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclaratorListContext ------------------------------------------------------------------

CParser::StructDeclaratorListContext::StructDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructDeclaratorContext* CParser::StructDeclaratorListContext::structDeclarator() {
  return getRuleContext<CParser::StructDeclaratorContext>(0);
}

CParser::StructDeclaratorListContext* CParser::StructDeclaratorListContext::structDeclaratorList() {
  return getRuleContext<CParser::StructDeclaratorListContext>(0);
}


size_t CParser::StructDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleStructDeclaratorList;
}

void CParser::StructDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaratorList(this);
}

void CParser::StructDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaratorList(this);
}


antlrcpp::Any CParser::StructDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::StructDeclaratorListContext* CParser::structDeclaratorList() {
   return structDeclaratorList(0);
}

CParser::StructDeclaratorListContext* CParser::structDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::StructDeclaratorListContext *_localctx = _tracker.createInstance<StructDeclaratorListContext>(_ctx, parentState);
  CParser::StructDeclaratorListContext *previousContext = _localctx;
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, CParser::RuleStructDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(757);
    structDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(764);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclaratorList);
        setState(759);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(760);
        match(CParser::Comma);
        setState(761);
        structDeclarator(); 
      }
      setState(766);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructDeclaratorContext ------------------------------------------------------------------

CParser::StructDeclaratorContext::StructDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::StructDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::ConstantExpressionContext* CParser::StructDeclaratorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::StructDeclaratorContext::getRuleIndex() const {
  return CParser::RuleStructDeclarator;
}

void CParser::StructDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarator(this);
}

void CParser::StructDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarator(this);
}


antlrcpp::Any CParser::StructDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclaratorContext* CParser::structDeclarator() {
  StructDeclaratorContext *_localctx = _tracker.createInstance<StructDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 88, CParser::RuleStructDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(773);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(767);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(769);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::Caret - 65))
        | (1ULL << (CParser::Identifier - 65)))) != 0)) {
        setState(768);
        declarator();
      }
      setState(771);
      match(CParser::Colon);
      setState(772);
      constantExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumSpecifierContext ------------------------------------------------------------------

CParser::EnumSpecifierContext::EnumSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EnumeratorListContext* CParser::EnumSpecifierContext::enumeratorList() {
  return getRuleContext<CParser::EnumeratorListContext>(0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::EnumSpecifierContext::getRuleIndex() const {
  return CParser::RuleEnumSpecifier;
}

void CParser::EnumSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumSpecifier(this);
}

void CParser::EnumSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumSpecifier(this);
}


antlrcpp::Any CParser::EnumSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumSpecifierContext* CParser::enumSpecifier() {
  EnumSpecifierContext *_localctx = _tracker.createInstance<EnumSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 90, CParser::RuleEnumSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(794);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(775);
      match(CParser::Enum);
      setState(777);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(776);
        match(CParser::Identifier);
      }
      setState(779);
      match(CParser::LeftBrace);
      setState(780);
      enumeratorList(0);
      setState(781);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(783);
      match(CParser::Enum);
      setState(785);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(784);
        match(CParser::Identifier);
      }
      setState(787);
      match(CParser::LeftBrace);
      setState(788);
      enumeratorList(0);
      setState(789);
      match(CParser::Comma);
      setState(790);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(792);
      match(CParser::Enum);
      setState(793);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumeratorListContext ------------------------------------------------------------------

CParser::EnumeratorListContext::EnumeratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EnumeratorContext* CParser::EnumeratorListContext::enumerator() {
  return getRuleContext<CParser::EnumeratorContext>(0);
}

CParser::EnumeratorListContext* CParser::EnumeratorListContext::enumeratorList() {
  return getRuleContext<CParser::EnumeratorListContext>(0);
}


size_t CParser::EnumeratorListContext::getRuleIndex() const {
  return CParser::RuleEnumeratorList;
}

void CParser::EnumeratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeratorList(this);
}

void CParser::EnumeratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeratorList(this);
}


antlrcpp::Any CParser::EnumeratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumeratorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::EnumeratorListContext* CParser::enumeratorList() {
   return enumeratorList(0);
}

CParser::EnumeratorListContext* CParser::enumeratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::EnumeratorListContext *_localctx = _tracker.createInstance<EnumeratorListContext>(_ctx, parentState);
  CParser::EnumeratorListContext *previousContext = _localctx;
  size_t startState = 92;
  enterRecursionRule(_localctx, 92, CParser::RuleEnumeratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(797);
    enumerator();
    _ctx->stop = _input->LT(-1);
    setState(804);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EnumeratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEnumeratorList);
        setState(799);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(800);
        match(CParser::Comma);
        setState(801);
        enumerator(); 
      }
      setState(806);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EnumeratorContext ------------------------------------------------------------------

CParser::EnumeratorContext::EnumeratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EnumerationConstantContext* CParser::EnumeratorContext::enumerationConstant() {
  return getRuleContext<CParser::EnumerationConstantContext>(0);
}

CParser::ConstantExpressionContext* CParser::EnumeratorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::EnumeratorContext::getRuleIndex() const {
  return CParser::RuleEnumerator;
}

void CParser::EnumeratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerator(this);
}

void CParser::EnumeratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerator(this);
}


antlrcpp::Any CParser::EnumeratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumerator(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumeratorContext* CParser::enumerator() {
  EnumeratorContext *_localctx = _tracker.createInstance<EnumeratorContext>(_ctx, getState());
  enterRule(_localctx, 94, CParser::RuleEnumerator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(812);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(807);
      enumerationConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(808);
      enumerationConstant();
      setState(809);
      match(CParser::Assign);
      setState(810);
      constantExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationConstantContext ------------------------------------------------------------------

CParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::EnumerationConstantContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::EnumerationConstantContext::getRuleIndex() const {
  return CParser::RuleEnumerationConstant;
}

void CParser::EnumerationConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerationConstant(this);
}

void CParser::EnumerationConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerationConstant(this);
}


antlrcpp::Any CParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumerationConstantContext* CParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 96, CParser::RuleEnumerationConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(814);
    match(CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicTypeSpecifierContext ------------------------------------------------------------------

CParser::AtomicTypeSpecifierContext::AtomicTypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::AtomicTypeSpecifierContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}


size_t CParser::AtomicTypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleAtomicTypeSpecifier;
}

void CParser::AtomicTypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomicTypeSpecifier(this);
}

void CParser::AtomicTypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomicTypeSpecifier(this);
}


antlrcpp::Any CParser::AtomicTypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAtomicTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::AtomicTypeSpecifierContext* CParser::atomicTypeSpecifier() {
  AtomicTypeSpecifierContext *_localctx = _tracker.createInstance<AtomicTypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 98, CParser::RuleAtomicTypeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(816);
    match(CParser::Atomic);
    setState(817);
    match(CParser::LeftParen);
    setState(818);
    typeName();
    setState(819);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierContext ------------------------------------------------------------------

CParser::TypeQualifierContext::TypeQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::TypeQualifierContext::getRuleIndex() const {
  return CParser::RuleTypeQualifier;
}

void CParser::TypeQualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifier(this);
}

void CParser::TypeQualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifier(this);
}


antlrcpp::Any CParser::TypeQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeQualifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeQualifierContext* CParser::typeQualifier() {
  TypeQualifierContext *_localctx = _tracker.createInstance<TypeQualifierContext>(_ctx, getState());
  enterRule(_localctx, 100, CParser::RuleTypeQualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(821);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Const)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Atomic))) != 0))) {
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

//----------------- FunctionSpecifierContext ------------------------------------------------------------------

CParser::FunctionSpecifierContext::FunctionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::GccAttributeSpecifierContext* CParser::FunctionSpecifierContext::gccAttributeSpecifier() {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(0);
}

tree::TerminalNode* CParser::FunctionSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::FunctionSpecifierContext::getRuleIndex() const {
  return CParser::RuleFunctionSpecifier;
}

void CParser::FunctionSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionSpecifier(this);
}

void CParser::FunctionSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionSpecifier(this);
}


antlrcpp::Any CParser::FunctionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionSpecifierContext* CParser::functionSpecifier() {
  FunctionSpecifierContext *_localctx = _tracker.createInstance<FunctionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 102, CParser::RuleFunctionSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(829);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__7:
      case CParser::T__8:
      case CParser::Inline:
      case CParser::Noreturn: {
        enterOuterAlt(_localctx, 1);
        setState(823);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__7)
          | (1ULL << CParser::T__8)
          | (1ULL << CParser::Inline)
          | (1ULL << CParser::Noreturn))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(824);
        gccAttributeSpecifier();
        break;
      }

      case CParser::T__9: {
        enterOuterAlt(_localctx, 3);
        setState(825);
        match(CParser::T__9);
        setState(826);
        match(CParser::LeftParen);
        setState(827);
        match(CParser::Identifier);
        setState(828);
        match(CParser::RightParen);
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

//----------------- AlignmentSpecifierContext ------------------------------------------------------------------

CParser::AlignmentSpecifierContext::AlignmentSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::AlignmentSpecifierContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::ConstantExpressionContext* CParser::AlignmentSpecifierContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::AlignmentSpecifierContext::getRuleIndex() const {
  return CParser::RuleAlignmentSpecifier;
}

void CParser::AlignmentSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlignmentSpecifier(this);
}

void CParser::AlignmentSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlignmentSpecifier(this);
}


antlrcpp::Any CParser::AlignmentSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAlignmentSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::AlignmentSpecifierContext* CParser::alignmentSpecifier() {
  AlignmentSpecifierContext *_localctx = _tracker.createInstance<AlignmentSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 104, CParser::RuleAlignmentSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(841);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(831);
      match(CParser::Alignas);
      setState(832);
      match(CParser::LeftParen);
      setState(833);
      typeName();
      setState(834);
      match(CParser::RightParen);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(836);
      match(CParser::Alignas);
      setState(837);
      match(CParser::LeftParen);
      setState(838);
      constantExpression();
      setState(839);
      match(CParser::RightParen);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

CParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DirectDeclaratorContext* CParser::DeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::PointerContext* CParser::DeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

std::vector<CParser::GccDeclaratorExtensionContext *> CParser::DeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<CParser::GccDeclaratorExtensionContext>();
}

CParser::GccDeclaratorExtensionContext* CParser::DeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<CParser::GccDeclaratorExtensionContext>(i);
}


size_t CParser::DeclaratorContext::getRuleIndex() const {
  return CParser::RuleDeclarator;
}

void CParser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void CParser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}


antlrcpp::Any CParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclaratorContext* CParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 106, CParser::RuleDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(844);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Star

    || _la == CParser::Caret) {
      setState(843);
      pointer();
    }
    setState(846);
    directDeclarator(0);
    setState(850);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(847);
        gccDeclaratorExtension(); 
      }
      setState(852);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectDeclaratorContext ------------------------------------------------------------------

CParser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DirectDeclaratorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::DeclaratorContext* CParser::DirectDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}

CParser::DirectDeclaratorContext* CParser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::TypeQualifierListContext* CParser::DirectDeclaratorContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::AssignmentExpressionContext* CParser::DirectDeclaratorContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ParameterTypeListContext* CParser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::IdentifierListContext* CParser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}


size_t CParser::DirectDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectDeclarator;
}

void CParser::DirectDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectDeclarator(this);
}

void CParser::DirectDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectDeclarator(this);
}


antlrcpp::Any CParser::DirectDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectDeclarator(this);
  else
    return visitor->visitChildren(this);
}


CParser::DirectDeclaratorContext* CParser::directDeclarator() {
   return directDeclarator(0);
}

CParser::DirectDeclaratorContext* CParser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  CParser::DirectDeclaratorContext *previousContext = _localctx;
  size_t startState = 108;
  enterRecursionRule(_localctx, 108, CParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(862);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      setState(854);
      match(CParser::Identifier);
      break;
    }

    case 2: {
      setState(855);
      match(CParser::LeftParen);
      setState(856);
      declarator();
      setState(857);
      match(CParser::RightParen);
      break;
    }

    case 3: {
      setState(859);
      match(CParser::Identifier);
      setState(860);
      match(CParser::Colon);
      setState(861);
      match(CParser::DigitSequence);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(909);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(907);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(864);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(865);
          match(CParser::LeftBracket);
          setState(867);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(866);
            typeQualifierList(0);
          }
          setState(870);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::NullPtr)
            | (1ULL << CParser::Tree_find_key)
            | (1ULL << CParser::Tree_add_key)
            | (1ULL << CParser::Tree_enum)
            | (1ULL << CParser::Tree_set_key)
            | (1ULL << CParser::Tree_get_key)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
            | (1ULL << (CParser::Plus - 65))
            | (1ULL << (CParser::PlusPlus - 65))
            | (1ULL << (CParser::Minus - 65))
            | (1ULL << (CParser::MinusMinus - 65))
            | (1ULL << (CParser::Star - 65))
            | (1ULL << (CParser::And - 65))
            | (1ULL << (CParser::AndAnd - 65))
            | (1ULL << (CParser::Not - 65))
            | (1ULL << (CParser::Tilde - 65))
            | (1ULL << (CParser::Identifier - 65))
            | (1ULL << (CParser::Constant - 65))
            | (1ULL << (CParser::DigitSequence - 65))
            | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
            setState(869);
            assignmentExpression();
          }
          setState(872);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(873);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(874);
          match(CParser::LeftBracket);
          setState(875);
          match(CParser::Static);
          setState(877);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(876);
            typeQualifierList(0);
          }
          setState(879);
          assignmentExpression();
          setState(880);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(882);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(883);
          match(CParser::LeftBracket);
          setState(884);
          typeQualifierList(0);
          setState(885);
          match(CParser::Static);
          setState(886);
          assignmentExpression();
          setState(887);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(889);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(890);
          match(CParser::LeftBracket);
          setState(892);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(891);
            typeQualifierList(0);
          }
          setState(894);
          match(CParser::Star);
          setState(895);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(896);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(897);
          match(CParser::LeftParen);
          setState(898);
          parameterTypeList();
          setState(899);
          match(CParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(901);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(902);
          match(CParser::LeftParen);
          setState(904);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Identifier) {
            setState(903);
            identifierList(0);
          }
          setState(906);
          match(CParser::RightParen);
          break;
        }

        } 
      }
      setState(911);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- GccDeclaratorExtensionContext ------------------------------------------------------------------

CParser::GccDeclaratorExtensionContext::GccDeclaratorExtensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::GccDeclaratorExtensionContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::GccDeclaratorExtensionContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}

CParser::GccAttributeSpecifierContext* CParser::GccDeclaratorExtensionContext::gccAttributeSpecifier() {
  return getRuleContext<CParser::GccAttributeSpecifierContext>(0);
}


size_t CParser::GccDeclaratorExtensionContext::getRuleIndex() const {
  return CParser::RuleGccDeclaratorExtension;
}

void CParser::GccDeclaratorExtensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccDeclaratorExtension(this);
}

void CParser::GccDeclaratorExtensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccDeclaratorExtension(this);
}


antlrcpp::Any CParser::GccDeclaratorExtensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccDeclaratorExtension(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccDeclaratorExtensionContext* CParser::gccDeclaratorExtension() {
  GccDeclaratorExtensionContext *_localctx = _tracker.createInstance<GccDeclaratorExtensionContext>(_ctx, getState());
  enterRule(_localctx, 110, CParser::RuleGccDeclaratorExtension);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(921);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__10: {
        enterOuterAlt(_localctx, 1);
        setState(912);
        match(CParser::T__10);
        setState(913);
        match(CParser::LeftParen);
        setState(915); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(914);
          match(CParser::StringLiteral);
          setState(917); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == CParser::StringLiteral);
        setState(919);
        match(CParser::RightParen);
        break;
      }

      case CParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(920);
        gccAttributeSpecifier();
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

//----------------- GccAttributeSpecifierContext ------------------------------------------------------------------

CParser::GccAttributeSpecifierContext::GccAttributeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::GccAttributeListContext* CParser::GccAttributeSpecifierContext::gccAttributeList() {
  return getRuleContext<CParser::GccAttributeListContext>(0);
}


size_t CParser::GccAttributeSpecifierContext::getRuleIndex() const {
  return CParser::RuleGccAttributeSpecifier;
}

void CParser::GccAttributeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttributeSpecifier(this);
}

void CParser::GccAttributeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttributeSpecifier(this);
}


antlrcpp::Any CParser::GccAttributeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccAttributeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccAttributeSpecifierContext* CParser::gccAttributeSpecifier() {
  GccAttributeSpecifierContext *_localctx = _tracker.createInstance<GccAttributeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 112, CParser::RuleGccAttributeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(923);
    match(CParser::T__11);
    setState(924);
    match(CParser::LeftParen);
    setState(925);
    match(CParser::LeftParen);
    setState(926);
    gccAttributeList();
    setState(927);
    match(CParser::RightParen);
    setState(928);
    match(CParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeListContext ------------------------------------------------------------------

CParser::GccAttributeListContext::GccAttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::GccAttributeContext *> CParser::GccAttributeListContext::gccAttribute() {
  return getRuleContexts<CParser::GccAttributeContext>();
}

CParser::GccAttributeContext* CParser::GccAttributeListContext::gccAttribute(size_t i) {
  return getRuleContext<CParser::GccAttributeContext>(i);
}


size_t CParser::GccAttributeListContext::getRuleIndex() const {
  return CParser::RuleGccAttributeList;
}

void CParser::GccAttributeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttributeList(this);
}

void CParser::GccAttributeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttributeList(this);
}


antlrcpp::Any CParser::GccAttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccAttributeList(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccAttributeListContext* CParser::gccAttributeList() {
  GccAttributeListContext *_localctx = _tracker.createInstance<GccAttributeListContext>(_ctx, getState());
  enterRule(_localctx, 114, CParser::RuleGccAttributeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(939);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(930);
      gccAttribute();
      setState(935);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::Comma) {
        setState(931);
        match(CParser::Comma);
        setState(932);
        gccAttribute();
        setState(937);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GccAttributeContext ------------------------------------------------------------------

CParser::GccAttributeContext::GccAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ArgumentExpressionListContext* CParser::GccAttributeContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}


size_t CParser::GccAttributeContext::getRuleIndex() const {
  return CParser::RuleGccAttribute;
}

void CParser::GccAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGccAttribute(this);
}

void CParser::GccAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGccAttribute(this);
}


antlrcpp::Any CParser::GccAttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGccAttribute(this);
  else
    return visitor->visitChildren(this);
}

CParser::GccAttributeContext* CParser::gccAttribute() {
  GccAttributeContext *_localctx = _tracker.createInstance<GccAttributeContext>(_ctx, getState());
  enterRule(_localctx, 116, CParser::RuleGccAttribute);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(950);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__1:
      case CParser::T__2:
      case CParser::T__3:
      case CParser::T__4:
      case CParser::T__5:
      case CParser::T__6:
      case CParser::T__7:
      case CParser::T__8:
      case CParser::T__9:
      case CParser::T__10:
      case CParser::T__11:
      case CParser::T__12:
      case CParser::T__13:
      case CParser::NullPtr:
      case CParser::Tree_find_key:
      case CParser::Tree_add_key:
      case CParser::Tree_enum:
      case CParser::Tree_set_key:
      case CParser::Tree_get_key:
      case CParser::Auto:
      case CParser::Break:
      case CParser::Case:
      case CParser::Char:
      case CParser::Const:
      case CParser::Continue:
      case CParser::Default:
      case CParser::Do:
      case CParser::Double:
      case CParser::Else:
      case CParser::Enum:
      case CParser::Extern:
      case CParser::Float:
      case CParser::For:
      case CParser::Goto:
      case CParser::If:
      case CParser::Inline:
      case CParser::Int:
      case CParser::Long:
      case CParser::Register:
      case CParser::Restrict:
      case CParser::Return:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Sizeof:
      case CParser::Static:
      case CParser::Struct:
      case CParser::Switch:
      case CParser::Typedef:
      case CParser::Union:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Volatile:
      case CParser::While:
      case CParser::Alignas:
      case CParser::Alignof:
      case CParser::Atomic:
      case CParser::Bool:
      case CParser::Complex:
      case CParser::Generic:
      case CParser::Imaginary:
      case CParser::Noreturn:
      case CParser::StaticAssert:
      case CParser::ThreadLocal:
      case CParser::LeftBracket:
      case CParser::RightBracket:
      case CParser::LeftBrace:
      case CParser::RightBrace:
      case CParser::Less:
      case CParser::LessEqual:
      case CParser::Greater:
      case CParser::GreaterEqual:
      case CParser::LeftShift:
      case CParser::RightShift:
      case CParser::Plus:
      case CParser::PlusPlus:
      case CParser::Minus:
      case CParser::MinusMinus:
      case CParser::Star:
      case CParser::Div:
      case CParser::Mod:
      case CParser::And:
      case CParser::Or:
      case CParser::AndAnd:
      case CParser::OrOr:
      case CParser::Caret:
      case CParser::Not:
      case CParser::Tilde:
      case CParser::Question:
      case CParser::Colon:
      case CParser::Semi:
      case CParser::Assign:
      case CParser::StarAssign:
      case CParser::DivAssign:
      case CParser::ModAssign:
      case CParser::PlusAssign:
      case CParser::MinusAssign:
      case CParser::LeftShiftAssign:
      case CParser::RightShiftAssign:
      case CParser::AndAssign:
      case CParser::XorAssign:
      case CParser::OrAssign:
      case CParser::Equal:
      case CParser::NotEqual:
      case CParser::Arrow:
      case CParser::Dot:
      case CParser::Ellipsis:
      case CParser::Identifier:
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral:
      case CParser::ComplexDefine:
      case CParser::AsmBlock:
      case CParser::LineAfterPreprocessing:
      case CParser::LineDirective:
      case CParser::PragmaDirective:
      case CParser::Whitespace:
      case CParser::Newline:
      case CParser::BlockComment:
      case CParser::LineComment: {
        enterOuterAlt(_localctx, 1);
        setState(941);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (((((_la - 65) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
          | (1ULL << (CParser::RightParen - 65))
          | (1ULL << (CParser::Comma - 65)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(947);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftParen) {
          setState(942);
          match(CParser::LeftParen);
          setState(944);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::NullPtr)
            | (1ULL << CParser::Tree_find_key)
            | (1ULL << CParser::Tree_add_key)
            | (1ULL << CParser::Tree_enum)
            | (1ULL << CParser::Tree_set_key)
            | (1ULL << CParser::Tree_get_key)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
            | (1ULL << (CParser::Plus - 65))
            | (1ULL << (CParser::PlusPlus - 65))
            | (1ULL << (CParser::Minus - 65))
            | (1ULL << (CParser::MinusMinus - 65))
            | (1ULL << (CParser::Star - 65))
            | (1ULL << (CParser::And - 65))
            | (1ULL << (CParser::AndAnd - 65))
            | (1ULL << (CParser::Not - 65))
            | (1ULL << (CParser::Tilde - 65))
            | (1ULL << (CParser::Identifier - 65))
            | (1ULL << (CParser::Constant - 65))
            | (1ULL << (CParser::DigitSequence - 65))
            | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
            setState(943);
            argumentExpressionList(0);
          }
          setState(946);
          match(CParser::RightParen);
        }
        break;
      }

      case CParser::RightParen:
      case CParser::Comma: {
        enterOuterAlt(_localctx, 2);

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

//----------------- NestedParenthesesBlockContext ------------------------------------------------------------------

CParser::NestedParenthesesBlockContext::NestedParenthesesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::NestedParenthesesBlockContext *> CParser::NestedParenthesesBlockContext::nestedParenthesesBlock() {
  return getRuleContexts<CParser::NestedParenthesesBlockContext>();
}

CParser::NestedParenthesesBlockContext* CParser::NestedParenthesesBlockContext::nestedParenthesesBlock(size_t i) {
  return getRuleContext<CParser::NestedParenthesesBlockContext>(i);
}


size_t CParser::NestedParenthesesBlockContext::getRuleIndex() const {
  return CParser::RuleNestedParenthesesBlock;
}

void CParser::NestedParenthesesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedParenthesesBlock(this);
}

void CParser::NestedParenthesesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedParenthesesBlock(this);
}


antlrcpp::Any CParser::NestedParenthesesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitNestedParenthesesBlock(this);
  else
    return visitor->visitChildren(this);
}

CParser::NestedParenthesesBlockContext* CParser::nestedParenthesesBlock() {
  NestedParenthesesBlockContext *_localctx = _tracker.createInstance<NestedParenthesesBlockContext>(_ctx, getState());
  enterRule(_localctx, 118, CParser::RuleNestedParenthesesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(959);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::NullPtr)
      | (1ULL << CParser::Tree_find_key)
      | (1ULL << CParser::Tree_add_key)
      | (1ULL << CParser::Tree_enum)
      | (1ULL << CParser::Tree_set_key)
      | (1ULL << CParser::Tree_get_key)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Do)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Else)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::Goto)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::While)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Generic)
      | (1ULL << CParser::Imaginary)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::ThreadLocal - 64))
      | (1ULL << (CParser::LeftParen - 64))
      | (1ULL << (CParser::LeftBracket - 64))
      | (1ULL << (CParser::RightBracket - 64))
      | (1ULL << (CParser::LeftBrace - 64))
      | (1ULL << (CParser::RightBrace - 64))
      | (1ULL << (CParser::Less - 64))
      | (1ULL << (CParser::LessEqual - 64))
      | (1ULL << (CParser::Greater - 64))
      | (1ULL << (CParser::GreaterEqual - 64))
      | (1ULL << (CParser::LeftShift - 64))
      | (1ULL << (CParser::RightShift - 64))
      | (1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::PlusPlus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::MinusMinus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::Div - 64))
      | (1ULL << (CParser::Mod - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Or - 64))
      | (1ULL << (CParser::AndAnd - 64))
      | (1ULL << (CParser::OrOr - 64))
      | (1ULL << (CParser::Caret - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Question - 64))
      | (1ULL << (CParser::Colon - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Comma - 64))
      | (1ULL << (CParser::Assign - 64))
      | (1ULL << (CParser::StarAssign - 64))
      | (1ULL << (CParser::DivAssign - 64))
      | (1ULL << (CParser::ModAssign - 64))
      | (1ULL << (CParser::PlusAssign - 64))
      | (1ULL << (CParser::MinusAssign - 64))
      | (1ULL << (CParser::LeftShiftAssign - 64))
      | (1ULL << (CParser::RightShiftAssign - 64))
      | (1ULL << (CParser::AndAssign - 64))
      | (1ULL << (CParser::XorAssign - 64))
      | (1ULL << (CParser::OrAssign - 64))
      | (1ULL << (CParser::Equal - 64))
      | (1ULL << (CParser::NotEqual - 64))
      | (1ULL << (CParser::Arrow - 64))
      | (1ULL << (CParser::Dot - 64))
      | (1ULL << (CParser::Ellipsis - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64))
      | (1ULL << (CParser::ComplexDefine - 64))
      | (1ULL << (CParser::AsmBlock - 64))
      | (1ULL << (CParser::LineAfterPreprocessing - 64))
      | (1ULL << (CParser::LineDirective - 64))
      | (1ULL << (CParser::PragmaDirective - 64))
      | (1ULL << (CParser::Whitespace - 64))
      | (1ULL << (CParser::Newline - 64))
      | (1ULL << (CParser::BlockComment - 64))
      | (1ULL << (CParser::LineComment - 64)))) != 0)) {
      setState(957);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CParser::T__0:
        case CParser::T__1:
        case CParser::T__2:
        case CParser::T__3:
        case CParser::T__4:
        case CParser::T__5:
        case CParser::T__6:
        case CParser::T__7:
        case CParser::T__8:
        case CParser::T__9:
        case CParser::T__10:
        case CParser::T__11:
        case CParser::T__12:
        case CParser::T__13:
        case CParser::NullPtr:
        case CParser::Tree_find_key:
        case CParser::Tree_add_key:
        case CParser::Tree_enum:
        case CParser::Tree_set_key:
        case CParser::Tree_get_key:
        case CParser::Auto:
        case CParser::Break:
        case CParser::Case:
        case CParser::Char:
        case CParser::Const:
        case CParser::Continue:
        case CParser::Default:
        case CParser::Do:
        case CParser::Double:
        case CParser::Else:
        case CParser::Enum:
        case CParser::Extern:
        case CParser::Float:
        case CParser::For:
        case CParser::Goto:
        case CParser::If:
        case CParser::Inline:
        case CParser::Int:
        case CParser::Long:
        case CParser::Register:
        case CParser::Restrict:
        case CParser::Return:
        case CParser::Short:
        case CParser::Signed:
        case CParser::Sizeof:
        case CParser::Static:
        case CParser::Struct:
        case CParser::Switch:
        case CParser::Typedef:
        case CParser::Union:
        case CParser::Unsigned:
        case CParser::Void:
        case CParser::Volatile:
        case CParser::While:
        case CParser::Alignas:
        case CParser::Alignof:
        case CParser::Atomic:
        case CParser::Bool:
        case CParser::Complex:
        case CParser::Generic:
        case CParser::Imaginary:
        case CParser::Noreturn:
        case CParser::StaticAssert:
        case CParser::ThreadLocal:
        case CParser::LeftBracket:
        case CParser::RightBracket:
        case CParser::LeftBrace:
        case CParser::RightBrace:
        case CParser::Less:
        case CParser::LessEqual:
        case CParser::Greater:
        case CParser::GreaterEqual:
        case CParser::LeftShift:
        case CParser::RightShift:
        case CParser::Plus:
        case CParser::PlusPlus:
        case CParser::Minus:
        case CParser::MinusMinus:
        case CParser::Star:
        case CParser::Div:
        case CParser::Mod:
        case CParser::And:
        case CParser::Or:
        case CParser::AndAnd:
        case CParser::OrOr:
        case CParser::Caret:
        case CParser::Not:
        case CParser::Tilde:
        case CParser::Question:
        case CParser::Colon:
        case CParser::Semi:
        case CParser::Comma:
        case CParser::Assign:
        case CParser::StarAssign:
        case CParser::DivAssign:
        case CParser::ModAssign:
        case CParser::PlusAssign:
        case CParser::MinusAssign:
        case CParser::LeftShiftAssign:
        case CParser::RightShiftAssign:
        case CParser::AndAssign:
        case CParser::XorAssign:
        case CParser::OrAssign:
        case CParser::Equal:
        case CParser::NotEqual:
        case CParser::Arrow:
        case CParser::Dot:
        case CParser::Ellipsis:
        case CParser::Identifier:
        case CParser::Constant:
        case CParser::DigitSequence:
        case CParser::StringLiteral:
        case CParser::ComplexDefine:
        case CParser::AsmBlock:
        case CParser::LineAfterPreprocessing:
        case CParser::LineDirective:
        case CParser::PragmaDirective:
        case CParser::Whitespace:
        case CParser::Newline:
        case CParser::BlockComment:
        case CParser::LineComment: {
          setState(952);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == CParser::LeftParen

          || _la == CParser::RightParen)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case CParser::LeftParen: {
          setState(953);
          match(CParser::LeftParen);
          setState(954);
          nestedParenthesesBlock();
          setState(955);
          match(CParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(961);
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

//----------------- PointerContext ------------------------------------------------------------------

CParser::PointerContext::PointerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeQualifierListContext* CParser::PointerContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::PointerContext* CParser::PointerContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}


size_t CParser::PointerContext::getRuleIndex() const {
  return CParser::RulePointer;
}

void CParser::PointerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointer(this);
}

void CParser::PointerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointer(this);
}


antlrcpp::Any CParser::PointerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPointer(this);
  else
    return visitor->visitChildren(this);
}

CParser::PointerContext* CParser::pointer() {
  PointerContext *_localctx = _tracker.createInstance<PointerContext>(_ctx, getState());
  enterRule(_localctx, 120, CParser::RulePointer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(980);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(962);
      match(CParser::Star);
      setState(964);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
      case 1: {
        setState(963);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(966);
      match(CParser::Star);
      setState(968);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(967);
        typeQualifierList(0);
      }
      setState(970);
      pointer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(971);
      match(CParser::Caret);
      setState(973);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
      case 1: {
        setState(972);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(975);
      match(CParser::Caret);
      setState(977);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(976);
        typeQualifierList(0);
      }
      setState(979);
      pointer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierListContext ------------------------------------------------------------------

CParser::TypeQualifierListContext::TypeQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeQualifierContext* CParser::TypeQualifierListContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}

CParser::TypeQualifierListContext* CParser::TypeQualifierListContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}


size_t CParser::TypeQualifierListContext::getRuleIndex() const {
  return CParser::RuleTypeQualifierList;
}

void CParser::TypeQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifierList(this);
}

void CParser::TypeQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifierList(this);
}


antlrcpp::Any CParser::TypeQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeQualifierList(this);
  else
    return visitor->visitChildren(this);
}


CParser::TypeQualifierListContext* CParser::typeQualifierList() {
   return typeQualifierList(0);
}

CParser::TypeQualifierListContext* CParser::typeQualifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TypeQualifierListContext *_localctx = _tracker.createInstance<TypeQualifierListContext>(_ctx, parentState);
  CParser::TypeQualifierListContext *previousContext = _localctx;
  size_t startState = 122;
  enterRecursionRule(_localctx, 122, CParser::RuleTypeQualifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(983);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(989);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(985);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(986);
        typeQualifier(); 
      }
      setState(991);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

CParser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterListContext* CParser::ParameterTypeListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}


size_t CParser::ParameterTypeListContext::getRuleIndex() const {
  return CParser::RuleParameterTypeList;
}

void CParser::ParameterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterTypeList(this);
}

void CParser::ParameterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterTypeList(this);
}


antlrcpp::Any CParser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterTypeListContext* CParser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 124, CParser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(997);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(992);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(993);
      parameterList(0);
      setState(994);
      match(CParser::Comma);
      setState(995);
      match(CParser::Ellipsis);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

CParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterDeclarationContext* CParser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<CParser::ParameterDeclarationContext>(0);
}

CParser::ParameterListContext* CParser::ParameterListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}


size_t CParser::ParameterListContext::getRuleIndex() const {
  return CParser::RuleParameterList;
}

void CParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void CParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any CParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}


CParser::ParameterListContext* CParser::parameterList() {
   return parameterList(0);
}

CParser::ParameterListContext* CParser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  CParser::ParameterListContext *previousContext = _localctx;
  size_t startState = 126;
  enterRecursionRule(_localctx, 126, CParser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1000);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(1007);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(1002);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1003);
        match(CParser::Comma);
        setState(1004);
        parameterDeclaration(); 
      }
      setState(1009);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

CParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclaratorContext* CParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::DeclarationSpecifiers2Context* CParser::ParameterDeclarationContext::declarationSpecifiers2() {
  return getRuleContext<CParser::DeclarationSpecifiers2Context>(0);
}

CParser::AbstractDeclaratorContext* CParser::ParameterDeclarationContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}


size_t CParser::ParameterDeclarationContext::getRuleIndex() const {
  return CParser::RuleParameterDeclaration;
}

void CParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void CParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any CParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterDeclarationContext* CParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 128, CParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1017);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1010);
      declarationSpecifiers();
      setState(1011);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1013);
      declarationSpecifiers2();
      setState(1015);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
      case 1: {
        setState(1014);
        abstractDeclarator();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

CParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IdentifierListContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::IdentifierListContext* CParser::IdentifierListContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}


size_t CParser::IdentifierListContext::getRuleIndex() const {
  return CParser::RuleIdentifierList;
}

void CParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void CParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any CParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}


CParser::IdentifierListContext* CParser::identifierList() {
   return identifierList(0);
}

CParser::IdentifierListContext* CParser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  CParser::IdentifierListContext *previousContext = _localctx;
  size_t startState = 130;
  enterRecursionRule(_localctx, 130, CParser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1020);
    match(CParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(1027);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(1022);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1023);
        match(CParser::Comma);
        setState(1024);
        match(CParser::Identifier); 
      }
      setState(1029);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

CParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::TypeNameContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::AbstractDeclaratorContext* CParser::TypeNameContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}


size_t CParser::TypeNameContext::getRuleIndex() const {
  return CParser::RuleTypeName;
}

void CParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void CParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}


antlrcpp::Any CParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeNameContext* CParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 132, CParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1030);
    specifierQualifierList();
    setState(1032);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
      | (1ULL << (CParser::LeftBracket - 65))
      | (1ULL << (CParser::Star - 65))
      | (1ULL << (CParser::Caret - 65)))) != 0)) {
      setState(1031);
      abstractDeclarator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbstractDeclaratorContext ------------------------------------------------------------------

CParser::AbstractDeclaratorContext::AbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PointerContext* CParser::AbstractDeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::AbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(0);
}

std::vector<CParser::GccDeclaratorExtensionContext *> CParser::AbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<CParser::GccDeclaratorExtensionContext>();
}

CParser::GccDeclaratorExtensionContext* CParser::AbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<CParser::GccDeclaratorExtensionContext>(i);
}


size_t CParser::AbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleAbstractDeclarator;
}

void CParser::AbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbstractDeclarator(this);
}

void CParser::AbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbstractDeclarator(this);
}


antlrcpp::Any CParser::AbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AbstractDeclaratorContext* CParser::abstractDeclarator() {
  AbstractDeclaratorContext *_localctx = _tracker.createInstance<AbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 134, CParser::RuleAbstractDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1045);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1034);
      pointer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1036);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Star

      || _la == CParser::Caret) {
        setState(1035);
        pointer();
      }
      setState(1038);
      directAbstractDeclarator(0);
      setState(1042);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1039);
          gccDeclaratorExtension(); 
        }
        setState(1044);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectAbstractDeclaratorContext ------------------------------------------------------------------

CParser::DirectAbstractDeclaratorContext::DirectAbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}

std::vector<CParser::GccDeclaratorExtensionContext *> CParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension() {
  return getRuleContexts<CParser::GccDeclaratorExtensionContext>();
}

CParser::GccDeclaratorExtensionContext* CParser::DirectAbstractDeclaratorContext::gccDeclaratorExtension(size_t i) {
  return getRuleContext<CParser::GccDeclaratorExtensionContext>(i);
}

CParser::TypeQualifierListContext* CParser::DirectAbstractDeclaratorContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::AssignmentExpressionContext* CParser::DirectAbstractDeclaratorContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ParameterTypeListContext* CParser::DirectAbstractDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(0);
}


size_t CParser::DirectAbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectAbstractDeclarator;
}

void CParser::DirectAbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectAbstractDeclarator(this);
}

void CParser::DirectAbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectAbstractDeclarator(this);
}


antlrcpp::Any CParser::DirectAbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}


CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator() {
   return directAbstractDeclarator(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectAbstractDeclaratorContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(_ctx, parentState);
  CParser::DirectAbstractDeclaratorContext *previousContext = _localctx;
  size_t startState = 136;
  enterRecursionRule(_localctx, 136, CParser::RuleDirectAbstractDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1093);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
    case 1: {
      setState(1048);
      match(CParser::LeftParen);
      setState(1049);
      abstractDeclarator();
      setState(1050);
      match(CParser::RightParen);
      setState(1054);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1051);
          gccDeclaratorExtension(); 
        }
        setState(1056);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx);
      }
      break;
    }

    case 2: {
      setState(1057);
      match(CParser::LeftBracket);
      setState(1059);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(1058);
        typeQualifierList(0);
      }
      setState(1062);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1061);
        assignmentExpression();
      }
      setState(1064);
      match(CParser::RightBracket);
      break;
    }

    case 3: {
      setState(1065);
      match(CParser::LeftBracket);
      setState(1066);
      match(CParser::Static);
      setState(1068);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Const)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Atomic))) != 0)) {
        setState(1067);
        typeQualifierList(0);
      }
      setState(1070);
      assignmentExpression();
      setState(1071);
      match(CParser::RightBracket);
      break;
    }

    case 4: {
      setState(1073);
      match(CParser::LeftBracket);
      setState(1074);
      typeQualifierList(0);
      setState(1075);
      match(CParser::Static);
      setState(1076);
      assignmentExpression();
      setState(1077);
      match(CParser::RightBracket);
      break;
    }

    case 5: {
      setState(1079);
      match(CParser::LeftBracket);
      setState(1080);
      match(CParser::Star);
      setState(1081);
      match(CParser::RightBracket);
      break;
    }

    case 6: {
      setState(1082);
      match(CParser::LeftParen);
      setState(1084);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::T__4)
        | (1ULL << CParser::T__5)
        | (1ULL << CParser::T__6)
        | (1ULL << CParser::T__7)
        | (1ULL << CParser::T__8)
        | (1ULL << CParser::T__9)
        | (1ULL << CParser::T__11)
        | (1ULL << CParser::Auto)
        | (1ULL << CParser::Char)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Enum)
        | (1ULL << CParser::Extern)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Inline)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Register)
        | (1ULL << CParser::Restrict)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Static)
        | (1ULL << CParser::Struct)
        | (1ULL << CParser::Typedef)
        | (1ULL << CParser::Union)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void)
        | (1ULL << CParser::Volatile)
        | (1ULL << CParser::Alignas)
        | (1ULL << CParser::Atomic)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Complex)
        | (1ULL << CParser::Noreturn))) != 0) || _la == CParser::ThreadLocal

      || _la == CParser::Identifier) {
        setState(1083);
        parameterTypeList();
      }
      setState(1086);
      match(CParser::RightParen);
      setState(1090);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1087);
          gccDeclaratorExtension(); 
        }
        setState(1092);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx);
      }
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1138);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1136);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1095);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1096);
          match(CParser::LeftBracket);
          setState(1098);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(1097);
            typeQualifierList(0);
          }
          setState(1101);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::NullPtr)
            | (1ULL << CParser::Tree_find_key)
            | (1ULL << CParser::Tree_add_key)
            | (1ULL << CParser::Tree_enum)
            | (1ULL << CParser::Tree_set_key)
            | (1ULL << CParser::Tree_get_key)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::Alignof)
            | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
            | (1ULL << (CParser::Plus - 65))
            | (1ULL << (CParser::PlusPlus - 65))
            | (1ULL << (CParser::Minus - 65))
            | (1ULL << (CParser::MinusMinus - 65))
            | (1ULL << (CParser::Star - 65))
            | (1ULL << (CParser::And - 65))
            | (1ULL << (CParser::AndAnd - 65))
            | (1ULL << (CParser::Not - 65))
            | (1ULL << (CParser::Tilde - 65))
            | (1ULL << (CParser::Identifier - 65))
            | (1ULL << (CParser::Constant - 65))
            | (1ULL << (CParser::DigitSequence - 65))
            | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
            setState(1100);
            assignmentExpression();
          }
          setState(1103);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1104);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1105);
          match(CParser::LeftBracket);
          setState(1106);
          match(CParser::Static);
          setState(1108);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::Const)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Atomic))) != 0)) {
            setState(1107);
            typeQualifierList(0);
          }
          setState(1110);
          assignmentExpression();
          setState(1111);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1113);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1114);
          match(CParser::LeftBracket);
          setState(1115);
          typeQualifierList(0);
          setState(1116);
          match(CParser::Static);
          setState(1117);
          assignmentExpression();
          setState(1118);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1120);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(1121);
          match(CParser::LeftBracket);
          setState(1122);
          match(CParser::Star);
          setState(1123);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(1124);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(1125);
          match(CParser::LeftParen);
          setState(1127);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::T__4)
            | (1ULL << CParser::T__5)
            | (1ULL << CParser::T__6)
            | (1ULL << CParser::T__7)
            | (1ULL << CParser::T__8)
            | (1ULL << CParser::T__9)
            | (1ULL << CParser::T__11)
            | (1ULL << CParser::Auto)
            | (1ULL << CParser::Char)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Double)
            | (1ULL << CParser::Enum)
            | (1ULL << CParser::Extern)
            | (1ULL << CParser::Float)
            | (1ULL << CParser::Inline)
            | (1ULL << CParser::Int)
            | (1ULL << CParser::Long)
            | (1ULL << CParser::Register)
            | (1ULL << CParser::Restrict)
            | (1ULL << CParser::Short)
            | (1ULL << CParser::Signed)
            | (1ULL << CParser::Static)
            | (1ULL << CParser::Struct)
            | (1ULL << CParser::Typedef)
            | (1ULL << CParser::Union)
            | (1ULL << CParser::Unsigned)
            | (1ULL << CParser::Void)
            | (1ULL << CParser::Volatile)
            | (1ULL << CParser::Alignas)
            | (1ULL << CParser::Atomic)
            | (1ULL << CParser::Bool)
            | (1ULL << CParser::Complex)
            | (1ULL << CParser::Noreturn))) != 0) || _la == CParser::ThreadLocal

          || _la == CParser::Identifier) {
            setState(1126);
            parameterTypeList();
          }
          setState(1129);
          match(CParser::RightParen);
          setState(1133);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(1130);
              gccDeclaratorExtension(); 
            }
            setState(1135);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
          }
          break;
        }

        } 
      }
      setState(1140);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypedefNameContext ------------------------------------------------------------------

CParser::TypedefNameContext::TypedefNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypedefNameContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::TypedefNameContext::getRuleIndex() const {
  return CParser::RuleTypedefName;
}

void CParser::TypedefNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedefName(this);
}

void CParser::TypedefNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedefName(this);
}


antlrcpp::Any CParser::TypedefNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypedefName(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypedefNameContext* CParser::typedefName() {
  TypedefNameContext *_localctx = _tracker.createInstance<TypedefNameContext>(_ctx, getState());
  enterRule(_localctx, 138, CParser::RuleTypedefName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1141);
    match(CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

CParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::InitializerContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::InitializerListContext* CParser::InitializerContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}


size_t CParser::InitializerContext::getRuleIndex() const {
  return CParser::RuleInitializer;
}

void CParser::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void CParser::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}


antlrcpp::Any CParser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitializerContext* CParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 140, CParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1143);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1144);
      match(CParser::LeftBrace);
      setState(1145);
      initializerList(0);
      setState(1146);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1148);
      match(CParser::LeftBrace);
      setState(1149);
      initializerList(0);
      setState(1150);
      match(CParser::Comma);
      setState(1151);
      match(CParser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerListContext ------------------------------------------------------------------

CParser::InitializerListContext::InitializerListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InitializerContext* CParser::InitializerListContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}

CParser::DesignationContext* CParser::InitializerListContext::designation() {
  return getRuleContext<CParser::DesignationContext>(0);
}

CParser::InitializerListContext* CParser::InitializerListContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}


size_t CParser::InitializerListContext::getRuleIndex() const {
  return CParser::RuleInitializerList;
}

void CParser::InitializerListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializerList(this);
}

void CParser::InitializerListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializerList(this);
}


antlrcpp::Any CParser::InitializerListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitializerList(this);
  else
    return visitor->visitChildren(this);
}


CParser::InitializerListContext* CParser::initializerList() {
   return initializerList(0);
}

CParser::InitializerListContext* CParser::initializerList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InitializerListContext *_localctx = _tracker.createInstance<InitializerListContext>(_ctx, parentState);
  CParser::InitializerListContext *previousContext = _localctx;
  size_t startState = 142;
  enterRecursionRule(_localctx, 142, CParser::RuleInitializerList, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftBracket

    || _la == CParser::Dot) {
      setState(1156);
      designation();
    }
    setState(1159);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(1169);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(1161);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1162);
        match(CParser::Comma);
        setState(1164);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::Dot) {
          setState(1163);
          designation();
        }
        setState(1166);
        initializer(); 
      }
      setState(1171);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignationContext ------------------------------------------------------------------

CParser::DesignationContext::DesignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorListContext* CParser::DesignationContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}


size_t CParser::DesignationContext::getRuleIndex() const {
  return CParser::RuleDesignation;
}

void CParser::DesignationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignation(this);
}

void CParser::DesignationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignation(this);
}


antlrcpp::Any CParser::DesignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignation(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignationContext* CParser::designation() {
  DesignationContext *_localctx = _tracker.createInstance<DesignationContext>(_ctx, getState());
  enterRule(_localctx, 144, CParser::RuleDesignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1172);
    designatorList(0);
    setState(1173);
    match(CParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorListContext ------------------------------------------------------------------

CParser::DesignatorListContext::DesignatorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorContext* CParser::DesignatorListContext::designator() {
  return getRuleContext<CParser::DesignatorContext>(0);
}

CParser::DesignatorListContext* CParser::DesignatorListContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}


size_t CParser::DesignatorListContext::getRuleIndex() const {
  return CParser::RuleDesignatorList;
}

void CParser::DesignatorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignatorList(this);
}

void CParser::DesignatorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignatorList(this);
}


antlrcpp::Any CParser::DesignatorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignatorList(this);
  else
    return visitor->visitChildren(this);
}


CParser::DesignatorListContext* CParser::designatorList() {
   return designatorList(0);
}

CParser::DesignatorListContext* CParser::designatorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DesignatorListContext *_localctx = _tracker.createInstance<DesignatorListContext>(_ctx, parentState);
  CParser::DesignatorListContext *previousContext = _localctx;
  size_t startState = 146;
  enterRecursionRule(_localctx, 146, CParser::RuleDesignatorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1176);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(1182);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(1178);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1179);
        designator(); 
      }
      setState(1184);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

CParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConstantExpressionContext* CParser::DesignatorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::DesignatorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::DesignatorContext::getRuleIndex() const {
  return CParser::RuleDesignator;
}

void CParser::DesignatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignator(this);
}

void CParser::DesignatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignator(this);
}


antlrcpp::Any CParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignatorContext* CParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 148, CParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(1185);
        match(CParser::LeftBracket);
        setState(1186);
        constantExpression();
        setState(1187);
        match(CParser::RightBracket);
        break;
      }

      case CParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(1189);
        match(CParser::Dot);
        setState(1190);
        match(CParser::Identifier);
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

//----------------- StaticAssertDeclarationContext ------------------------------------------------------------------

CParser::StaticAssertDeclarationContext::StaticAssertDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConstantExpressionContext* CParser::StaticAssertDeclarationContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

std::vector<tree::TerminalNode *> CParser::StaticAssertDeclarationContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}


size_t CParser::StaticAssertDeclarationContext::getRuleIndex() const {
  return CParser::RuleStaticAssertDeclaration;
}

void CParser::StaticAssertDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStaticAssertDeclaration(this);
}

void CParser::StaticAssertDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStaticAssertDeclaration(this);
}


antlrcpp::Any CParser::StaticAssertDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStaticAssertDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::StaticAssertDeclarationContext* CParser::staticAssertDeclaration() {
  StaticAssertDeclarationContext *_localctx = _tracker.createInstance<StaticAssertDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 150, CParser::RuleStaticAssertDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1193);
    match(CParser::StaticAssert);
    setState(1194);
    match(CParser::LeftParen);
    setState(1195);
    constantExpression();
    setState(1196);
    match(CParser::Comma);
    setState(1198); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1197);
      match(CParser::StringLiteral);
      setState(1200); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::StringLiteral);
    setState(1202);
    match(CParser::RightParen);
    setState(1203);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LabeledStatementContext* CParser::StatementContext::labeledStatement() {
  return getRuleContext<CParser::LabeledStatementContext>(0);
}

CParser::CompoundStatementContext* CParser::StatementContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::ExpressionStatementContext* CParser::StatementContext::expressionStatement() {
  return getRuleContext<CParser::ExpressionStatementContext>(0);
}

CParser::SelectionStatementContext* CParser::StatementContext::selectionStatement() {
  return getRuleContext<CParser::SelectionStatementContext>(0);
}

CParser::IterationStatementContext* CParser::StatementContext::iterationStatement() {
  return getRuleContext<CParser::IterationStatementContext>(0);
}

CParser::JumpStatementContext* CParser::StatementContext::jumpStatement() {
  return getRuleContext<CParser::JumpStatementContext>(0);
}

std::vector<CParser::LogicalOrExpressionContext *> CParser::StatementContext::logicalOrExpression() {
  return getRuleContexts<CParser::LogicalOrExpressionContext>();
}

CParser::LogicalOrExpressionContext* CParser::StatementContext::logicalOrExpression(size_t i) {
  return getRuleContext<CParser::LogicalOrExpressionContext>(i);
}


size_t CParser::StatementContext::getRuleIndex() const {
  return CParser::RuleStatement;
}

void CParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void CParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any CParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::StatementContext* CParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 152, CParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 136, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1205);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1206);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1207);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1208);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1209);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1210);
      jumpStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1211);
      _la = _input->LA(1);
      if (!(_la == CParser::T__10

      || _la == CParser::T__12)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1212);
      _la = _input->LA(1);
      if (!(_la == CParser::T__13

      || _la == CParser::Volatile)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1213);
      match(CParser::LeftParen);
      setState(1222);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1214);
        logicalOrExpression(0);
        setState(1219);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CParser::Comma) {
          setState(1215);
          match(CParser::Comma);
          setState(1216);
          logicalOrExpression(0);
          setState(1221);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1237);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::Colon) {
        setState(1224);
        match(CParser::Colon);
        setState(1233);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__0)
          | (1ULL << CParser::T__1)
          | (1ULL << CParser::T__2)
          | (1ULL << CParser::NullPtr)
          | (1ULL << CParser::Tree_find_key)
          | (1ULL << CParser::Tree_add_key)
          | (1ULL << CParser::Tree_enum)
          | (1ULL << CParser::Tree_set_key)
          | (1ULL << CParser::Tree_get_key)
          | (1ULL << CParser::Sizeof)
          | (1ULL << CParser::Alignof)
          | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
          | (1ULL << (CParser::Plus - 65))
          | (1ULL << (CParser::PlusPlus - 65))
          | (1ULL << (CParser::Minus - 65))
          | (1ULL << (CParser::MinusMinus - 65))
          | (1ULL << (CParser::Star - 65))
          | (1ULL << (CParser::And - 65))
          | (1ULL << (CParser::AndAnd - 65))
          | (1ULL << (CParser::Not - 65))
          | (1ULL << (CParser::Tilde - 65))
          | (1ULL << (CParser::Identifier - 65))
          | (1ULL << (CParser::Constant - 65))
          | (1ULL << (CParser::DigitSequence - 65))
          | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
          setState(1225);
          logicalOrExpression(0);
          setState(1230);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CParser::Comma) {
            setState(1226);
            match(CParser::Comma);
            setState(1227);
            logicalOrExpression(0);
            setState(1232);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(1239);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1240);
      match(CParser::RightParen);
      setState(1241);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabeledStatementContext ------------------------------------------------------------------

CParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LabeledStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::StatementContext* CParser::LabeledStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::ConstantExpressionContext* CParser::LabeledStatementContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::LabeledStatementContext::getRuleIndex() const {
  return CParser::RuleLabeledStatement;
}

void CParser::LabeledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeledStatement(this);
}

void CParser::LabeledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeledStatement(this);
}


antlrcpp::Any CParser::LabeledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLabeledStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::LabeledStatementContext* CParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, CParser::RuleLabeledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1255);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(1244);
        match(CParser::Identifier);
        setState(1245);
        match(CParser::Colon);
        setState(1246);
        statement();
        break;
      }

      case CParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(1247);
        match(CParser::Case);
        setState(1248);
        constantExpression();
        setState(1249);
        match(CParser::Colon);
        setState(1250);
        statement();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(1252);
        match(CParser::Default);
        setState(1253);
        match(CParser::Colon);
        setState(1254);
        statement();
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

//----------------- CompoundStatementContext ------------------------------------------------------------------

CParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::BlockItemListContext* CParser::CompoundStatementContext::blockItemList() {
  return getRuleContext<CParser::BlockItemListContext>(0);
}


size_t CParser::CompoundStatementContext::getRuleIndex() const {
  return CParser::RuleCompoundStatement;
}

void CParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void CParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any CParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::CompoundStatementContext* CParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 156, CParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1257);
    match(CParser::LeftBrace);
    setState(1259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::NullPtr)
      | (1ULL << CParser::Tree_find_key)
      | (1ULL << CParser::Tree_add_key)
      | (1ULL << CParser::Tree_enum)
      | (1ULL << CParser::Tree_set_key)
      | (1ULL << CParser::Tree_get_key)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Do)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::Goto)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::While)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Generic)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::ThreadLocal - 64))
      | (1ULL << (CParser::LeftParen - 64))
      | (1ULL << (CParser::LeftBrace - 64))
      | (1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::PlusPlus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::MinusMinus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::AndAnd - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(1258);
      blockItemList(0);
    }
    setState(1261);
    match(CParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

CParser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::BlockItemContext* CParser::BlockItemListContext::blockItem() {
  return getRuleContext<CParser::BlockItemContext>(0);
}

CParser::BlockItemListContext* CParser::BlockItemListContext::blockItemList() {
  return getRuleContext<CParser::BlockItemListContext>(0);
}


size_t CParser::BlockItemListContext::getRuleIndex() const {
  return CParser::RuleBlockItemList;
}

void CParser::BlockItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemList(this);
}

void CParser::BlockItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemList(this);
}


antlrcpp::Any CParser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}


CParser::BlockItemListContext* CParser::blockItemList() {
   return blockItemList(0);
}

CParser::BlockItemListContext* CParser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  CParser::BlockItemListContext *previousContext = _localctx;
  size_t startState = 158;
  enterRecursionRule(_localctx, 158, CParser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1264);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(1270);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(1266);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1267);
        blockItem(); 
      }
      setState(1272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationContext* CParser::BlockItemContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}

CParser::StatementContext* CParser::BlockItemContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}


size_t CParser::BlockItemContext::getRuleIndex() const {
  return CParser::RuleBlockItem;
}

void CParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any CParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

CParser::BlockItemContext* CParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 160, CParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1273);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1274);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

CParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::ExpressionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ExpressionStatementContext::getRuleIndex() const {
  return CParser::RuleExpressionStatement;
}

void CParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void CParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any CParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExpressionStatementContext* CParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 162, CParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::NullPtr)
      | (1ULL << CParser::Tree_find_key)
      | (1ULL << CParser::Tree_add_key)
      | (1ULL << CParser::Tree_enum)
      | (1ULL << CParser::Tree_set_key)
      | (1ULL << CParser::Tree_get_key)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Alignof)
      | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
      | (1ULL << (CParser::Plus - 65))
      | (1ULL << (CParser::PlusPlus - 65))
      | (1ULL << (CParser::Minus - 65))
      | (1ULL << (CParser::MinusMinus - 65))
      | (1ULL << (CParser::Star - 65))
      | (1ULL << (CParser::And - 65))
      | (1ULL << (CParser::AndAnd - 65))
      | (1ULL << (CParser::Not - 65))
      | (1ULL << (CParser::Tilde - 65))
      | (1ULL << (CParser::Identifier - 65))
      | (1ULL << (CParser::Constant - 65))
      | (1ULL << (CParser::DigitSequence - 65))
      | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
      setState(1277);
      expression(0);
    }
    setState(1280);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

CParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::SelectionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

std::vector<CParser::StatementContext *> CParser::SelectionStatementContext::statement() {
  return getRuleContexts<CParser::StatementContext>();
}

CParser::StatementContext* CParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<CParser::StatementContext>(i);
}


size_t CParser::SelectionStatementContext::getRuleIndex() const {
  return CParser::RuleSelectionStatement;
}

void CParser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void CParser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any CParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::SelectionStatementContext* CParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 164, CParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1297);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(1282);
        match(CParser::If);
        setState(1283);
        match(CParser::LeftParen);
        setState(1284);
        expression(0);
        setState(1285);
        match(CParser::RightParen);
        setState(1286);
        statement();
        setState(1289);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx)) {
        case 1: {
          setState(1287);
          match(CParser::Else);
          setState(1288);
          statement();
          break;
        }

        }
        break;
      }

      case CParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(1291);
        match(CParser::Switch);
        setState(1292);
        match(CParser::LeftParen);
        setState(1293);
        expression(0);
        setState(1294);
        match(CParser::RightParen);
        setState(1295);
        statement();
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

//----------------- IterationStatementContext ------------------------------------------------------------------

CParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IterationStatementContext::While() {
  return getToken(CParser::While, 0);
}

CParser::ExpressionContext* CParser::IterationStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::StatementContext* CParser::IterationStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::IterationStatementContext::Do() {
  return getToken(CParser::Do, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::For() {
  return getToken(CParser::For, 0);
}

CParser::ForConditionContext* CParser::IterationStatementContext::forCondition() {
  return getRuleContext<CParser::ForConditionContext>(0);
}


size_t CParser::IterationStatementContext::getRuleIndex() const {
  return CParser::RuleIterationStatement;
}

void CParser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void CParser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any CParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::IterationStatementContext* CParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 166, CParser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1319);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(1299);
        match(CParser::While);
        setState(1300);
        match(CParser::LeftParen);
        setState(1301);
        expression(0);
        setState(1302);
        match(CParser::RightParen);
        setState(1303);
        statement();
        break;
      }

      case CParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(1305);
        match(CParser::Do);
        setState(1306);
        statement();
        setState(1307);
        match(CParser::While);
        setState(1308);
        match(CParser::LeftParen);
        setState(1309);
        expression(0);
        setState(1310);
        match(CParser::RightParen);
        setState(1311);
        match(CParser::Semi);
        break;
      }

      case CParser::For: {
        enterOuterAlt(_localctx, 3);
        setState(1313);
        match(CParser::For);
        setState(1314);
        match(CParser::LeftParen);
        setState(1315);
        forCondition();
        setState(1316);
        match(CParser::RightParen);
        setState(1317);
        statement();
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

//----------------- ForConditionContext ------------------------------------------------------------------

CParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ForDeclarationContext* CParser::ForConditionContext::forDeclaration() {
  return getRuleContext<CParser::ForDeclarationContext>(0);
}

std::vector<CParser::ForExpressionContext *> CParser::ForConditionContext::forExpression() {
  return getRuleContexts<CParser::ForExpressionContext>();
}

CParser::ForExpressionContext* CParser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<CParser::ForExpressionContext>(i);
}

CParser::ExpressionContext* CParser::ForConditionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ForConditionContext::getRuleIndex() const {
  return CParser::RuleForCondition;
}

void CParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void CParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}


antlrcpp::Any CParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForConditionContext* CParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 168, CParser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1321);
      forDeclaration();
      setState(1322);
      match(CParser::Semi);
      setState(1324);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1323);
        forExpression(0);
      }
      setState(1326);
      match(CParser::Semi);
      setState(1328);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1327);
        forExpression(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1331);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1330);
        expression(0);
      }
      setState(1333);
      match(CParser::Semi);
      setState(1335);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1334);
        forExpression(0);
      }
      setState(1337);
      match(CParser::Semi);
      setState(1339);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1338);
        forExpression(0);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForDeclarationContext ------------------------------------------------------------------

CParser::ForDeclarationContext::ForDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::ForDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::InitDeclaratorListContext* CParser::ForDeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::ForDeclarationContext::getRuleIndex() const {
  return CParser::RuleForDeclaration;
}

void CParser::ForDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForDeclaration(this);
}

void CParser::ForDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForDeclaration(this);
}


antlrcpp::Any CParser::ForDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForDeclarationContext* CParser::forDeclaration() {
  ForDeclarationContext *_localctx = _tracker.createInstance<ForDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 170, CParser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1347);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1343);
      declarationSpecifiers();
      setState(1344);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1346);
      declarationSpecifiers();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForExpressionContext ------------------------------------------------------------------

CParser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ForExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ForExpressionContext* CParser::ForExpressionContext::forExpression() {
  return getRuleContext<CParser::ForExpressionContext>(0);
}


size_t CParser::ForExpressionContext::getRuleIndex() const {
  return CParser::RuleForExpression;
}

void CParser::ForExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForExpression(this);
}

void CParser::ForExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForExpression(this);
}


antlrcpp::Any CParser::ForExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForExpression(this);
  else
    return visitor->visitChildren(this);
}


CParser::ForExpressionContext* CParser::forExpression() {
   return forExpression(0);
}

CParser::ForExpressionContext* CParser::forExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, parentState);
  CParser::ForExpressionContext *previousContext = _localctx;
  size_t startState = 172;
  enterRecursionRule(_localctx, 172, CParser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1350);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(1357);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(1352);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1353);
        match(CParser::Comma);
        setState(1354);
        assignmentExpression(); 
      }
      setState(1359);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

CParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::JumpStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::ExpressionContext* CParser::JumpStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::JumpStatementContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}


size_t CParser::JumpStatementContext::getRuleIndex() const {
  return CParser::RuleJumpStatement;
}

void CParser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void CParser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}


antlrcpp::Any CParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::JumpStatementContext* CParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 174, CParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1360);
      match(CParser::Goto);
      setState(1361);
      match(CParser::Identifier);
      setState(1362);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1363);
      match(CParser::Continue);
      setState(1364);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1365);
      match(CParser::Break);
      setState(1366);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1367);
      match(CParser::Return);
      setState(1369);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::NullPtr)
        | (1ULL << CParser::Tree_find_key)
        | (1ULL << CParser::Tree_add_key)
        | (1ULL << CParser::Tree_enum)
        | (1ULL << CParser::Tree_set_key)
        | (1ULL << CParser::Tree_get_key)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::Alignof)
        | (1ULL << CParser::Generic))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (CParser::LeftParen - 65))
        | (1ULL << (CParser::Plus - 65))
        | (1ULL << (CParser::PlusPlus - 65))
        | (1ULL << (CParser::Minus - 65))
        | (1ULL << (CParser::MinusMinus - 65))
        | (1ULL << (CParser::Star - 65))
        | (1ULL << (CParser::And - 65))
        | (1ULL << (CParser::AndAnd - 65))
        | (1ULL << (CParser::Not - 65))
        | (1ULL << (CParser::Tilde - 65))
        | (1ULL << (CParser::Identifier - 65))
        | (1ULL << (CParser::Constant - 65))
        | (1ULL << (CParser::DigitSequence - 65))
        | (1ULL << (CParser::StringLiteral - 65)))) != 0)) {
        setState(1368);
        expression(0);
      }
      setState(1371);
      match(CParser::Semi);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1372);
      match(CParser::Goto);
      setState(1373);
      unaryExpression();
      setState(1374);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompilationUnitContext ------------------------------------------------------------------

CParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CompilationUnitContext::EOF() {
  return getToken(CParser::EOF, 0);
}

CParser::TranslationUnitContext* CParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::CompilationUnitContext::getRuleIndex() const {
  return CParser::RuleCompilationUnit;
}

void CParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void CParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any CParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

CParser::CompilationUnitContext* CParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 176, CParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::ThreadLocal - 64))
      | (1ULL << (CParser::LeftParen - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::Caret - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Identifier - 64)))) != 0)) {
      setState(1378);
      translationUnit(0);
    }
    setState(1381);
    match(CParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

CParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExternalDeclarationContext* CParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<CParser::ExternalDeclarationContext>(0);
}

CParser::TranslationUnitContext* CParser::TranslationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::TranslationUnitContext::getRuleIndex() const {
  return CParser::RuleTranslationUnit;
}

void CParser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void CParser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


antlrcpp::Any CParser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}


CParser::TranslationUnitContext* CParser::translationUnit() {
   return translationUnit(0);
}

CParser::TranslationUnitContext* CParser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  CParser::TranslationUnitContext *previousContext = _localctx;
  size_t startState = 178;
  enterRecursionRule(_localctx, 178, CParser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1384);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(1390);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(1386);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1387);
        externalDeclaration(); 
      }
      setState(1392);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

CParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::FunctionDefinitionContext* CParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<CParser::FunctionDefinitionContext>(0);
}

CParser::DeclarationContext* CParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::ExternalDeclarationContext::getRuleIndex() const {
  return CParser::RuleExternalDeclaration;
}

void CParser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void CParser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any CParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExternalDeclarationContext* CParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 180, CParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1396);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1393);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1394);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1395);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

CParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::CompoundStatementContext* CParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::DeclarationSpecifiersContext* CParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclarationListContext* CParser::FunctionDefinitionContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
}


size_t CParser::FunctionDefinitionContext::getRuleIndex() const {
  return CParser::RuleFunctionDefinition;
}

void CParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void CParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any CParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionDefinitionContext* CParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 182, CParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1399);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx)) {
    case 1: {
      setState(1398);
      declarationSpecifiers();
      break;
    }

    }
    setState(1401);
    declarator();
    setState(1403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::Auto)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Enum)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Inline)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Restrict)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Struct)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Union)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Volatile)
      | (1ULL << CParser::Alignas)
      | (1ULL << CParser::Atomic)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Complex)
      | (1ULL << CParser::Noreturn)
      | (1ULL << CParser::StaticAssert))) != 0) || _la == CParser::ThreadLocal

    || _la == CParser::Identifier) {
      setState(1402);
      declarationList(0);
    }
    setState(1405);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListContext ------------------------------------------------------------------

CParser::DeclarationListContext::DeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationContext* CParser::DeclarationListContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}

CParser::DeclarationListContext* CParser::DeclarationListContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
}


size_t CParser::DeclarationListContext::getRuleIndex() const {
  return CParser::RuleDeclarationList;
}

void CParser::DeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationList(this);
}

void CParser::DeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationList(this);
}


antlrcpp::Any CParser::DeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


CParser::DeclarationListContext* CParser::declarationList() {
   return declarationList(0);
}

CParser::DeclarationListContext* CParser::declarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DeclarationListContext *_localctx = _tracker.createInstance<DeclarationListContext>(_ctx, parentState);
  CParser::DeclarationListContext *previousContext = _localctx;
  size_t startState = 184;
  enterRecursionRule(_localctx, 184, CParser::RuleDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1408);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(1414);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(1410);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1411);
        declaration(); 
      }
      setState(1416);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return genericAssocListSempred(dynamic_cast<GenericAssocListContext *>(context), predicateIndex);
    case 10: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 11: return argumentExpressionListSempred(dynamic_cast<ArgumentExpressionListContext *>(context), predicateIndex);
    case 15: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 16: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 17: return shiftExpressionSempred(dynamic_cast<ShiftExpressionContext *>(context), predicateIndex);
    case 18: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 19: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 20: return andExpressionSempred(dynamic_cast<AndExpressionContext *>(context), predicateIndex);
    case 21: return exclusiveOrExpressionSempred(dynamic_cast<ExclusiveOrExpressionContext *>(context), predicateIndex);
    case 22: return inclusiveOrExpressionSempred(dynamic_cast<InclusiveOrExpressionContext *>(context), predicateIndex);
    case 23: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 24: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 28: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 34: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 40: return structDeclarationListSempred(dynamic_cast<StructDeclarationListContext *>(context), predicateIndex);
    case 43: return structDeclaratorListSempred(dynamic_cast<StructDeclaratorListContext *>(context), predicateIndex);
    case 46: return enumeratorListSempred(dynamic_cast<EnumeratorListContext *>(context), predicateIndex);
    case 54: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 61: return typeQualifierListSempred(dynamic_cast<TypeQualifierListContext *>(context), predicateIndex);
    case 63: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 65: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 68: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 71: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 73: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 79: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 86: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 89: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 92: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CParser::genericAssocListSempred(GenericAssocListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool CParser::argumentExpressionListSempred(ArgumentExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 3);
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::shiftExpressionSempred(ShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 2);
    case 13: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 14: return precpred(_ctx, 4);
    case 15: return precpred(_ctx, 3);
    case 16: return precpred(_ctx, 2);
    case 17: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 18: return precpred(_ctx, 2);
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::structDeclarationListSempred(StructDeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::structDeclaratorListSempred(StructDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::enumeratorListSempred(EnumeratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 7);
    case 31: return precpred(_ctx, 6);
    case 32: return precpred(_ctx, 5);
    case 33: return precpred(_ctx, 4);
    case 34: return precpred(_ctx, 3);
    case 35: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 36: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 37: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 38: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 39: return precpred(_ctx, 5);
    case 40: return precpred(_ctx, 4);
    case 41: return precpred(_ctx, 3);
    case 42: return precpred(_ctx, 2);
    case 43: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 44: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 45: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 46: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 47: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 48: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 49: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CParser::_decisionToDFA;
atn::PredictionContextCache CParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CParser::_atn;
std::vector<uint16_t> CParser::_serializedATN;

std::vector<std::string> CParser::_ruleNames = {
  "primaryExpression", "genericSelection", "genericAssocList", "genericAssociation", 
  "treeSetKey", "treeAddKey", "treeGetKey", "treeFindKey", "treeEnum", "funcCall", 
  "postfixExpression", "argumentExpressionList", "unaryExpression", "unaryOperator", 
  "castExpression", "multiplicativeExpression", "additiveExpression", "shiftExpression", 
  "relationalExpression", "equalityExpression", "andExpression", "exclusiveOrExpression", 
  "inclusiveOrExpression", "logicalAndExpression", "logicalOrExpression", 
  "conditionalExpression", "assignmentExpression", "assignmentOperator", 
  "expression", "constantExpression", "declaration", "declarationSpecifiers", 
  "declarationSpecifiers2", "declarationSpecifier", "initDeclaratorList", 
  "initDeclarator", "storageClassSpecifier", "typeSpecifier", "structOrUnionSpecifier", 
  "structOrUnion", "structDeclarationList", "structDeclaration", "specifierQualifierList", 
  "structDeclaratorList", "structDeclarator", "enumSpecifier", "enumeratorList", 
  "enumerator", "enumerationConstant", "atomicTypeSpecifier", "typeQualifier", 
  "functionSpecifier", "alignmentSpecifier", "declarator", "directDeclarator", 
  "gccDeclaratorExtension", "gccAttributeSpecifier", "gccAttributeList", 
  "gccAttribute", "nestedParenthesesBlock", "pointer", "typeQualifierList", 
  "parameterTypeList", "parameterList", "parameterDeclaration", "identifierList", 
  "typeName", "abstractDeclarator", "directAbstractDeclarator", "typedefName", 
  "initializer", "initializerList", "designation", "designatorList", "designator", 
  "staticAssertDeclaration", "statement", "labeledStatement", "compoundStatement", 
  "blockItemList", "blockItem", "expressionStatement", "selectionStatement", 
  "iterationStatement", "forCondition", "forDeclaration", "forExpression", 
  "jumpStatement", "compilationUnit", "translationUnit", "externalDeclaration", 
  "functionDefinition", "declarationList"
};

std::vector<std::string> CParser::_literalNames = {
  "", "'__extension__'", "'__builtin_va_arg'", "'__builtin_offsetof'", "'__m128'", 
  "'__m128d'", "'__m128i'", "'__typeof__'", "'__inline__'", "'__stdcall'", 
  "'__declspec'", "'__asm'", "'__attribute__'", "'__asm__'", "'__volatile__'", 
  "'(void *)0x00000000L'", "'tree_manager_find_child_node'", "'tree_manager_add_child_node'", 
  "'tree_manager_get_first_child'", "", "", "'auto'", "'break'", "'case'", 
  "'char'", "'const'", "'continue'", "'default'", "'do'", "'double'", "'else'", 
  "'enum'", "'extern'", "'float'", "'for'", "'goto'", "'if'", "'inline'", 
  "'int'", "'long'", "'register'", "'restrict'", "'return'", "'short'", 
  "'signed'", "'sizeof'", "'static'", "'struct'", "'switch'", "'typedef'", 
  "'union'", "'unsigned'", "'void'", "'volatile'", "'while'", "'_Alignas'", 
  "'_Alignof'", "'_Atomic'", "'_Bool'", "'_Complex'", "'_Generic'", "'_Imaginary'", 
  "'_Noreturn'", "'_Static_assert'", "'_Thread_local'", "'('", "')'", "'['", 
  "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", 
  "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", "'&'", "'|'", "'&&'", "'||'", 
  "'^'", "'!'", "'~'", "'?'", "':'", "';'", "','", "'='", "'*='", "'/='", 
  "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", "'^='", "'|='", "'=='", 
  "'!='", "'->'", "'.'", "'...'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "NullPtr", 
  "Tree_find_key", "Tree_add_key", "Tree_enum", "Tree_set_key", "Tree_get_key", 
  "Auto", "Break", "Case", "Char", "Const", "Continue", "Default", "Do", 
  "Double", "Else", "Enum", "Extern", "Float", "For", "Goto", "If", "Inline", 
  "Int", "Long", "Register", "Restrict", "Return", "Short", "Signed", "Sizeof", 
  "Static", "Struct", "Switch", "Typedef", "Union", "Unsigned", "Void", 
  "Volatile", "While", "Alignas", "Alignof", "Atomic", "Bool", "Complex", 
  "Generic", "Imaginary", "Noreturn", "StaticAssert", "ThreadLocal", "LeftParen", 
  "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
  "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", "RightShift", 
  "Plus", "PlusPlus", "Minus", "MinusMinus", "Star", "Div", "Mod", "And", 
  "Or", "AndAnd", "OrOr", "Caret", "Not", "Tilde", "Question", "Colon", 
  "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", "PlusAssign", 
  "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", "XorAssign", 
  "OrAssign", "Equal", "NotEqual", "Arrow", "Dot", "Ellipsis", "Identifier", 
  "Constant", "DigitSequence", "StringLiteral", "ComplexDefine", "AsmBlock", 
  "LineAfterPreprocessing", "LineDirective", "PragmaDirective", "Whitespace", 
  "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary CParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CParser::_tokenNames;

CParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x7d, 0x58c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x6, 0x2, 0xc0, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xc1, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xcb, 
    0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xdf, 0xa, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0xee, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xf1, 0xb, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xfa, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xff, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x106, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x10b, 0xa, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x110, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x119, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x11d, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x121, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x126, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x130, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x135, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x139, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x13d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x142, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x14e, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x152, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x156, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x15b, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x160, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x165, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x16a, 0xa, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x16f, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x173, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x19d, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x1ae, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0x1b1, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x1b9, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x1bc, 
    0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1d4, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 
    0x10, 0x1e5, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x7, 0x11, 0x1f3, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 
    0x1f6, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x201, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x204, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 
    0x13, 0x20f, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x212, 0xb, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x7, 0x14, 0x223, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x226, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x231, 0xa, 0x15, 
    0xc, 0x15, 0xe, 0x15, 0x234, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x23c, 0xa, 0x16, 0xc, 0x16, 
    0xe, 0x16, 0x23f, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x247, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0x24a, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x7, 0x18, 0x252, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x255, 
    0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x7, 0x19, 0x25d, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x260, 0xb, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x7, 0x1a, 0x268, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x26b, 0xb, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 
    0x1b, 0x273, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x27b, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 
    0x1e, 0x285, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x288, 0xb, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x294, 0xa, 0x20, 0x3, 0x21, 
    0x6, 0x21, 0x297, 0xa, 0x21, 0xd, 0x21, 0xe, 0x21, 0x298, 0x3, 0x22, 
    0x6, 0x22, 0x29c, 0xa, 0x22, 0xd, 0x22, 0xe, 0x22, 0x29d, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x2a5, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 
    0x24, 0x2ad, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x2b0, 0xb, 0x24, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x2b7, 
    0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x2c9, 0xa, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x2cd, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x2d6, 
    0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x2df, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 
    0x2e2, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2e6, 0xa, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x2eb, 0xa, 0x2b, 0x3, 0x2c, 
    0x3, 0x2c, 0x5, 0x2c, 0x2ef, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x2f3, 0xa, 0x2c, 0x5, 0x2c, 0x2f5, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x2fd, 0xa, 0x2d, 
    0xc, 0x2d, 0xe, 0x2d, 0x300, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
    0x304, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x308, 0xa, 0x2e, 
    0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x30c, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x314, 0xa, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x5, 0x2f, 0x31d, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x325, 0xa, 0x30, 0xc, 0x30, 
    0xe, 0x30, 0x328, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x5, 0x31, 0x32f, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 
    0x340, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x34c, 
    0xa, 0x36, 0x3, 0x37, 0x5, 0x37, 0x34f, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x7, 0x37, 0x353, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x356, 0xb, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x361, 0xa, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x366, 0xa, 0x38, 0x3, 0x38, 0x5, 0x38, 
    0x369, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x370, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x37f, 0xa, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x38b, 0xa, 0x38, 0x3, 0x38, 
    0x7, 0x38, 0x38e, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x391, 0xb, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x6, 0x39, 0x396, 0xa, 0x39, 0xd, 0x39, 
    0xe, 0x39, 0x397, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x39c, 0xa, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x3a8, 0xa, 0x3b, 
    0xc, 0x3b, 0xe, 0x3b, 0x3ab, 0xb, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x3ae, 
    0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x3b3, 0xa, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x3b6, 0xa, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x3b9, 
    0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 
    0x3d, 0x3c0, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x3c3, 0xb, 0x3d, 0x3, 
    0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x3c7, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x3cb, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 
    0x3d0, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x3d4, 0xa, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x3d7, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x3de, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 
    0x3e1, 0xb, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x3e8, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x3f0, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 
    0x3f3, 0xb, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x5, 0x42, 0x3fa, 0xa, 0x42, 0x5, 0x42, 0x3fc, 0xa, 0x42, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x404, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x407, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x5, 0x44, 0x40b, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x40f, 
    0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x413, 0xa, 0x45, 0xc, 0x45, 
    0xe, 0x45, 0x416, 0xb, 0x45, 0x5, 0x45, 0x418, 0xa, 0x45, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x41f, 0xa, 0x46, 
    0xc, 0x46, 0xe, 0x46, 0x422, 0xb, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 
    0x426, 0xa, 0x46, 0x3, 0x46, 0x5, 0x46, 0x429, 0xa, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x42f, 0xa, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x5, 0x46, 0x43f, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x443, 
    0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x446, 0xb, 0x46, 0x5, 0x46, 0x448, 
    0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x44d, 0xa, 0x46, 
    0x3, 0x46, 0x5, 0x46, 0x450, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x457, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x46a, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x7, 0x46, 0x46e, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x471, 0xb, 0x46, 
    0x7, 0x46, 0x473, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x476, 0xb, 0x46, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 
    0x484, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x488, 0xa, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x48f, 
    0xa, 0x49, 0x3, 0x49, 0x7, 0x49, 0x492, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 
    0x495, 0xb, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x49f, 0xa, 0x4b, 0xc, 0x4b, 
    0xe, 0x4b, 0x4a2, 0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x4aa, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x6, 0x4d, 0x4b1, 0xa, 0x4d, 0xd, 0x4d, 
    0xe, 0x4d, 0x4b2, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x4c4, 0xa, 0x4e, 
    0xc, 0x4e, 0xe, 0x4e, 0x4c7, 0xb, 0x4e, 0x5, 0x4e, 0x4c9, 0xa, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x4cf, 0xa, 0x4e, 
    0xc, 0x4e, 0xe, 0x4e, 0x4d2, 0xb, 0x4e, 0x5, 0x4e, 0x4d4, 0xa, 0x4e, 
    0x7, 0x4e, 0x4d6, 0xa, 0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x4d9, 0xb, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x4dd, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x4ea, 0xa, 0x4f, 0x3, 0x50, 
    0x3, 0x50, 0x5, 0x50, 0x4ee, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x4f7, 0xa, 0x51, 
    0xc, 0x51, 0xe, 0x51, 0x4fa, 0xb, 0x51, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 
    0x4fe, 0xa, 0x52, 0x3, 0x53, 0x5, 0x53, 0x501, 0xa, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 
    0x54, 0x3, 0x54, 0x5, 0x54, 0x50c, 0xa, 0x54, 0x3, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x514, 0xa, 0x54, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x55, 0x5, 0x55, 0x52a, 0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x5, 0x56, 0x52f, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 0x533, 
    0xa, 0x56, 0x3, 0x56, 0x5, 0x56, 0x536, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x5, 0x56, 0x53a, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 0x53e, 
    0xa, 0x56, 0x5, 0x56, 0x540, 0xa, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x5, 0x57, 0x546, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x54e, 0xa, 0x58, 0xc, 0x58, 
    0xe, 0x58, 0x551, 0xb, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x55c, 
    0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 
    0x59, 0x563, 0xa, 0x59, 0x3, 0x5a, 0x5, 0x5a, 0x566, 0xa, 0x5a, 0x3, 
    0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
    0x7, 0x5b, 0x56f, 0xa, 0x5b, 0xc, 0x5b, 0xe, 0x5b, 0x572, 0xb, 0x5b, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x577, 0xa, 0x5c, 0x3, 0x5d, 
    0x5, 0x5d, 0x57a, 0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x57e, 
    0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
    0x5e, 0x3, 0x5e, 0x7, 0x5e, 0x587, 0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 
    0x58a, 0xb, 0x5e, 0x3, 0x5e, 0x2, 0x1f, 0x6, 0x16, 0x18, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x3a, 0x46, 0x52, 0x58, 
    0x5e, 0x6e, 0x7c, 0x80, 0x84, 0x8a, 0x90, 0x94, 0xa0, 0xae, 0xb4, 0xba, 
    0x5f, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 
    0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
    0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 
    0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0x2, 0x10, 0x4, 
    0x2, 0x71, 0x71, 0x74, 0x74, 0x3, 0x2, 0x71, 0x72, 0x7, 0x2, 0x4f, 0x4f, 
    0x51, 0x51, 0x53, 0x53, 0x56, 0x56, 0x5b, 0x5c, 0x3, 0x2, 0x61, 0x6b, 
    0x8, 0x2, 0x17, 0x17, 0x22, 0x22, 0x2a, 0x2a, 0x30, 0x30, 0x33, 0x33, 
    0x42, 0x42, 0xa, 0x2, 0x6, 0x8, 0x1a, 0x1a, 0x1f, 0x1f, 0x23, 0x23, 
    0x28, 0x29, 0x2d, 0x2e, 0x35, 0x36, 0x3c, 0x3d, 0x3, 0x2, 0x6, 0x8, 
    0x4, 0x2, 0x31, 0x31, 0x34, 0x34, 0x6, 0x2, 0x1b, 0x1b, 0x2b, 0x2b, 
    0x37, 0x37, 0x3b, 0x3b, 0x5, 0x2, 0xa, 0xb, 0x27, 0x27, 0x40, 0x40, 
    0x4, 0x2, 0x43, 0x44, 0x60, 0x60, 0x3, 0x2, 0x43, 0x44, 0x4, 0x2, 0xd, 
    0xd, 0xf, 0xf, 0x4, 0x2, 0x10, 0x10, 0x37, 0x37, 0x2, 0x613, 0x2, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x6, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xa, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x10c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x122, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x13e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x157, 0x3, 0x2, 0x2, 0x2, 0x14, 0x16b, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1b2, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d5, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1e6, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x205, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x213, 0x3, 0x2, 0x2, 0x2, 0x28, 0x227, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x235, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x240, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x24b, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x256, 0x3, 0x2, 0x2, 0x2, 0x32, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x27a, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x27e, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x289, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x293, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x296, 0x3, 0x2, 0x2, 0x2, 0x42, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x2a4, 0x3, 0x2, 0x2, 0x2, 0x46, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x48, 0x2b6, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x2c8, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x50, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x2ea, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2f6, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x307, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x31e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x62, 0x330, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x332, 0x3, 0x2, 0x2, 0x2, 0x66, 0x337, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x34b, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x360, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x72, 0x39d, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x76, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x3c1, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x3d8, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x80, 0x3e9, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x84, 0x3fd, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x408, 0x3, 0x2, 0x2, 0x2, 0x88, 0x417, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x447, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x477, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x483, 0x3, 0x2, 0x2, 0x2, 0x90, 0x485, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x496, 0x3, 0x2, 0x2, 0x2, 0x94, 0x499, 0x3, 0x2, 0x2, 0x2, 0x96, 0x4a9, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x4dc, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x4eb, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x4fd, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0x500, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x513, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0x529, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x53f, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0x545, 0x3, 0x2, 0x2, 0x2, 0xae, 0x547, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x562, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0x565, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x569, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0x576, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x579, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0x581, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xdf, 0x7, 0x71, 0x2, 
    0x2, 0xbd, 0xdf, 0x7, 0x72, 0x2, 0x2, 0xbe, 0xc0, 0x7, 0x74, 0x2, 0x2, 
    0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xdf, 0x7, 0x11, 0x2, 0x2, 0xc4, 0xc5, 0x7, 
    0x43, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x3a, 0x1e, 0x2, 0xc6, 0xc7, 0x7, 0x44, 
    0x2, 0x2, 0xc7, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xdf, 0x5, 0x4, 0x3, 
    0x2, 0xc9, 0xcb, 0x7, 0x3, 0x2, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xcd, 0x7, 0x43, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x9e, 0x50, 0x2, 0xce, 0xcf, 
    0x7, 0x44, 0x2, 0x2, 0xcf, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 
    0x4, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x43, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x1a, 
    0xe, 0x2, 0xd3, 0xd4, 0x7, 0x60, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x86, 0x44, 
    0x2, 0xd5, 0xd6, 0x7, 0x44, 0x2, 0x2, 0xd6, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd8, 0x7, 0x5, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x43, 0x2, 0x2, 0xd9, 
    0xda, 0x5, 0x86, 0x44, 0x2, 0xda, 0xdb, 0x7, 0x60, 0x2, 0x2, 0xdb, 0xdc, 
    0x5, 0x1a, 0xe, 0x2, 0xdc, 0xdd, 0x7, 0x44, 0x2, 0x2, 0xdd, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xde, 0xc8, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xca, 0x3, 0x2, 0x2, 0x2, 0xde, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xde, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 
    0x7, 0x3e, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x43, 0x2, 0x2, 0xe2, 0xe3, 0x5, 
    0x36, 0x1c, 0x2, 0xe3, 0xe4, 0x7, 0x60, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x6, 
    0x4, 0x2, 0xe5, 0xe6, 0x7, 0x44, 0x2, 0x2, 0xe6, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xe8, 0x8, 0x4, 0x1, 0x2, 0xe8, 0xe9, 0x5, 0x8, 0x5, 0x2, 
    0xe9, 0xef, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0xc, 0x3, 0x2, 0x2, 0xeb, 
    0xec, 0x7, 0x60, 0x2, 0x2, 0xec, 0xee, 0x5, 0x8, 0x5, 0x2, 0xed, 0xea, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x86, 0x44, 
    0x2, 0xf3, 0xf4, 0x7, 0x5e, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x36, 0x1c, 0x2, 
    0xf5, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x1d, 0x2, 0x2, 0xf7, 
    0xf8, 0x7, 0x5e, 0x2, 0x2, 0xf8, 0xfa, 0x5, 0x36, 0x1c, 0x2, 0xf9, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x15, 0x2, 0x2, 0xfc, 0xfe, 0x7, 0x43, 
    0x2, 0x2, 0xfd, 0xff, 0x7, 0x56, 0x2, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x100, 0x101, 0x7, 0x71, 0x2, 0x2, 0x101, 0x102, 0x7, 0x60, 0x2, 0x2, 
    0x102, 0x103, 0x7, 0x74, 0x2, 0x2, 0x103, 0x105, 0x7, 0x60, 0x2, 0x2, 
    0x104, 0x106, 0x7, 0x56, 0x2, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 
    0x107, 0x108, 0x5, 0x1a, 0xe, 0x2, 0x108, 0x10a, 0x7, 0x44, 0x2, 0x2, 
    0x109, 0x10b, 0x7, 0x5f, 0x2, 0x2, 0x10a, 0x109, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x10c, 
    0x10d, 0x7, 0x13, 0x2, 0x2, 0x10d, 0x10f, 0x7, 0x43, 0x2, 0x2, 0x10e, 
    0x110, 0x7, 0x56, 0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10f, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x112, 0x7, 0x71, 0x2, 0x2, 0x112, 0x113, 0x7, 0x60, 0x2, 0x2, 0x113, 
    0x114, 0x9, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x60, 0x2, 0x2, 0x115, 
    0x116, 0x9, 0x3, 0x2, 0x2, 0x116, 0x11c, 0x7, 0x60, 0x2, 0x2, 0x117, 
    0x119, 0x7, 0x56, 0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x11d, 0x7, 0x71, 0x2, 0x2, 0x11b, 0x11d, 0x7, 0x11, 0x2, 0x2, 0x11c, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x120, 0x7, 0x44, 0x2, 0x2, 0x11f, 
    0x121, 0x7, 0x5f, 0x2, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x120, 
    0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0xd, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
    0x7, 0x16, 0x2, 0x2, 0x123, 0x125, 0x7, 0x43, 0x2, 0x2, 0x124, 0x126, 
    0x7, 0x56, 0x2, 0x2, 0x125, 0x124, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 
    0x7, 0x71, 0x2, 0x2, 0x128, 0x129, 0x7, 0x60, 0x2, 0x2, 0x129, 0x12a, 
    0x7, 0x71, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x43, 0x2, 0x2, 0x12b, 0x12c, 
    0x9, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x44, 0x2, 0x2, 0x12d, 0x12f, 
    0x7, 0x60, 0x2, 0x2, 0x12e, 0x130, 0x7, 0x56, 0x2, 0x2, 0x12f, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x138, 0x5, 0x1a, 0xe, 0x2, 0x132, 0x133, 
    0x7, 0x60, 0x2, 0x2, 0x133, 0x135, 0x7, 0x72, 0x2, 0x2, 0x134, 0x132, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
    0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x60, 0x2, 0x2, 0x137, 0x139, 
    0x7, 0x72, 0x2, 0x2, 0x138, 0x134, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13c, 
    0x7, 0x44, 0x2, 0x2, 0x13b, 0x13d, 0x7, 0x5f, 0x2, 0x2, 0x13c, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x12, 0x2, 0x2, 0x13f, 0x141, 0x7, 
    0x43, 0x2, 0x2, 0x140, 0x142, 0x7, 0x56, 0x2, 0x2, 0x141, 0x140, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x71, 0x2, 0x2, 0x144, 0x145, 0x7, 
    0x60, 0x2, 0x2, 0x145, 0x146, 0x7, 0x71, 0x2, 0x2, 0x146, 0x147, 0x7, 
    0x43, 0x2, 0x2, 0x147, 0x148, 0x9, 0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 
    0x44, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x60, 0x2, 0x2, 0x14a, 0x14b, 0x9, 
    0x3, 0x2, 0x2, 0x14b, 0x151, 0x7, 0x60, 0x2, 0x2, 0x14c, 0x14e, 0x7, 
    0x56, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x152, 0x7, 
    0x71, 0x2, 0x2, 0x150, 0x152, 0x7, 0x11, 0x2, 0x2, 0x151, 0x14d, 0x3, 
    0x2, 0x2, 0x2, 0x151, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 
    0x2, 0x2, 0x2, 0x153, 0x155, 0x7, 0x44, 0x2, 0x2, 0x154, 0x156, 0x7, 
    0x5f, 0x2, 0x2, 0x155, 0x154, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 
    0x2, 0x2, 0x2, 0x156, 0x11, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x7, 0x14, 
    0x2, 0x2, 0x158, 0x15a, 0x7, 0x43, 0x2, 0x2, 0x159, 0x15b, 0x7, 0x56, 
    0x2, 0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x71, 
    0x2, 0x2, 0x15d, 0x15f, 0x7, 0x60, 0x2, 0x2, 0x15e, 0x160, 0x7, 0x56, 
    0x2, 0x2, 0x15f, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x71, 
    0x2, 0x2, 0x162, 0x164, 0x7, 0x60, 0x2, 0x2, 0x163, 0x165, 0x7, 0x56, 
    0x2, 0x2, 0x164, 0x163, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 
    0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x7, 0x71, 
    0x2, 0x2, 0x167, 0x169, 0x7, 0x44, 0x2, 0x2, 0x168, 0x16a, 0x7, 0x5f, 
    0x2, 0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x71, 
    0x2, 0x2, 0x16c, 0x16e, 0x7, 0x43, 0x2, 0x2, 0x16d, 0x16f, 0x5, 0x18, 
    0xd, 0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x172, 0x7, 0x44, 
    0x2, 0x2, 0x171, 0x173, 0x7, 0x5f, 0x2, 0x2, 0x172, 0x171, 0x3, 0x2, 
    0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x175, 0x8, 0xc, 0x1, 0x2, 0x175, 0x19d, 0x5, 0x2, 0x2, 
    0x2, 0x176, 0x19d, 0x5, 0xe, 0x8, 0x2, 0x177, 0x19d, 0x5, 0xa, 0x6, 
    0x2, 0x178, 0x19d, 0x5, 0x10, 0x9, 0x2, 0x179, 0x19d, 0x5, 0xc, 0x7, 
    0x2, 0x17a, 0x19d, 0x5, 0x12, 0xa, 0x2, 0x17b, 0x19d, 0x5, 0x14, 0xb, 
    0x2, 0x17c, 0x17d, 0x7, 0x43, 0x2, 0x2, 0x17d, 0x17e, 0x5, 0x86, 0x44, 
    0x2, 0x17e, 0x17f, 0x7, 0x44, 0x2, 0x2, 0x17f, 0x180, 0x7, 0x47, 0x2, 
    0x2, 0x180, 0x181, 0x5, 0x90, 0x49, 0x2, 0x181, 0x182, 0x7, 0x48, 0x2, 
    0x2, 0x182, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 0x43, 0x2, 
    0x2, 0x184, 0x185, 0x5, 0x86, 0x44, 0x2, 0x185, 0x186, 0x7, 0x44, 0x2, 
    0x2, 0x186, 0x187, 0x7, 0x47, 0x2, 0x2, 0x187, 0x188, 0x5, 0x90, 0x49, 
    0x2, 0x188, 0x189, 0x7, 0x60, 0x2, 0x2, 0x189, 0x18a, 0x7, 0x48, 0x2, 
    0x2, 0x18a, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x7, 0x3, 0x2, 
    0x2, 0x18c, 0x18d, 0x7, 0x43, 0x2, 0x2, 0x18d, 0x18e, 0x5, 0x86, 0x44, 
    0x2, 0x18e, 0x18f, 0x7, 0x44, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x47, 0x2, 
    0x2, 0x190, 0x191, 0x5, 0x90, 0x49, 0x2, 0x191, 0x192, 0x7, 0x48, 0x2, 
    0x2, 0x192, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x7, 0x3, 0x2, 
    0x2, 0x194, 0x195, 0x7, 0x43, 0x2, 0x2, 0x195, 0x196, 0x5, 0x86, 0x44, 
    0x2, 0x196, 0x197, 0x7, 0x44, 0x2, 0x2, 0x197, 0x198, 0x7, 0x47, 0x2, 
    0x2, 0x198, 0x199, 0x5, 0x90, 0x49, 0x2, 0x199, 0x19a, 0x7, 0x60, 0x2, 
    0x2, 0x19a, 0x19b, 0x7, 0x48, 0x2, 0x2, 0x19b, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x174, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x177, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x179, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x17a, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x183, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x193, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x19f, 0xc, 0xb, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x45, 0x2, 
    0x2, 0x1a0, 0x1a1, 0x5, 0x3a, 0x1e, 0x2, 0x1a1, 0x1a2, 0x7, 0x46, 0x2, 
    0x2, 0x1a2, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0xc, 0xa, 0x2, 
    0x2, 0x1a4, 0x1a5, 0x7, 0x6f, 0x2, 0x2, 0x1a5, 0x1ae, 0x7, 0x71, 0x2, 
    0x2, 0x1a6, 0x1a7, 0xc, 0x9, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x6e, 0x2, 
    0x2, 0x1a8, 0x1ae, 0x7, 0x71, 0x2, 0x2, 0x1a9, 0x1aa, 0xc, 0x8, 0x2, 
    0x2, 0x1aa, 0x1ae, 0x7, 0x50, 0x2, 0x2, 0x1ab, 0x1ac, 0xc, 0x7, 0x2, 
    0x2, 0x1ac, 0x1ae, 0x7, 0x52, 0x2, 0x2, 0x1ad, 0x19e, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x8, 0xd, 0x1, 0x2, 
    0x1b3, 0x1b4, 0x5, 0x36, 0x1c, 0x2, 0x1b4, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1b5, 0x1b6, 0xc, 0x3, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 0x60, 0x2, 0x2, 
    0x1b7, 0x1b9, 0x5, 0x36, 0x1c, 0x2, 0x1b8, 0x1b5, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1d4, 0x5, 0x16, 0xc, 0x2, 0x1be, 
    0x1bf, 0x7, 0x50, 0x2, 0x2, 0x1bf, 0x1d4, 0x5, 0x1a, 0xe, 0x2, 0x1c0, 
    0x1c1, 0x7, 0x52, 0x2, 0x2, 0x1c1, 0x1d4, 0x5, 0x1a, 0xe, 0x2, 0x1c2, 
    0x1c3, 0x5, 0x1c, 0xf, 0x2, 0x1c3, 0x1c4, 0x5, 0x1e, 0x10, 0x2, 0x1c4, 
    0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x2f, 0x2, 0x2, 0x1c6, 
    0x1d4, 0x5, 0x1a, 0xe, 0x2, 0x1c7, 0x1c8, 0x7, 0x2f, 0x2, 0x2, 0x1c8, 
    0x1c9, 0x7, 0x43, 0x2, 0x2, 0x1c9, 0x1ca, 0x5, 0x86, 0x44, 0x2, 0x1ca, 
    0x1cb, 0x7, 0x44, 0x2, 0x2, 0x1cb, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1cc, 
    0x1cd, 0x7, 0x3a, 0x2, 0x2, 0x1cd, 0x1ce, 0x7, 0x43, 0x2, 0x2, 0x1ce, 
    0x1cf, 0x5, 0x86, 0x44, 0x2, 0x1cf, 0x1d0, 0x7, 0x44, 0x2, 0x2, 0x1d0, 
    0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x7, 0x58, 0x2, 0x2, 0x1d2, 
    0x1d4, 0x7, 0x71, 0x2, 0x2, 0x1d3, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1be, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 
    0x9, 0x4, 0x2, 0x2, 0x1d6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1e5, 0x5, 
    0x1a, 0xe, 0x2, 0x1d8, 0x1d9, 0x7, 0x43, 0x2, 0x2, 0x1d9, 0x1da, 0x5, 
    0x86, 0x44, 0x2, 0x1da, 0x1db, 0x7, 0x44, 0x2, 0x2, 0x1db, 0x1dc, 0x5, 
    0x1e, 0x10, 0x2, 0x1dc, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x7, 
    0x3, 0x2, 0x2, 0x1de, 0x1df, 0x7, 0x43, 0x2, 0x2, 0x1df, 0x1e0, 0x5, 
    0x86, 0x44, 0x2, 0x1e0, 0x1e1, 0x7, 0x44, 0x2, 0x2, 0x1e1, 0x1e2, 0x5, 
    0x1e, 0x10, 0x2, 0x1e2, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e5, 0x7, 
    0x73, 0x2, 0x2, 0x1e4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1d8, 0x3, 
    0x2, 0x2, 0x2, 0x1e4, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e3, 0x3, 
    0x2, 0x2, 0x2, 0x1e5, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x8, 0x11, 
    0x1, 0x2, 0x1e7, 0x1e8, 0x5, 0x1e, 0x10, 0x2, 0x1e8, 0x1f4, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1ea, 0xc, 0x5, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x53, 
    0x2, 0x2, 0x1eb, 0x1f3, 0x5, 0x1e, 0x10, 0x2, 0x1ec, 0x1ed, 0xc, 0x4, 
    0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x54, 0x2, 0x2, 0x1ee, 0x1f3, 0x5, 0x1e, 
    0x10, 0x2, 0x1ef, 0x1f0, 0xc, 0x3, 0x2, 0x2, 0x1f0, 0x1f1, 0x7, 0x55, 
    0x2, 0x2, 0x1f1, 0x1f3, 0x5, 0x1e, 0x10, 0x2, 0x1f2, 0x1e9, 0x3, 0x2, 
    0x2, 0x2, 0x1f2, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ef, 0x3, 0x2, 
    0x2, 0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 
    0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x8, 0x12, 0x1, 
    0x2, 0x1f8, 0x1f9, 0x5, 0x20, 0x11, 0x2, 0x1f9, 0x202, 0x3, 0x2, 0x2, 
    0x2, 0x1fa, 0x1fb, 0xc, 0x4, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x4f, 0x2, 
    0x2, 0x1fc, 0x201, 0x5, 0x20, 0x11, 0x2, 0x1fd, 0x1fe, 0xc, 0x3, 0x2, 
    0x2, 0x1fe, 0x1ff, 0x7, 0x51, 0x2, 0x2, 0x1ff, 0x201, 0x5, 0x20, 0x11, 
    0x2, 0x200, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x200, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x204, 0x3, 0x2, 0x2, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 
    0x2, 0x202, 0x203, 0x3, 0x2, 0x2, 0x2, 0x203, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x204, 0x202, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x8, 0x13, 0x1, 0x2, 
    0x206, 0x207, 0x5, 0x22, 0x12, 0x2, 0x207, 0x210, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x209, 0xc, 0x4, 0x2, 0x2, 0x209, 0x20a, 0x7, 0x4d, 0x2, 0x2, 
    0x20a, 0x20f, 0x5, 0x22, 0x12, 0x2, 0x20b, 0x20c, 0xc, 0x3, 0x2, 0x2, 
    0x20c, 0x20d, 0x7, 0x4e, 0x2, 0x2, 0x20d, 0x20f, 0x5, 0x22, 0x12, 0x2, 
    0x20e, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x20f, 0x212, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 
    0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x25, 0x3, 0x2, 0x2, 0x2, 0x212, 
    0x210, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x8, 0x14, 0x1, 0x2, 0x214, 
    0x215, 0x5, 0x24, 0x13, 0x2, 0x215, 0x224, 0x3, 0x2, 0x2, 0x2, 0x216, 
    0x217, 0xc, 0x6, 0x2, 0x2, 0x217, 0x218, 0x7, 0x49, 0x2, 0x2, 0x218, 
    0x223, 0x5, 0x24, 0x13, 0x2, 0x219, 0x21a, 0xc, 0x5, 0x2, 0x2, 0x21a, 
    0x21b, 0x7, 0x4b, 0x2, 0x2, 0x21b, 0x223, 0x5, 0x24, 0x13, 0x2, 0x21c, 
    0x21d, 0xc, 0x4, 0x2, 0x2, 0x21d, 0x21e, 0x7, 0x4a, 0x2, 0x2, 0x21e, 
    0x223, 0x5, 0x24, 0x13, 0x2, 0x21f, 0x220, 0xc, 0x3, 0x2, 0x2, 0x220, 
    0x221, 0x7, 0x4c, 0x2, 0x2, 0x221, 0x223, 0x5, 0x24, 0x13, 0x2, 0x222, 
    0x216, 0x3, 0x2, 0x2, 0x2, 0x222, 0x219, 0x3, 0x2, 0x2, 0x2, 0x222, 
    0x21c, 0x3, 0x2, 0x2, 0x2, 0x222, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x223, 
    0x226, 0x3, 0x2, 0x2, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 
    0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 0x27, 0x3, 0x2, 0x2, 0x2, 0x226, 0x224, 
    0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x8, 0x15, 0x1, 0x2, 0x228, 0x229, 
    0x5, 0x26, 0x14, 0x2, 0x229, 0x232, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 
    0xc, 0x4, 0x2, 0x2, 0x22b, 0x22c, 0x7, 0x6c, 0x2, 0x2, 0x22c, 0x231, 
    0x5, 0x26, 0x14, 0x2, 0x22d, 0x22e, 0xc, 0x3, 0x2, 0x2, 0x22e, 0x22f, 
    0x7, 0x6d, 0x2, 0x2, 0x22f, 0x231, 0x5, 0x26, 0x14, 0x2, 0x230, 0x22a, 
    0x3, 0x2, 0x2, 0x2, 0x230, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x231, 0x234, 
    0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
    0x3, 0x2, 0x2, 0x2, 0x233, 0x29, 0x3, 0x2, 0x2, 0x2, 0x234, 0x232, 0x3, 
    0x2, 0x2, 0x2, 0x235, 0x236, 0x8, 0x16, 0x1, 0x2, 0x236, 0x237, 0x5, 
    0x28, 0x15, 0x2, 0x237, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0xc, 
    0x3, 0x2, 0x2, 0x239, 0x23a, 0x7, 0x56, 0x2, 0x2, 0x23a, 0x23c, 0x5, 
    0x28, 0x15, 0x2, 0x23b, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23f, 0x3, 
    0x2, 0x2, 0x2, 0x23d, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x23e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x23d, 0x3, 0x2, 
    0x2, 0x2, 0x240, 0x241, 0x8, 0x17, 0x1, 0x2, 0x241, 0x242, 0x5, 0x2a, 
    0x16, 0x2, 0x242, 0x248, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0xc, 0x3, 
    0x2, 0x2, 0x244, 0x245, 0x7, 0x5a, 0x2, 0x2, 0x245, 0x247, 0x5, 0x2a, 
    0x16, 0x2, 0x246, 0x243, 0x3, 0x2, 0x2, 0x2, 0x247, 0x24a, 0x3, 0x2, 
    0x2, 0x2, 0x248, 0x246, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 
    0x2, 0x2, 0x249, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x248, 0x3, 0x2, 0x2, 
    0x2, 0x24b, 0x24c, 0x8, 0x18, 0x1, 0x2, 0x24c, 0x24d, 0x5, 0x2c, 0x17, 
    0x2, 0x24d, 0x253, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0xc, 0x3, 0x2, 
    0x2, 0x24f, 0x250, 0x7, 0x57, 0x2, 0x2, 0x250, 0x252, 0x5, 0x2c, 0x17, 
    0x2, 0x251, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x252, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 
    0x2, 0x254, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 
    0x256, 0x257, 0x8, 0x19, 0x1, 0x2, 0x257, 0x258, 0x5, 0x2e, 0x18, 0x2, 
    0x258, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0xc, 0x3, 0x2, 0x2, 
    0x25a, 0x25b, 0x7, 0x58, 0x2, 0x2, 0x25b, 0x25d, 0x5, 0x2e, 0x18, 0x2, 
    0x25c, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x260, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x25f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x261, 
    0x262, 0x8, 0x1a, 0x1, 0x2, 0x262, 0x263, 0x5, 0x30, 0x19, 0x2, 0x263, 
    0x269, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0xc, 0x3, 0x2, 0x2, 0x265, 
    0x266, 0x7, 0x59, 0x2, 0x2, 0x266, 0x268, 0x5, 0x30, 0x19, 0x2, 0x267, 
    0x264, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x269, 
    0x267, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26a, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x272, 
    0x5, 0x32, 0x1a, 0x2, 0x26d, 0x26e, 0x7, 0x5d, 0x2, 0x2, 0x26e, 0x26f, 
    0x5, 0x3a, 0x1e, 0x2, 0x26f, 0x270, 0x7, 0x5e, 0x2, 0x2, 0x270, 0x271, 
    0x5, 0x34, 0x1b, 0x2, 0x271, 0x273, 0x3, 0x2, 0x2, 0x2, 0x272, 0x26d, 
    0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 0x273, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x274, 0x27b, 0x5, 0x34, 0x1b, 0x2, 0x275, 0x276, 0x5, 
    0x1a, 0xe, 0x2, 0x276, 0x277, 0x5, 0x38, 0x1d, 0x2, 0x277, 0x278, 0x5, 
    0x36, 0x1c, 0x2, 0x278, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27b, 0x7, 
    0x73, 0x2, 0x2, 0x27a, 0x274, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x275, 0x3, 
    0x2, 0x2, 0x2, 0x27a, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x27c, 0x27d, 0x9, 0x5, 0x2, 0x2, 0x27d, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x27e, 0x27f, 0x8, 0x1e, 0x1, 0x2, 0x27f, 0x280, 0x5, 0x36, 0x1c, 
    0x2, 0x280, 0x286, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0xc, 0x3, 0x2, 
    0x2, 0x282, 0x283, 0x7, 0x60, 0x2, 0x2, 0x283, 0x285, 0x5, 0x36, 0x1c, 
    0x2, 0x284, 0x281, 0x3, 0x2, 0x2, 0x2, 0x285, 0x288, 0x3, 0x2, 0x2, 
    0x2, 0x286, 0x284, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x3, 0x2, 0x2, 
    0x2, 0x287, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x288, 0x286, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x28a, 0x5, 0x34, 0x1b, 0x2, 0x28a, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x28b, 0x28c, 0x5, 0x40, 0x21, 0x2, 0x28c, 0x28d, 0x5, 0x46, 0x24, 0x2, 
    0x28d, 0x28e, 0x7, 0x5f, 0x2, 0x2, 0x28e, 0x294, 0x3, 0x2, 0x2, 0x2, 
    0x28f, 0x290, 0x5, 0x40, 0x21, 0x2, 0x290, 0x291, 0x7, 0x5f, 0x2, 0x2, 
    0x291, 0x294, 0x3, 0x2, 0x2, 0x2, 0x292, 0x294, 0x5, 0x98, 0x4d, 0x2, 
    0x293, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x293, 0x28f, 0x3, 0x2, 0x2, 0x2, 
    0x293, 0x292, 0x3, 0x2, 0x2, 0x2, 0x294, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x295, 
    0x297, 0x5, 0x44, 0x23, 0x2, 0x296, 0x295, 0x3, 0x2, 0x2, 0x2, 0x297, 
    0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x298, 
    0x299, 0x3, 0x2, 0x2, 0x2, 0x299, 0x41, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29c, 
    0x5, 0x44, 0x23, 0x2, 0x29b, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 
    0x3, 0x2, 0x2, 0x2, 0x29d, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 
    0x3, 0x2, 0x2, 0x2, 0x29e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a5, 0x5, 
    0x4a, 0x26, 0x2, 0x2a0, 0x2a5, 0x5, 0x4c, 0x27, 0x2, 0x2a1, 0x2a5, 0x5, 
    0x66, 0x34, 0x2, 0x2a2, 0x2a5, 0x5, 0x68, 0x35, 0x2, 0x2a3, 0x2a5, 0x5, 
    0x6a, 0x36, 0x2, 0x2a4, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a0, 0x3, 
    0x2, 0x2, 0x2, 0x2a4, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a2, 0x3, 
    0x2, 0x2, 0x2, 0x2a4, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x2a6, 0x2a7, 0x8, 0x24, 0x1, 0x2, 0x2a7, 0x2a8, 0x5, 0x48, 
    0x25, 0x2, 0x2a8, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0xc, 0x3, 
    0x2, 0x2, 0x2aa, 0x2ab, 0x7, 0x60, 0x2, 0x2, 0x2ab, 0x2ad, 0x5, 0x48, 
    0x25, 0x2, 0x2ac, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2b0, 0x3, 0x2, 
    0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 0x3, 0x2, 
    0x2, 0x2, 0x2af, 0x47, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 0x2, 
    0x2, 0x2b1, 0x2b7, 0x5, 0x6c, 0x37, 0x2, 0x2b2, 0x2b3, 0x5, 0x6c, 0x37, 
    0x2, 0x2b3, 0x2b4, 0x7, 0x61, 0x2, 0x2, 0x2b4, 0x2b5, 0x5, 0x8e, 0x48, 
    0x2, 0x2b5, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b1, 0x3, 0x2, 0x2, 
    0x2, 0x2b6, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x2b8, 0x2b9, 0x9, 0x6, 0x2, 0x2, 0x2b9, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x2ba, 
    0x2c9, 0x9, 0x7, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x3, 0x2, 0x2, 0x2bc, 
    0x2bd, 0x7, 0x43, 0x2, 0x2, 0x2bd, 0x2be, 0x9, 0x8, 0x2, 0x2, 0x2be, 
    0x2c9, 0x7, 0x44, 0x2, 0x2, 0x2bf, 0x2c9, 0x5, 0x64, 0x33, 0x2, 0x2c0, 
    0x2c9, 0x5, 0x4e, 0x28, 0x2, 0x2c1, 0x2c9, 0x5, 0x5c, 0x2f, 0x2, 0x2c2, 
    0x2c9, 0x5, 0x8c, 0x47, 0x2, 0x2c3, 0x2c4, 0x7, 0x9, 0x2, 0x2, 0x2c4, 
    0x2c5, 0x7, 0x43, 0x2, 0x2, 0x2c5, 0x2c6, 0x5, 0x3c, 0x1f, 0x2, 0x2c6, 
    0x2c7, 0x7, 0x44, 0x2, 0x2, 0x2c7, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cc, 
    0x5, 0x50, 0x29, 0x2, 0x2cb, 0x2cd, 0x7, 0x71, 0x2, 0x2, 0x2cc, 0x2cb, 
    0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 
    0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0x7, 0x47, 0x2, 0x2, 0x2cf, 0x2d0, 
    0x5, 0x52, 0x2a, 0x2, 0x2d0, 0x2d1, 0x7, 0x48, 0x2, 0x2, 0x2d1, 0x2d6, 
    0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d3, 0x5, 0x50, 0x29, 0x2, 0x2d3, 0x2d4, 
    0x7, 0x71, 0x2, 0x2, 0x2d4, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2ca, 
    0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x9, 0x9, 0x2, 0x2, 0x2d8, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x2d9, 0x2da, 0x8, 0x2a, 0x1, 0x2, 0x2da, 0x2db, 0x5, 0x54, 
    0x2b, 0x2, 0x2db, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0xc, 0x3, 
    0x2, 0x2, 0x2dd, 0x2df, 0x5, 0x54, 0x2b, 0x2, 0x2de, 0x2dc, 0x3, 0x2, 
    0x2, 0x2, 0x2df, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x2e2, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e5, 0x5, 0x56, 0x2c, 
    0x2, 0x2e4, 0x2e6, 0x5, 0x58, 0x2d, 0x2, 0x2e5, 0x2e4, 0x3, 0x2, 0x2, 
    0x2, 0x2e5, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x3, 0x2, 0x2, 
    0x2, 0x2e7, 0x2e8, 0x7, 0x5f, 0x2, 0x2, 0x2e8, 0x2eb, 0x3, 0x2, 0x2, 
    0x2, 0x2e9, 0x2eb, 0x5, 0x98, 0x4d, 0x2, 0x2ea, 0x2e3, 0x3, 0x2, 0x2, 
    0x2, 0x2ea, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x2ec, 0x2ee, 0x5, 0x4c, 0x27, 0x2, 0x2ed, 0x2ef, 0x5, 0x56, 0x2c, 0x2, 
    0x2ee, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x3, 0x2, 0x2, 0x2, 
    0x2ef, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 0x5, 0x66, 0x34, 0x2, 
    0x2f1, 0x2f3, 0x5, 0x56, 0x2c, 0x2, 0x2f2, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
    0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f5, 0x3, 0x2, 0x2, 0x2, 
    0x2f4, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f0, 0x3, 0x2, 0x2, 0x2, 
    0x2f5, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x8, 0x2d, 0x1, 0x2, 
    0x2f7, 0x2f8, 0x5, 0x5a, 0x2e, 0x2, 0x2f8, 0x2fe, 0x3, 0x2, 0x2, 0x2, 
    0x2f9, 0x2fa, 0xc, 0x3, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x60, 0x2, 0x2, 
    0x2fb, 0x2fd, 0x5, 0x5a, 0x2e, 0x2, 0x2fc, 0x2f9, 0x3, 0x2, 0x2, 0x2, 
    0x2fd, 0x300, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 0x2, 0x2, 
    0x2fe, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x59, 0x3, 0x2, 0x2, 0x2, 0x300, 
    0x2fe, 0x3, 0x2, 0x2, 0x2, 0x301, 0x308, 0x5, 0x6c, 0x37, 0x2, 0x302, 
    0x304, 0x5, 0x6c, 0x37, 0x2, 0x303, 0x302, 0x3, 0x2, 0x2, 0x2, 0x303, 
    0x304, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 0x3, 0x2, 0x2, 0x2, 0x305, 
    0x306, 0x7, 0x5e, 0x2, 0x2, 0x306, 0x308, 0x5, 0x3c, 0x1f, 0x2, 0x307, 
    0x301, 0x3, 0x2, 0x2, 0x2, 0x307, 0x303, 0x3, 0x2, 0x2, 0x2, 0x308, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30b, 0x7, 0x21, 0x2, 0x2, 0x30a, 
    0x30c, 0x7, 0x71, 0x2, 0x2, 0x30b, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x30c, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 
    0x30e, 0x7, 0x47, 0x2, 0x2, 0x30e, 0x30f, 0x5, 0x5e, 0x30, 0x2, 0x30f, 
    0x310, 0x7, 0x48, 0x2, 0x2, 0x310, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x311, 
    0x313, 0x7, 0x21, 0x2, 0x2, 0x312, 0x314, 0x7, 0x71, 0x2, 0x2, 0x313, 
    0x312, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x3, 0x2, 0x2, 0x2, 0x314, 
    0x315, 0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 0x7, 0x47, 0x2, 0x2, 0x316, 
    0x317, 0x5, 0x5e, 0x30, 0x2, 0x317, 0x318, 0x7, 0x60, 0x2, 0x2, 0x318, 
    0x319, 0x7, 0x48, 0x2, 0x2, 0x319, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31a, 
    0x31b, 0x7, 0x21, 0x2, 0x2, 0x31b, 0x31d, 0x7, 0x71, 0x2, 0x2, 0x31c, 
    0x309, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x311, 0x3, 0x2, 0x2, 0x2, 0x31c, 
    0x31a, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 
    0x8, 0x30, 0x1, 0x2, 0x31f, 0x320, 0x5, 0x60, 0x31, 0x2, 0x320, 0x326, 
    0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0xc, 0x3, 0x2, 0x2, 0x322, 0x323, 
    0x7, 0x60, 0x2, 0x2, 0x323, 0x325, 0x5, 0x60, 0x31, 0x2, 0x324, 0x321, 
    0x3, 0x2, 0x2, 0x2, 0x325, 0x328, 0x3, 0x2, 0x2, 0x2, 0x326, 0x324, 
    0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 0x3, 0x2, 0x2, 0x2, 0x327, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x328, 0x326, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32f, 0x5, 
    0x62, 0x32, 0x2, 0x32a, 0x32b, 0x5, 0x62, 0x32, 0x2, 0x32b, 0x32c, 0x7, 
    0x61, 0x2, 0x2, 0x32c, 0x32d, 0x5, 0x3c, 0x1f, 0x2, 0x32d, 0x32f, 0x3, 
    0x2, 0x2, 0x2, 0x32e, 0x329, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32a, 0x3, 
    0x2, 0x2, 0x2, 0x32f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 0x7, 0x71, 
    0x2, 0x2, 0x331, 0x63, 0x3, 0x2, 0x2, 0x2, 0x332, 0x333, 0x7, 0x3b, 
    0x2, 0x2, 0x333, 0x334, 0x7, 0x43, 0x2, 0x2, 0x334, 0x335, 0x5, 0x86, 
    0x44, 0x2, 0x335, 0x336, 0x7, 0x44, 0x2, 0x2, 0x336, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x337, 0x338, 0x9, 0xa, 0x2, 0x2, 0x338, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x339, 0x340, 0x9, 0xb, 0x2, 0x2, 0x33a, 0x340, 0x5, 0x72, 0x3a, 
    0x2, 0x33b, 0x33c, 0x7, 0xc, 0x2, 0x2, 0x33c, 0x33d, 0x7, 0x43, 0x2, 
    0x2, 0x33d, 0x33e, 0x7, 0x71, 0x2, 0x2, 0x33e, 0x340, 0x7, 0x44, 0x2, 
    0x2, 0x33f, 0x339, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x33a, 0x3, 0x2, 0x2, 
    0x2, 0x33f, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x340, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x341, 0x342, 0x7, 0x39, 0x2, 0x2, 0x342, 0x343, 0x7, 0x43, 0x2, 0x2, 
    0x343, 0x344, 0x5, 0x86, 0x44, 0x2, 0x344, 0x345, 0x7, 0x44, 0x2, 0x2, 
    0x345, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x346, 0x347, 0x7, 0x39, 0x2, 0x2, 
    0x347, 0x348, 0x7, 0x43, 0x2, 0x2, 0x348, 0x349, 0x5, 0x3c, 0x1f, 0x2, 
    0x349, 0x34a, 0x7, 0x44, 0x2, 0x2, 0x34a, 0x34c, 0x3, 0x2, 0x2, 0x2, 
    0x34b, 0x341, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x346, 0x3, 0x2, 0x2, 0x2, 
    0x34c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34f, 0x5, 0x7a, 0x3e, 0x2, 
    0x34e, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34f, 0x3, 0x2, 0x2, 0x2, 
    0x34f, 0x350, 0x3, 0x2, 0x2, 0x2, 0x350, 0x354, 0x5, 0x6e, 0x38, 0x2, 
    0x351, 0x353, 0x5, 0x70, 0x39, 0x2, 0x352, 0x351, 0x3, 0x2, 0x2, 0x2, 
    0x353, 0x356, 0x3, 0x2, 0x2, 0x2, 0x354, 0x352, 0x3, 0x2, 0x2, 0x2, 
    0x354, 0x355, 0x3, 0x2, 0x2, 0x2, 0x355, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x356, 
    0x354, 0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 0x8, 0x38, 0x1, 0x2, 0x358, 
    0x361, 0x7, 0x71, 0x2, 0x2, 0x359, 0x35a, 0x7, 0x43, 0x2, 0x2, 0x35a, 
    0x35b, 0x5, 0x6c, 0x37, 0x2, 0x35b, 0x35c, 0x7, 0x44, 0x2, 0x2, 0x35c, 
    0x361, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x7, 0x71, 0x2, 0x2, 0x35e, 
    0x35f, 0x7, 0x5e, 0x2, 0x2, 0x35f, 0x361, 0x7, 0x73, 0x2, 0x2, 0x360, 
    0x357, 0x3, 0x2, 0x2, 0x2, 0x360, 0x359, 0x3, 0x2, 0x2, 0x2, 0x360, 
    0x35d, 0x3, 0x2, 0x2, 0x2, 0x361, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x362, 
    0x363, 0xc, 0x9, 0x2, 0x2, 0x363, 0x365, 0x7, 0x45, 0x2, 0x2, 0x364, 
    0x366, 0x5, 0x7c, 0x3f, 0x2, 0x365, 0x364, 0x3, 0x2, 0x2, 0x2, 0x365, 
    0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 0x368, 0x3, 0x2, 0x2, 0x2, 0x367, 
    0x369, 0x5, 0x36, 0x1c, 0x2, 0x368, 0x367, 0x3, 0x2, 0x2, 0x2, 0x368, 
    0x369, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36a, 
    0x38e, 0x7, 0x46, 0x2, 0x2, 0x36b, 0x36c, 0xc, 0x8, 0x2, 0x2, 0x36c, 
    0x36d, 0x7, 0x45, 0x2, 0x2, 0x36d, 0x36f, 0x7, 0x30, 0x2, 0x2, 0x36e, 
    0x370, 0x5, 0x7c, 0x3f, 0x2, 0x36f, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36f, 
    0x370, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x3, 0x2, 0x2, 0x2, 0x371, 
    0x372, 0x5, 0x36, 0x1c, 0x2, 0x372, 0x373, 0x7, 0x46, 0x2, 0x2, 0x373, 
    0x38e, 0x3, 0x2, 0x2, 0x2, 0x374, 0x375, 0xc, 0x7, 0x2, 0x2, 0x375, 
    0x376, 0x7, 0x45, 0x2, 0x2, 0x376, 0x377, 0x5, 0x7c, 0x3f, 0x2, 0x377, 
    0x378, 0x7, 0x30, 0x2, 0x2, 0x378, 0x379, 0x5, 0x36, 0x1c, 0x2, 0x379, 
    0x37a, 0x7, 0x46, 0x2, 0x2, 0x37a, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x37b, 
    0x37c, 0xc, 0x6, 0x2, 0x2, 0x37c, 0x37e, 0x7, 0x45, 0x2, 0x2, 0x37d, 
    0x37f, 0x5, 0x7c, 0x3f, 0x2, 0x37e, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37e, 
    0x37f, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x3, 0x2, 0x2, 0x2, 0x380, 
    0x381, 0x7, 0x53, 0x2, 0x2, 0x381, 0x38e, 0x7, 0x46, 0x2, 0x2, 0x382, 
    0x383, 0xc, 0x5, 0x2, 0x2, 0x383, 0x384, 0x7, 0x43, 0x2, 0x2, 0x384, 
    0x385, 0x5, 0x7e, 0x40, 0x2, 0x385, 0x386, 0x7, 0x44, 0x2, 0x2, 0x386, 
    0x38e, 0x3, 0x2, 0x2, 0x2, 0x387, 0x388, 0xc, 0x4, 0x2, 0x2, 0x388, 
    0x38a, 0x7, 0x43, 0x2, 0x2, 0x389, 0x38b, 0x5, 0x84, 0x43, 0x2, 0x38a, 
    0x389, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38b, 
    0x38c, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38e, 0x7, 0x44, 0x2, 0x2, 0x38d, 
    0x362, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x38d, 
    0x374, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x38d, 
    0x382, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x387, 0x3, 0x2, 0x2, 0x2, 0x38e, 
    0x391, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38f, 
    0x390, 0x3, 0x2, 0x2, 0x2, 0x390, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x391, 0x38f, 
    0x3, 0x2, 0x2, 0x2, 0x392, 0x393, 0x7, 0xd, 0x2, 0x2, 0x393, 0x395, 
    0x7, 0x43, 0x2, 0x2, 0x394, 0x396, 0x7, 0x74, 0x2, 0x2, 0x395, 0x394, 
    0x3, 0x2, 0x2, 0x2, 0x396, 0x397, 0x3, 0x2, 0x2, 0x2, 0x397, 0x395, 
    0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x3, 0x2, 0x2, 0x2, 0x398, 0x399, 
    0x3, 0x2, 0x2, 0x2, 0x399, 0x39c, 0x7, 0x44, 0x2, 0x2, 0x39a, 0x39c, 
    0x5, 0x72, 0x3a, 0x2, 0x39b, 0x392, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39a, 
    0x3, 0x2, 0x2, 0x2, 0x39c, 0x71, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x7, 
    0xe, 0x2, 0x2, 0x39e, 0x39f, 0x7, 0x43, 0x2, 0x2, 0x39f, 0x3a0, 0x7, 
    0x43, 0x2, 0x2, 0x3a0, 0x3a1, 0x5, 0x74, 0x3b, 0x2, 0x3a1, 0x3a2, 0x7, 
    0x44, 0x2, 0x2, 0x3a2, 0x3a3, 0x7, 0x44, 0x2, 0x2, 0x3a3, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x3a4, 0x3a9, 0x5, 0x76, 0x3c, 0x2, 0x3a5, 0x3a6, 0x7, 
    0x60, 0x2, 0x2, 0x3a6, 0x3a8, 0x5, 0x76, 0x3c, 0x2, 0x3a7, 0x3a5, 0x3, 
    0x2, 0x2, 0x2, 0x3a8, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3a7, 0x3, 
    0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ae, 0x3, 
    0x2, 0x2, 0x2, 0x3ab, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ae, 0x3, 
    0x2, 0x2, 0x2, 0x3ad, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3ac, 0x3, 
    0x2, 0x2, 0x2, 0x3ae, 0x75, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b5, 0xa, 0xc, 
    0x2, 0x2, 0x3b0, 0x3b2, 0x7, 0x43, 0x2, 0x2, 0x3b1, 0x3b3, 0x5, 0x18, 
    0xd, 0x2, 0x3b2, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x3, 0x2, 
    0x2, 0x2, 0x3b3, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b6, 0x7, 0x44, 
    0x2, 0x2, 0x3b5, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b6, 0x3, 0x2, 
    0x2, 0x2, 0x3b6, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b9, 0x3, 0x2, 
    0x2, 0x2, 0x3b8, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b7, 0x3, 0x2, 
    0x2, 0x2, 0x3b9, 0x77, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3c0, 0xa, 0xd, 0x2, 
    0x2, 0x3bb, 0x3bc, 0x7, 0x43, 0x2, 0x2, 0x3bc, 0x3bd, 0x5, 0x78, 0x3d, 
    0x2, 0x3bd, 0x3be, 0x7, 0x44, 0x2, 0x2, 0x3be, 0x3c0, 0x3, 0x2, 0x2, 
    0x2, 0x3bf, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3bb, 0x3, 0x2, 0x2, 
    0x2, 0x3c0, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3bf, 0x3, 0x2, 0x2, 
    0x2, 0x3c1, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x3c3, 0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c6, 0x7, 0x53, 0x2, 0x2, 
    0x3c5, 0x3c7, 0x5, 0x7c, 0x3f, 0x2, 0x3c6, 0x3c5, 0x3, 0x2, 0x2, 0x2, 
    0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3d7, 0x3, 0x2, 0x2, 0x2, 
    0x3c8, 0x3ca, 0x7, 0x53, 0x2, 0x2, 0x3c9, 0x3cb, 0x5, 0x7c, 0x3f, 0x2, 
    0x3ca, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cb, 0x3, 0x2, 0x2, 0x2, 
    0x3cb, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3d7, 0x5, 0x7a, 0x3e, 0x2, 
    0x3cd, 0x3cf, 0x7, 0x5a, 0x2, 0x2, 0x3ce, 0x3d0, 0x5, 0x7c, 0x3f, 0x2, 
    0x3cf, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d0, 0x3, 0x2, 0x2, 0x2, 
    0x3d0, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d3, 0x7, 0x5a, 0x2, 0x2, 
    0x3d2, 0x3d4, 0x5, 0x7c, 0x3f, 0x2, 0x3d3, 0x3d2, 0x3, 0x2, 0x2, 0x2, 
    0x3d3, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d5, 0x3, 0x2, 0x2, 0x2, 
    0x3d5, 0x3d7, 0x5, 0x7a, 0x3e, 0x2, 0x3d6, 0x3c4, 0x3, 0x2, 0x2, 0x2, 
    0x3d6, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3cd, 0x3, 0x2, 0x2, 0x2, 
    0x3d6, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x3d8, 
    0x3d9, 0x8, 0x3f, 0x1, 0x2, 0x3d9, 0x3da, 0x5, 0x66, 0x34, 0x2, 0x3da, 
    0x3df, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0xc, 0x3, 0x2, 0x2, 0x3dc, 
    0x3de, 0x5, 0x66, 0x34, 0x2, 0x3dd, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3de, 
    0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3df, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3df, 
    0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3df, 
    0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e8, 0x5, 0x80, 0x41, 0x2, 0x3e3, 0x3e4, 
    0x5, 0x80, 0x41, 0x2, 0x3e4, 0x3e5, 0x7, 0x60, 0x2, 0x2, 0x3e5, 0x3e6, 
    0x7, 0x70, 0x2, 0x2, 0x3e6, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e2, 
    0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x8, 0x41, 0x1, 0x2, 0x3ea, 0x3eb, 0x5, 
    0x82, 0x42, 0x2, 0x3eb, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0xc, 
    0x3, 0x2, 0x2, 0x3ed, 0x3ee, 0x7, 0x60, 0x2, 0x2, 0x3ee, 0x3f0, 0x5, 
    0x82, 0x42, 0x2, 0x3ef, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3f3, 0x3, 
    0x2, 0x2, 0x2, 0x3f1, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 0x3, 
    0x2, 0x2, 0x2, 0x3f2, 0x81, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f1, 0x3, 0x2, 
    0x2, 0x2, 0x3f4, 0x3f5, 0x5, 0x40, 0x21, 0x2, 0x3f5, 0x3f6, 0x5, 0x6c, 
    0x37, 0x2, 0x3f6, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f9, 0x5, 0x42, 
    0x22, 0x2, 0x3f8, 0x3fa, 0x5, 0x88, 0x45, 0x2, 0x3f9, 0x3f8, 0x3, 0x2, 
    0x2, 0x2, 0x3f9, 0x3fa, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fc, 0x3, 0x2, 
    0x2, 0x2, 0x3fb, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3f7, 0x3, 0x2, 
    0x2, 0x2, 0x3fc, 0x83, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x8, 0x43, 
    0x1, 0x2, 0x3fe, 0x3ff, 0x7, 0x71, 0x2, 0x2, 0x3ff, 0x405, 0x3, 0x2, 
    0x2, 0x2, 0x400, 0x401, 0xc, 0x3, 0x2, 0x2, 0x401, 0x402, 0x7, 0x60, 
    0x2, 0x2, 0x402, 0x404, 0x7, 0x71, 0x2, 0x2, 0x403, 0x400, 0x3, 0x2, 
    0x2, 0x2, 0x404, 0x407, 0x3, 0x2, 0x2, 0x2, 0x405, 0x403, 0x3, 0x2, 
    0x2, 0x2, 0x405, 0x406, 0x3, 0x2, 0x2, 0x2, 0x406, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x407, 0x405, 0x3, 0x2, 0x2, 0x2, 0x408, 0x40a, 0x5, 0x56, 0x2c, 
    0x2, 0x409, 0x40b, 0x5, 0x88, 0x45, 0x2, 0x40a, 0x409, 0x3, 0x2, 0x2, 
    0x2, 0x40a, 0x40b, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x40c, 0x418, 0x5, 0x7a, 0x3e, 0x2, 0x40d, 0x40f, 0x5, 0x7a, 0x3e, 0x2, 
    0x40e, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x40f, 0x3, 0x2, 0x2, 0x2, 
    0x40f, 0x410, 0x3, 0x2, 0x2, 0x2, 0x410, 0x414, 0x5, 0x8a, 0x46, 0x2, 
    0x411, 0x413, 0x5, 0x70, 0x39, 0x2, 0x412, 0x411, 0x3, 0x2, 0x2, 0x2, 
    0x413, 0x416, 0x3, 0x2, 0x2, 0x2, 0x414, 0x412, 0x3, 0x2, 0x2, 0x2, 
    0x414, 0x415, 0x3, 0x2, 0x2, 0x2, 0x415, 0x418, 0x3, 0x2, 0x2, 0x2, 
    0x416, 0x414, 0x3, 0x2, 0x2, 0x2, 0x417, 0x40c, 0x3, 0x2, 0x2, 0x2, 
    0x417, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x418, 0x89, 0x3, 0x2, 0x2, 0x2, 0x419, 
    0x41a, 0x8, 0x46, 0x1, 0x2, 0x41a, 0x41b, 0x7, 0x43, 0x2, 0x2, 0x41b, 
    0x41c, 0x5, 0x88, 0x45, 0x2, 0x41c, 0x420, 0x7, 0x44, 0x2, 0x2, 0x41d, 
    0x41f, 0x5, 0x70, 0x39, 0x2, 0x41e, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41f, 
    0x422, 0x3, 0x2, 0x2, 0x2, 0x420, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x420, 
    0x421, 0x3, 0x2, 0x2, 0x2, 0x421, 0x448, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x420, 0x3, 0x2, 0x2, 0x2, 0x423, 0x425, 0x7, 0x45, 0x2, 0x2, 0x424, 
    0x426, 0x5, 0x7c, 0x3f, 0x2, 0x425, 0x424, 0x3, 0x2, 0x2, 0x2, 0x425, 
    0x426, 0x3, 0x2, 0x2, 0x2, 0x426, 0x428, 0x3, 0x2, 0x2, 0x2, 0x427, 
    0x429, 0x5, 0x36, 0x1c, 0x2, 0x428, 0x427, 0x3, 0x2, 0x2, 0x2, 0x428, 
    0x429, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42a, 
    0x448, 0x7, 0x46, 0x2, 0x2, 0x42b, 0x42c, 0x7, 0x45, 0x2, 0x2, 0x42c, 
    0x42e, 0x7, 0x30, 0x2, 0x2, 0x42d, 0x42f, 0x5, 0x7c, 0x3f, 0x2, 0x42e, 
    0x42d, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x42f, 
    0x430, 0x3, 0x2, 0x2, 0x2, 0x430, 0x431, 0x5, 0x36, 0x1c, 0x2, 0x431, 
    0x432, 0x7, 0x46, 0x2, 0x2, 0x432, 0x448, 0x3, 0x2, 0x2, 0x2, 0x433, 
    0x434, 0x7, 0x45, 0x2, 0x2, 0x434, 0x435, 0x5, 0x7c, 0x3f, 0x2, 0x435, 
    0x436, 0x7, 0x30, 0x2, 0x2, 0x436, 0x437, 0x5, 0x36, 0x1c, 0x2, 0x437, 
    0x438, 0x7, 0x46, 0x2, 0x2, 0x438, 0x448, 0x3, 0x2, 0x2, 0x2, 0x439, 
    0x43a, 0x7, 0x45, 0x2, 0x2, 0x43a, 0x43b, 0x7, 0x53, 0x2, 0x2, 0x43b, 
    0x448, 0x7, 0x46, 0x2, 0x2, 0x43c, 0x43e, 0x7, 0x43, 0x2, 0x2, 0x43d, 
    0x43f, 0x5, 0x7e, 0x40, 0x2, 0x43e, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x43e, 
    0x43f, 0x3, 0x2, 0x2, 0x2, 0x43f, 0x440, 0x3, 0x2, 0x2, 0x2, 0x440, 
    0x444, 0x7, 0x44, 0x2, 0x2, 0x441, 0x443, 0x5, 0x70, 0x39, 0x2, 0x442, 
    0x441, 0x3, 0x2, 0x2, 0x2, 0x443, 0x446, 0x3, 0x2, 0x2, 0x2, 0x444, 
    0x442, 0x3, 0x2, 0x2, 0x2, 0x444, 0x445, 0x3, 0x2, 0x2, 0x2, 0x445, 
    0x448, 0x3, 0x2, 0x2, 0x2, 0x446, 0x444, 0x3, 0x2, 0x2, 0x2, 0x447, 
    0x419, 0x3, 0x2, 0x2, 0x2, 0x447, 0x423, 0x3, 0x2, 0x2, 0x2, 0x447, 
    0x42b, 0x3, 0x2, 0x2, 0x2, 0x447, 0x433, 0x3, 0x2, 0x2, 0x2, 0x447, 
    0x439, 0x3, 0x2, 0x2, 0x2, 0x447, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x448, 
    0x474, 0x3, 0x2, 0x2, 0x2, 0x449, 0x44a, 0xc, 0x7, 0x2, 0x2, 0x44a, 
    0x44c, 0x7, 0x45, 0x2, 0x2, 0x44b, 0x44d, 0x5, 0x7c, 0x3f, 0x2, 0x44c, 
    0x44b, 0x3, 0x2, 0x2, 0x2, 0x44c, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x44d, 
    0x44f, 0x3, 0x2, 0x2, 0x2, 0x44e, 0x450, 0x5, 0x36, 0x1c, 0x2, 0x44f, 
    0x44e, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x450, 0x3, 0x2, 0x2, 0x2, 0x450, 
    0x451, 0x3, 0x2, 0x2, 0x2, 0x451, 0x473, 0x7, 0x46, 0x2, 0x2, 0x452, 
    0x453, 0xc, 0x6, 0x2, 0x2, 0x453, 0x454, 0x7, 0x45, 0x2, 0x2, 0x454, 
    0x456, 0x7, 0x30, 0x2, 0x2, 0x455, 0x457, 0x5, 0x7c, 0x3f, 0x2, 0x456, 
    0x455, 0x3, 0x2, 0x2, 0x2, 0x456, 0x457, 0x3, 0x2, 0x2, 0x2, 0x457, 
    0x458, 0x3, 0x2, 0x2, 0x2, 0x458, 0x459, 0x5, 0x36, 0x1c, 0x2, 0x459, 
    0x45a, 0x7, 0x46, 0x2, 0x2, 0x45a, 0x473, 0x3, 0x2, 0x2, 0x2, 0x45b, 
    0x45c, 0xc, 0x5, 0x2, 0x2, 0x45c, 0x45d, 0x7, 0x45, 0x2, 0x2, 0x45d, 
    0x45e, 0x5, 0x7c, 0x3f, 0x2, 0x45e, 0x45f, 0x7, 0x30, 0x2, 0x2, 0x45f, 
    0x460, 0x5, 0x36, 0x1c, 0x2, 0x460, 0x461, 0x7, 0x46, 0x2, 0x2, 0x461, 
    0x473, 0x3, 0x2, 0x2, 0x2, 0x462, 0x463, 0xc, 0x4, 0x2, 0x2, 0x463, 
    0x464, 0x7, 0x45, 0x2, 0x2, 0x464, 0x465, 0x7, 0x53, 0x2, 0x2, 0x465, 
    0x473, 0x7, 0x46, 0x2, 0x2, 0x466, 0x467, 0xc, 0x3, 0x2, 0x2, 0x467, 
    0x469, 0x7, 0x43, 0x2, 0x2, 0x468, 0x46a, 0x5, 0x7e, 0x40, 0x2, 0x469, 
    0x468, 0x3, 0x2, 0x2, 0x2, 0x469, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x46a, 
    0x46b, 0x3, 0x2, 0x2, 0x2, 0x46b, 0x46f, 0x7, 0x44, 0x2, 0x2, 0x46c, 
    0x46e, 0x5, 0x70, 0x39, 0x2, 0x46d, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x46e, 
    0x471, 0x3, 0x2, 0x2, 0x2, 0x46f, 0x46d, 0x3, 0x2, 0x2, 0x2, 0x46f, 
    0x470, 0x3, 0x2, 0x2, 0x2, 0x470, 0x473, 0x3, 0x2, 0x2, 0x2, 0x471, 
    0x46f, 0x3, 0x2, 0x2, 0x2, 0x472, 0x449, 0x3, 0x2, 0x2, 0x2, 0x472, 
    0x452, 0x3, 0x2, 0x2, 0x2, 0x472, 0x45b, 0x3, 0x2, 0x2, 0x2, 0x472, 
    0x462, 0x3, 0x2, 0x2, 0x2, 0x472, 0x466, 0x3, 0x2, 0x2, 0x2, 0x473, 
    0x476, 0x3, 0x2, 0x2, 0x2, 0x474, 0x472, 0x3, 0x2, 0x2, 0x2, 0x474, 
    0x475, 0x3, 0x2, 0x2, 0x2, 0x475, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x476, 0x474, 
    0x3, 0x2, 0x2, 0x2, 0x477, 0x478, 0x7, 0x71, 0x2, 0x2, 0x478, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x479, 0x484, 0x5, 0x36, 0x1c, 0x2, 0x47a, 0x47b, 
    0x7, 0x47, 0x2, 0x2, 0x47b, 0x47c, 0x5, 0x90, 0x49, 0x2, 0x47c, 0x47d, 
    0x7, 0x48, 0x2, 0x2, 0x47d, 0x484, 0x3, 0x2, 0x2, 0x2, 0x47e, 0x47f, 
    0x7, 0x47, 0x2, 0x2, 0x47f, 0x480, 0x5, 0x90, 0x49, 0x2, 0x480, 0x481, 
    0x7, 0x60, 0x2, 0x2, 0x481, 0x482, 0x7, 0x48, 0x2, 0x2, 0x482, 0x484, 
    0x3, 0x2, 0x2, 0x2, 0x483, 0x479, 0x3, 0x2, 0x2, 0x2, 0x483, 0x47a, 
    0x3, 0x2, 0x2, 0x2, 0x483, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x484, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x485, 0x487, 0x8, 0x49, 0x1, 0x2, 0x486, 0x488, 0x5, 
    0x92, 0x4a, 0x2, 0x487, 0x486, 0x3, 0x2, 0x2, 0x2, 0x487, 0x488, 0x3, 
    0x2, 0x2, 0x2, 0x488, 0x489, 0x3, 0x2, 0x2, 0x2, 0x489, 0x48a, 0x5, 
    0x8e, 0x48, 0x2, 0x48a, 0x493, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x48c, 0xc, 
    0x3, 0x2, 0x2, 0x48c, 0x48e, 0x7, 0x60, 0x2, 0x2, 0x48d, 0x48f, 0x5, 
    0x92, 0x4a, 0x2, 0x48e, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x48e, 0x48f, 0x3, 
    0x2, 0x2, 0x2, 0x48f, 0x490, 0x3, 0x2, 0x2, 0x2, 0x490, 0x492, 0x5, 
    0x8e, 0x48, 0x2, 0x491, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x492, 0x495, 0x3, 
    0x2, 0x2, 0x2, 0x493, 0x491, 0x3, 0x2, 0x2, 0x2, 0x493, 0x494, 0x3, 
    0x2, 0x2, 0x2, 0x494, 0x91, 0x3, 0x2, 0x2, 0x2, 0x495, 0x493, 0x3, 0x2, 
    0x2, 0x2, 0x496, 0x497, 0x5, 0x94, 0x4b, 0x2, 0x497, 0x498, 0x7, 0x61, 
    0x2, 0x2, 0x498, 0x93, 0x3, 0x2, 0x2, 0x2, 0x499, 0x49a, 0x8, 0x4b, 
    0x1, 0x2, 0x49a, 0x49b, 0x5, 0x96, 0x4c, 0x2, 0x49b, 0x4a0, 0x3, 0x2, 
    0x2, 0x2, 0x49c, 0x49d, 0xc, 0x3, 0x2, 0x2, 0x49d, 0x49f, 0x5, 0x96, 
    0x4c, 0x2, 0x49e, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x4a2, 0x3, 0x2, 
    0x2, 0x2, 0x4a0, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a1, 0x3, 0x2, 
    0x2, 0x2, 0x4a1, 0x95, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4a0, 0x3, 0x2, 0x2, 
    0x2, 0x4a3, 0x4a4, 0x7, 0x45, 0x2, 0x2, 0x4a4, 0x4a5, 0x5, 0x3c, 0x1f, 
    0x2, 0x4a5, 0x4a6, 0x7, 0x46, 0x2, 0x2, 0x4a6, 0x4aa, 0x3, 0x2, 0x2, 
    0x2, 0x4a7, 0x4a8, 0x7, 0x6f, 0x2, 0x2, 0x4a8, 0x4aa, 0x7, 0x71, 0x2, 
    0x2, 0x4a9, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0x4a9, 0x4a7, 0x3, 0x2, 0x2, 
    0x2, 0x4aa, 0x97, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ac, 0x7, 0x41, 0x2, 
    0x2, 0x4ac, 0x4ad, 0x7, 0x43, 0x2, 0x2, 0x4ad, 0x4ae, 0x5, 0x3c, 0x1f, 
    0x2, 0x4ae, 0x4b0, 0x7, 0x60, 0x2, 0x2, 0x4af, 0x4b1, 0x7, 0x74, 0x2, 
    0x2, 0x4b0, 0x4af, 0x3, 0x2, 0x2, 0x2, 0x4b1, 0x4b2, 0x3, 0x2, 0x2, 
    0x2, 0x4b2, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 0x3, 0x2, 0x2, 
    0x2, 0x4b3, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b5, 0x7, 0x44, 0x2, 
    0x2, 0x4b5, 0x4b6, 0x7, 0x5f, 0x2, 0x2, 0x4b6, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x4b7, 0x4dd, 0x5, 0x9c, 0x4f, 0x2, 0x4b8, 0x4dd, 0x5, 0x9e, 0x50, 
    0x2, 0x4b9, 0x4dd, 0x5, 0xa4, 0x53, 0x2, 0x4ba, 0x4dd, 0x5, 0xa6, 0x54, 
    0x2, 0x4bb, 0x4dd, 0x5, 0xa8, 0x55, 0x2, 0x4bc, 0x4dd, 0x5, 0xb0, 0x59, 
    0x2, 0x4bd, 0x4be, 0x9, 0xe, 0x2, 0x2, 0x4be, 0x4bf, 0x9, 0xf, 0x2, 
    0x2, 0x4bf, 0x4c8, 0x7, 0x43, 0x2, 0x2, 0x4c0, 0x4c5, 0x5, 0x32, 0x1a, 
    0x2, 0x4c1, 0x4c2, 0x7, 0x60, 0x2, 0x2, 0x4c2, 0x4c4, 0x5, 0x32, 0x1a, 
    0x2, 0x4c3, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4c4, 0x4c7, 0x3, 0x2, 0x2, 
    0x2, 0x4c5, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c6, 0x3, 0x2, 0x2, 
    0x2, 0x4c6, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4c7, 0x4c5, 0x3, 0x2, 0x2, 
    0x2, 0x4c8, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4c9, 0x3, 0x2, 0x2, 
    0x2, 0x4c9, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4d3, 0x7, 0x5e, 0x2, 
    0x2, 0x4cb, 0x4d0, 0x5, 0x32, 0x1a, 0x2, 0x4cc, 0x4cd, 0x7, 0x60, 0x2, 
    0x2, 0x4cd, 0x4cf, 0x5, 0x32, 0x1a, 0x2, 0x4ce, 0x4cc, 0x3, 0x2, 0x2, 
    0x2, 0x4cf, 0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4ce, 0x3, 0x2, 0x2, 
    0x2, 0x4d0, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4d4, 0x3, 0x2, 0x2, 
    0x2, 0x4d2, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d3, 0x4cb, 0x3, 0x2, 0x2, 
    0x2, 0x4d3, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d6, 0x3, 0x2, 0x2, 
    0x2, 0x4d5, 0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d9, 0x3, 0x2, 0x2, 
    0x2, 0x4d7, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d8, 0x3, 0x2, 0x2, 
    0x2, 0x4d8, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4d7, 0x3, 0x2, 0x2, 
    0x2, 0x4da, 0x4db, 0x7, 0x44, 0x2, 0x2, 0x4db, 0x4dd, 0x7, 0x5f, 0x2, 
    0x2, 0x4dc, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4b8, 0x3, 0x2, 0x2, 
    0x2, 0x4dc, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4ba, 0x3, 0x2, 0x2, 
    0x2, 0x4dc, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4bc, 0x3, 0x2, 0x2, 
    0x2, 0x4dc, 0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x4de, 0x4df, 0x7, 0x71, 0x2, 0x2, 0x4df, 0x4e0, 0x7, 0x5e, 0x2, 0x2, 
    0x4e0, 0x4ea, 0x5, 0x9a, 0x4e, 0x2, 0x4e1, 0x4e2, 0x7, 0x19, 0x2, 0x2, 
    0x4e2, 0x4e3, 0x5, 0x3c, 0x1f, 0x2, 0x4e3, 0x4e4, 0x7, 0x5e, 0x2, 0x2, 
    0x4e4, 0x4e5, 0x5, 0x9a, 0x4e, 0x2, 0x4e5, 0x4ea, 0x3, 0x2, 0x2, 0x2, 
    0x4e6, 0x4e7, 0x7, 0x1d, 0x2, 0x2, 0x4e7, 0x4e8, 0x7, 0x5e, 0x2, 0x2, 
    0x4e8, 0x4ea, 0x5, 0x9a, 0x4e, 0x2, 0x4e9, 0x4de, 0x3, 0x2, 0x2, 0x2, 
    0x4e9, 0x4e1, 0x3, 0x2, 0x2, 0x2, 0x4e9, 0x4e6, 0x3, 0x2, 0x2, 0x2, 
    0x4ea, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ed, 0x7, 0x47, 0x2, 0x2, 
    0x4ec, 0x4ee, 0x5, 0xa0, 0x51, 0x2, 0x4ed, 0x4ec, 0x3, 0x2, 0x2, 0x2, 
    0x4ed, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4ef, 0x3, 0x2, 0x2, 0x2, 
    0x4ef, 0x4f0, 0x7, 0x48, 0x2, 0x2, 0x4f0, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4f2, 0x8, 0x51, 0x1, 0x2, 0x4f2, 0x4f3, 0x5, 0xa2, 0x52, 0x2, 
    0x4f3, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f5, 0xc, 0x3, 0x2, 0x2, 
    0x4f5, 0x4f7, 0x5, 0xa2, 0x52, 0x2, 0x4f6, 0x4f4, 0x3, 0x2, 0x2, 0x2, 
    0x4f7, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 
    0x4f8, 0x4f9, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x4fa, 
    0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4fb, 0x4fe, 0x5, 0x3e, 0x20, 0x2, 0x4fc, 
    0x4fe, 0x5, 0x9a, 0x4e, 0x2, 0x4fd, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0x4fd, 
    0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x501, 
    0x5, 0x3a, 0x1e, 0x2, 0x500, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x500, 0x501, 
    0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 0x3, 0x2, 0x2, 0x2, 0x502, 0x503, 
    0x7, 0x5f, 0x2, 0x2, 0x503, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x504, 0x505, 
    0x7, 0x26, 0x2, 0x2, 0x505, 0x506, 0x7, 0x43, 0x2, 0x2, 0x506, 0x507, 
    0x5, 0x3a, 0x1e, 0x2, 0x507, 0x508, 0x7, 0x44, 0x2, 0x2, 0x508, 0x50b, 
    0x5, 0x9a, 0x4e, 0x2, 0x509, 0x50a, 0x7, 0x20, 0x2, 0x2, 0x50a, 0x50c, 
    0x5, 0x9a, 0x4e, 0x2, 0x50b, 0x509, 0x3, 0x2, 0x2, 0x2, 0x50b, 0x50c, 
    0x3, 0x2, 0x2, 0x2, 0x50c, 0x514, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x50e, 
    0x7, 0x32, 0x2, 0x2, 0x50e, 0x50f, 0x7, 0x43, 0x2, 0x2, 0x50f, 0x510, 
    0x5, 0x3a, 0x1e, 0x2, 0x510, 0x511, 0x7, 0x44, 0x2, 0x2, 0x511, 0x512, 
    0x5, 0x9a, 0x4e, 0x2, 0x512, 0x514, 0x3, 0x2, 0x2, 0x2, 0x513, 0x504, 
    0x3, 0x2, 0x2, 0x2, 0x513, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x514, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0x515, 0x516, 0x7, 0x38, 0x2, 0x2, 0x516, 0x517, 0x7, 
    0x43, 0x2, 0x2, 0x517, 0x518, 0x5, 0x3a, 0x1e, 0x2, 0x518, 0x519, 0x7, 
    0x44, 0x2, 0x2, 0x519, 0x51a, 0x5, 0x9a, 0x4e, 0x2, 0x51a, 0x52a, 0x3, 
    0x2, 0x2, 0x2, 0x51b, 0x51c, 0x7, 0x1e, 0x2, 0x2, 0x51c, 0x51d, 0x5, 
    0x9a, 0x4e, 0x2, 0x51d, 0x51e, 0x7, 0x38, 0x2, 0x2, 0x51e, 0x51f, 0x7, 
    0x43, 0x2, 0x2, 0x51f, 0x520, 0x5, 0x3a, 0x1e, 0x2, 0x520, 0x521, 0x7, 
    0x44, 0x2, 0x2, 0x521, 0x522, 0x7, 0x5f, 0x2, 0x2, 0x522, 0x52a, 0x3, 
    0x2, 0x2, 0x2, 0x523, 0x524, 0x7, 0x24, 0x2, 0x2, 0x524, 0x525, 0x7, 
    0x43, 0x2, 0x2, 0x525, 0x526, 0x5, 0xaa, 0x56, 0x2, 0x526, 0x527, 0x7, 
    0x44, 0x2, 0x2, 0x527, 0x528, 0x5, 0x9a, 0x4e, 0x2, 0x528, 0x52a, 0x3, 
    0x2, 0x2, 0x2, 0x529, 0x515, 0x3, 0x2, 0x2, 0x2, 0x529, 0x51b, 0x3, 
    0x2, 0x2, 0x2, 0x529, 0x523, 0x3, 0x2, 0x2, 0x2, 0x52a, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x52b, 0x52c, 0x5, 0xac, 0x57, 0x2, 0x52c, 0x52e, 0x7, 0x5f, 
    0x2, 0x2, 0x52d, 0x52f, 0x5, 0xae, 0x58, 0x2, 0x52e, 0x52d, 0x3, 0x2, 
    0x2, 0x2, 0x52e, 0x52f, 0x3, 0x2, 0x2, 0x2, 0x52f, 0x530, 0x3, 0x2, 
    0x2, 0x2, 0x530, 0x532, 0x7, 0x5f, 0x2, 0x2, 0x531, 0x533, 0x5, 0xae, 
    0x58, 0x2, 0x532, 0x531, 0x3, 0x2, 0x2, 0x2, 0x532, 0x533, 0x3, 0x2, 
    0x2, 0x2, 0x533, 0x540, 0x3, 0x2, 0x2, 0x2, 0x534, 0x536, 0x5, 0x3a, 
    0x1e, 0x2, 0x535, 0x534, 0x3, 0x2, 0x2, 0x2, 0x535, 0x536, 0x3, 0x2, 
    0x2, 0x2, 0x536, 0x537, 0x3, 0x2, 0x2, 0x2, 0x537, 0x539, 0x7, 0x5f, 
    0x2, 0x2, 0x538, 0x53a, 0x5, 0xae, 0x58, 0x2, 0x539, 0x538, 0x3, 0x2, 
    0x2, 0x2, 0x539, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x53a, 0x53b, 0x3, 0x2, 
    0x2, 0x2, 0x53b, 0x53d, 0x7, 0x5f, 0x2, 0x2, 0x53c, 0x53e, 0x5, 0xae, 
    0x58, 0x2, 0x53d, 0x53c, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x3, 0x2, 
    0x2, 0x2, 0x53e, 0x540, 0x3, 0x2, 0x2, 0x2, 0x53f, 0x52b, 0x3, 0x2, 
    0x2, 0x2, 0x53f, 0x535, 0x3, 0x2, 0x2, 0x2, 0x540, 0xab, 0x3, 0x2, 0x2, 
    0x2, 0x541, 0x542, 0x5, 0x40, 0x21, 0x2, 0x542, 0x543, 0x5, 0x46, 0x24, 
    0x2, 0x543, 0x546, 0x3, 0x2, 0x2, 0x2, 0x544, 0x546, 0x5, 0x40, 0x21, 
    0x2, 0x545, 0x541, 0x3, 0x2, 0x2, 0x2, 0x545, 0x544, 0x3, 0x2, 0x2, 
    0x2, 0x546, 0xad, 0x3, 0x2, 0x2, 0x2, 0x547, 0x548, 0x8, 0x58, 0x1, 
    0x2, 0x548, 0x549, 0x5, 0x36, 0x1c, 0x2, 0x549, 0x54f, 0x3, 0x2, 0x2, 
    0x2, 0x54a, 0x54b, 0xc, 0x3, 0x2, 0x2, 0x54b, 0x54c, 0x7, 0x60, 0x2, 
    0x2, 0x54c, 0x54e, 0x5, 0x36, 0x1c, 0x2, 0x54d, 0x54a, 0x3, 0x2, 0x2, 
    0x2, 0x54e, 0x551, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x54d, 0x3, 0x2, 0x2, 
    0x2, 0x54f, 0x550, 0x3, 0x2, 0x2, 0x2, 0x550, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0x551, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x552, 0x553, 0x7, 0x25, 0x2, 0x2, 
    0x553, 0x554, 0x7, 0x71, 0x2, 0x2, 0x554, 0x563, 0x7, 0x5f, 0x2, 0x2, 
    0x555, 0x556, 0x7, 0x1c, 0x2, 0x2, 0x556, 0x563, 0x7, 0x5f, 0x2, 0x2, 
    0x557, 0x558, 0x7, 0x18, 0x2, 0x2, 0x558, 0x563, 0x7, 0x5f, 0x2, 0x2, 
    0x559, 0x55b, 0x7, 0x2c, 0x2, 0x2, 0x55a, 0x55c, 0x5, 0x3a, 0x1e, 0x2, 
    0x55b, 0x55a, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x55c, 0x3, 0x2, 0x2, 0x2, 
    0x55c, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55d, 0x563, 0x7, 0x5f, 0x2, 0x2, 
    0x55e, 0x55f, 0x7, 0x25, 0x2, 0x2, 0x55f, 0x560, 0x5, 0x1a, 0xe, 0x2, 
    0x560, 0x561, 0x7, 0x5f, 0x2, 0x2, 0x561, 0x563, 0x3, 0x2, 0x2, 0x2, 
    0x562, 0x552, 0x3, 0x2, 0x2, 0x2, 0x562, 0x555, 0x3, 0x2, 0x2, 0x2, 
    0x562, 0x557, 0x3, 0x2, 0x2, 0x2, 0x562, 0x559, 0x3, 0x2, 0x2, 0x2, 
    0x562, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x563, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x564, 
    0x566, 0x5, 0xb4, 0x5b, 0x2, 0x565, 0x564, 0x3, 0x2, 0x2, 0x2, 0x565, 
    0x566, 0x3, 0x2, 0x2, 0x2, 0x566, 0x567, 0x3, 0x2, 0x2, 0x2, 0x567, 
    0x568, 0x7, 0x2, 0x2, 0x3, 0x568, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56a, 
    0x8, 0x5b, 0x1, 0x2, 0x56a, 0x56b, 0x5, 0xb6, 0x5c, 0x2, 0x56b, 0x570, 
    0x3, 0x2, 0x2, 0x2, 0x56c, 0x56d, 0xc, 0x3, 0x2, 0x2, 0x56d, 0x56f, 
    0x5, 0xb6, 0x5c, 0x2, 0x56e, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x56f, 0x572, 
    0x3, 0x2, 0x2, 0x2, 0x570, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x570, 0x571, 
    0x3, 0x2, 0x2, 0x2, 0x571, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x572, 0x570, 0x3, 
    0x2, 0x2, 0x2, 0x573, 0x577, 0x5, 0xb8, 0x5d, 0x2, 0x574, 0x577, 0x5, 
    0x3e, 0x20, 0x2, 0x575, 0x577, 0x7, 0x5f, 0x2, 0x2, 0x576, 0x573, 0x3, 
    0x2, 0x2, 0x2, 0x576, 0x574, 0x3, 0x2, 0x2, 0x2, 0x576, 0x575, 0x3, 
    0x2, 0x2, 0x2, 0x577, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x578, 0x57a, 0x5, 0x40, 
    0x21, 0x2, 0x579, 0x578, 0x3, 0x2, 0x2, 0x2, 0x579, 0x57a, 0x3, 0x2, 
    0x2, 0x2, 0x57a, 0x57b, 0x3, 0x2, 0x2, 0x2, 0x57b, 0x57d, 0x5, 0x6c, 
    0x37, 0x2, 0x57c, 0x57e, 0x5, 0xba, 0x5e, 0x2, 0x57d, 0x57c, 0x3, 0x2, 
    0x2, 0x2, 0x57d, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57f, 0x3, 0x2, 
    0x2, 0x2, 0x57f, 0x580, 0x5, 0x9e, 0x50, 0x2, 0x580, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0x581, 0x582, 0x8, 0x5e, 0x1, 0x2, 0x582, 0x583, 0x5, 0x3e, 
    0x20, 0x2, 0x583, 0x588, 0x3, 0x2, 0x2, 0x2, 0x584, 0x585, 0xc, 0x3, 
    0x2, 0x2, 0x585, 0x587, 0x5, 0x3e, 0x20, 0x2, 0x586, 0x584, 0x3, 0x2, 
    0x2, 0x2, 0x587, 0x58a, 0x3, 0x2, 0x2, 0x2, 0x588, 0x586, 0x3, 0x2, 
    0x2, 0x2, 0x588, 0x589, 0x3, 0x2, 0x2, 0x2, 0x589, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0x58a, 0x588, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xc1, 0xca, 0xde, 0xef, 
    0xf9, 0xfe, 0x105, 0x10a, 0x10f, 0x118, 0x11c, 0x120, 0x125, 0x12f, 
    0x134, 0x138, 0x13c, 0x141, 0x14d, 0x151, 0x155, 0x15a, 0x15f, 0x164, 
    0x169, 0x16e, 0x172, 0x19c, 0x1ad, 0x1af, 0x1ba, 0x1d3, 0x1e4, 0x1f2, 
    0x1f4, 0x200, 0x202, 0x20e, 0x210, 0x222, 0x224, 0x230, 0x232, 0x23d, 
    0x248, 0x253, 0x25e, 0x269, 0x272, 0x27a, 0x286, 0x293, 0x298, 0x29d, 
    0x2a4, 0x2ae, 0x2b6, 0x2c8, 0x2cc, 0x2d5, 0x2e0, 0x2e5, 0x2ea, 0x2ee, 
    0x2f2, 0x2f4, 0x2fe, 0x303, 0x307, 0x30b, 0x313, 0x31c, 0x326, 0x32e, 
    0x33f, 0x34b, 0x34e, 0x354, 0x360, 0x365, 0x368, 0x36f, 0x37e, 0x38a, 
    0x38d, 0x38f, 0x397, 0x39b, 0x3a9, 0x3ad, 0x3b2, 0x3b5, 0x3b8, 0x3bf, 
    0x3c1, 0x3c6, 0x3ca, 0x3cf, 0x3d3, 0x3d6, 0x3df, 0x3e7, 0x3f1, 0x3f9, 
    0x3fb, 0x405, 0x40a, 0x40e, 0x414, 0x417, 0x420, 0x425, 0x428, 0x42e, 
    0x43e, 0x444, 0x447, 0x44c, 0x44f, 0x456, 0x469, 0x46f, 0x472, 0x474, 
    0x483, 0x487, 0x48e, 0x493, 0x4a0, 0x4a9, 0x4b2, 0x4c5, 0x4c8, 0x4d0, 
    0x4d3, 0x4d7, 0x4dc, 0x4e9, 0x4ed, 0x4f8, 0x4fd, 0x500, 0x50b, 0x513, 
    0x529, 0x52e, 0x532, 0x535, 0x539, 0x53d, 0x53f, 0x545, 0x54f, 0x55b, 
    0x562, 0x565, 0x570, 0x576, 0x579, 0x57d, 0x588, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CParser::Initializer CParser::_init;
