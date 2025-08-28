#include "Parser.h"
#include <iostream>

Parser::Parser(Lexer& lex) : lexer(lex) {
    advance();
}

void Parser::advance() {
    currentToken = lexer.getNextToken();
}

ASTNodePtr Parser::parsePrimary() {
    if (currentToken.type == TokenType::Identifier) {
        std::string idName = currentToken.value;
        advance();

        if (currentToken.type == TokenType::Symbol && currentToken.value == "(") {
            return parseCallExpr(idName);
        }

        std::cerr << "Error: Unexpected token after identifier\n";
        return nullptr;
    }

    if (currentToken.type == TokenType::StringLiteral) {
        auto strNode = std::make_unique<StringExpr>(currentToken.value);
        advance();
        return strNode;
    }

    std::cerr << "Error: Unexpected token in primary expression\n";
    return nullptr;
}

ASTNodePtr Parser::parseCallExpr(const std::string& calleeName) {
    // consume '('
    advance();

    std::vector<ASTNodePtr> args;

    if (!(currentToken.type == TokenType::Symbol && currentToken.value == ")")) {
        while (true) {
            auto arg = parseExpression();
            if (!arg) return nullptr;
            args.push_back(std::move(arg));

            if (currentToken.type == TokenType::Symbol && currentToken.value == ")")
                break;

            if (!(currentToken.type == TokenType::Symbol && currentToken.value == ",")) {
                std::cerr << "Error: Expected ',' or ')'\n";
                return nullptr;
            }
            advance();
        }
    }

    // consume ')'
    advance();

    return std::make_unique<CallExpr>(calleeName, std::move(args));
}

ASTNodePtr Parser::parseExpression() {
    return parsePrimary();
}
