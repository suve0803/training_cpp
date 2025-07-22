// Parser.cpp
#include "Parser.h"
#include <stdexcept>

void Parser::advance() {
    cur = lexer.getNextToken();
}

bool Parser::accept(TokenType t) {
    if (cur.type == t) { advance(); return true; }
    return false;
}

void Parser::expect(TokenType t) {
    if (!accept(t))
        throw std::runtime_error("Syntax error: expected " + Token::typeName(t));
}

std::unique_ptr<StatementNode> Parser::parse() {
    return parseStatement();
}

std::unique_ptr<StatementNode> Parser::parseStatement() {
    if (accept(TokenType::PRINT)) {
        auto expr = parseExpression();
        return std::make_unique<PrintNode>(std::move(expr));
    }
    if (cur.type == TokenType::IDENTIFIER) {
        std::string name = cur.value;
        advance();
        expect(TokenType::ASSIGN);
        auto expr = parseExpression();
        return std::make_unique<LetNode>(name, std::move(expr));
    }
    throw std::runtime_error("Unknown statement starting with: " + cur.value);
}

std::unique_ptr<ExpressionNode> Parser::parseExpression() {
    auto node = parseTerm();
    while (cur.type == TokenType::PLUS || cur.type == TokenType::MINUS) {
        char op = (cur.type == TokenType::PLUS ? '+' : '-');
        advance();
        auto rhs = parseTerm();
        node = std::make_unique<BinaryOpNode>(op, std::move(node), std::move(rhs));
    }
    return node;
}

std::unique_ptr<ExpressionNode> Parser::parseTerm() {
    auto node = parseFactor();
    while (cur.type == TokenType::STAR || cur.type == TokenType::SLASH) {
        char op = (cur.type == TokenType::STAR ? '*' : '/');
        advance();
        auto rhs = parseFactor();
        node = std::make_unique<BinaryOpNode>(op, std::move(node), std::move(rhs));
    }
    return node;
}

std::unique_ptr<ExpressionNode> Parser::parseFactor() {
    if (cur.type == TokenType::NUMBER) {
        double val = std::stod(cur.value);
        advance();
        return std::make_unique<NumberNode>(val);
    }
    if (cur.type == TokenType::IDENTIFIER) {
        std::string name = cur.value;
        advance();
        return std::make_unique<VariableNode>(name);
    }
    if (accept(TokenType::LPAREN)) {
        auto node = parseExpression();
        expect(TokenType::RPAREN);
        return node;
    }
    throw std::runtime_error("Syntax error in factor at: " + cur.value);
}
