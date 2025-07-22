#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "Token.h"

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> scanTokens();

private:
    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

    void scanToken();
    bool isAtEnd() const;
    char advance();
    bool match(char expected);
    char peek() const;
    void addToken(TokenType type);
    void addToken(TokenType type, const std::variant<int, double, std::string>& literal);
    void stringLiteral();
    void numberLiteral();
    void identifier();
    void skipWhitespace();
};

#endif
