#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source) : input(source), pos(0) {
    currentChar = pos < input.size() ? input[pos] : 0;
}

void Lexer::advance() {
    pos++;
    currentChar = pos < input.size() ? input[pos] : 0;
}

void Lexer::skipWhitespace() {
    while (currentChar && isspace(currentChar))
        advance();
}

Token Lexer::getNextToken() {
    skipWhitespace();

    if (currentChar == 0) {
        return Token{ TokenType::EndOfFile, "" };
    }

    if (currentChar == '"') {
        advance();
        std::string strVal;
        while (currentChar != '"' && currentChar != 0) {
            strVal += currentChar;
            advance();
        }
        if (currentChar == '"') advance();
        return Token{ TokenType::StringLiteral, strVal };
    }

    if (isalpha(currentChar) || currentChar == '_') {
        std::string id;
        while (isalnum(currentChar) || currentChar == '_') {
            id += currentChar;
            advance();
        }
        return Token{ TokenType::Identifier, id };
    }

    if (isdigit(currentChar)) {
        std::string num;
        while (isdigit(currentChar)) {
            num += currentChar;
            advance();
        }
        return Token{ TokenType::Number, num };
    }

    // Single-character symbol
    char sym = currentChar;
    advance();
    return Token{ TokenType::Symbol, std::string(1, sym) };
}
