#include "Lexer.h"
#include <cctype>
#include <unordered_map>

static std::unordered_map<std::string, TokenType> keywords = {
    {"PRINT", TokenType::PRINT},
    {"INPUT", TokenType::INPUT},
    {"LET", TokenType::LET},
    {"IF", TokenType::IF},
    {"THEN", TokenType::THEN},
    {"GOTO", TokenType::GOTO},
    {"GOSUB", TokenType::GOSUB},
    {"RETURN", TokenType::RETURN},
    {"FOR", TokenType::FOR},
    {"NEXT", TokenType::NEXT},
    {"TO", TokenType::TO},
    {"STEP", TokenType::STEP},
    {"REM", TokenType::REM},
    {"END", TokenType::END}
};

Lexer::Lexer(const std::string& src) : source(src) {}

std::vector<Token> Lexer::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }
    tokens.emplace_back(TokenType::EOF_TOKEN, "", line);
    return tokens;
}

void Lexer::scanToken() {
    skipWhitespace();
    if (isAtEnd()) return;

    char c = advance();
    if (std::isdigit(c)) {
        numberLiteral();
    }
    else if (std::isalpha(c)) {
        identifier();
    }
    else {
        switch (c) {
        case '+': addToken(TokenType::PLUS); break;
        case '-': addToken(TokenType::MINUS); break;
        case '*': addToken(TokenType::STAR); break;
        case '/': addToken(TokenType::SLASH); break;
        case '=': addToken(TokenType::EQUAL); break;
        case ',': addToken(TokenType::COMMA); break;
        case ':': addToken(TokenType::COLON); break;
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '"': stringLiteral(); break;
        default:
            tokens.emplace_back(TokenType::ERROR, std::string(1, c), line);
        }
    }
}

bool Lexer::isAtEnd() const {
    return current >= source.size();
}

char Lexer::advance() {
    return source[current++];
}

bool Lexer::match(char expected) {
    if (isAtEnd() || source[current] != expected) return false;
    current++;
    return true;
}

char Lexer::peek() const {
    return isAtEnd() ? '\0' : source[current];
}

void Lexer::addToken(TokenType type) {
    tokens.emplace_back(type, source.substr(start, current - start), line);
}

void Lexer::addToken(TokenType type, const std::variant<int, double, std::string>& literal) {
    tokens.emplace_back(type, source.substr(start, current - start), line);
    tokens.back().literal = literal;
}

void Lexer::skipWhitespace() {
    while (!isAtEnd()) {
        char c = peek();
        if (c == ' ' || c == '\t' || c == '\r') {
            advance();
        }
        else {
            break;
        }
    }
}

void Lexer::stringLiteral() {
    while (!isAtEnd() && peek() != '"') advance();
    if (isAtEnd()) return;
    advance(); // Consume closing "
    std::string value = source.substr(start + 1, current - start - 2);
    addToken(TokenType::STRING, value);
}

void Lexer::numberLiteral() {
    while (!isAtEnd() && std::isdigit(peek())) advance();
    std::string num = source.substr(start, current - start);
    addToken(TokenType::NUMBER, std::stoi(num));
}

void Lexer::identifier() {
    while (!isAtEnd() && std::isalnum(peek())) advance();
    std::string text = source.substr(start, current - start);
    if (keywords.count(text)) {
        addToken(keywords[text]);
    }
    else {
        addToken(TokenType::IDENTIFIER);
    }
}
