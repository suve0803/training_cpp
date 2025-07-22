#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <variant>

enum class TokenType {
    NUMBER, STRING, IDENTIFIER,
    PRINT, INPUT, LET, IF, THEN, GOTO, GOSUB, RETURN, FOR, NEXT, TO, STEP, REM, END,
    PLUS, MINUS, STAR, SLASH, EQUAL, COMMA, COLON,
    LEFT_PAREN, RIGHT_PAREN,
    LINE_NUMBER,
    EOF_TOKEN, ERROR
};

struct Token {
    TokenType type;
    std::string lexeme;
    std::variant<int, double, std::string> literal;
    int line;

    Token(TokenType type, const std::string& lexeme, int line)
        : type(type), lexeme(lexeme), line(line) {}
};

#endif
