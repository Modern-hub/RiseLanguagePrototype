#pragma once
#include <string>

enum class TokenType {
    Identifier,
    Number,
    StringLiteral,
    Symbol,
    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string value;
};
