#pragma once
#include <string>

enum class TokenType {
    Identifier,
    Number,
    String,
    Keyword,
    Operator,
    EOL,
    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string text;

    Token(TokenType t, const std::string& txt) : type(t), text(txt) {}
};
