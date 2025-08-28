#pragma once
#include "../Lexer/Lexer.h"
#include "../AST/AST.h"

class Parser {
    Lexer& lexer;
    Token currentToken;

    void advance();
    ASTNodePtr parsePrimary();
    ASTNodePtr parseCallExpr(const std::string& calleeName);
public:
    explicit Parser(Lexer& lexer);
    ASTNodePtr parseExpression();
};
