#pragma once
#include "Token.h"
#include <string>

class Lexer {
    const std::string& input;
    size_t pos = 0;
    char currentChar = 0;

    void advance();
    void skipWhitespace();
public:
    explicit Lexer(const std::string& source);
    Token getNextToken();
};
