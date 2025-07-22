#include "Parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& t) : tokens(t) {}

Token Parser::peek() {
    if (pos < tokens.size()) return tokens[pos];
    return Token(TokenType::EndOfFile, "");
}

Token Parser::advance() {
    if (pos < tokens.size()) return tokens[pos++];
    return Token(TokenType::EndOfFile, "");
}

bool Parser::match(TokenType type, const std::string& text) {
    if (peek().type == type && (text.empty() || peek().text == text)) {
        advance();
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<ASTNode>> Parser::parse() {
    std::vector<std::shared_ptr<ASTNode>> program;
    while (peek().type != TokenType::EndOfFile) {
        program.push_back(parseStatement());
    }
    return program;
}

std::shared_ptr<ASTNode> Parser::parseStatement() {
    if (match(TokenType::Keyword, "PRINT")) return parsePrint();
    if (match(TokenType::Keyword, "LET")) return parseLet();
    if (match(TokenType::Keyword, "IF")) return parseIf();
    if (match(TokenType::Keyword, "GOTO")) return parseGoto();
    throw std::runtime_error("Unknown statement");
}

std::shared_ptr<ASTNode> Parser::parsePrint() {
    auto node = std::make_shared<ASTNode>(ASTNodeType::PrintStmt, "PRINT");
    node->children.push_back(parseExpression());
    return node;
}

std::shared_ptr<ASTNode> Parser::parseLet() {
    Token var = advance();
    auto node = std::make_shared<ASTNode>(ASTNodeType::LetStmt, var.text);
    match(TokenType::Operator, "=");
    node->children.push_back(parseExpression());
    return node;
}

std::shared_ptr<ASTNode> Parser::parseIf() {
    auto node = std::make_shared<ASTNode>(ASTNodeType::IfStmt, "IF");
    node->children.push_back(parseExpression());
    match(TokenType::Keyword, "THEN");
    node->children.push_back(parseStatement());
    return node;
}

std::shared_ptr<ASTNode> Parser::parseGoto() {
    Token num = advance();
    auto node = std::make_shared<ASTNode>(ASTNodeType::GotoStmt, num.text);
    return node;
}

std::shared_ptr<ASTNode> Parser::parseExpression() {
    Token token = advance();
    return std::make_shared<ASTNode>(ASTNodeType::Expression, token.text);
}
