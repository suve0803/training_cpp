// parser.cpp
#include "parser.h"
#include <iostream>
#include <algorithm>
Parser::Parser(const std::vector<std::string>& t) : tokens(t) {}

std::string Parser::peek() const {
    return pos < tokens.size() ? tokens[pos] : "";
}

bool Parser::match(const std::string& tok) {
    if (peek() == tok) { pos++; return true; }
    return false;
}

std::string Parser::consume() {
    std::string t = peek();
    if (pos < tokens.size()) pos++;
    return t;
}

std::vector<std::unique_ptr<Statement>> Parser::parseProgram() {
    std::vector<std::unique_ptr<Statement>> stmts;
    while (pos < tokens.size()) {
        stmts.push_back(parseStmt());
    }
    return stmts;
}

std::unique_ptr<Statement> Parser::parseStmt() {
    if (match("PRINT")) {
        auto e = parseExpr();
        return std::make_unique<PrintStmt>(std::move(e));
    }
    throw std::runtime_error("Unexpected token '" + peek() + "'");
}

std::unique_ptr<Expression> Parser::parseExpr() {
    std::string t = consume();
    if (std::all_of(t.begin(), t.end(), ::isdigit)) {
        return std::make_unique<IntegerLiteral>(std::stoi(t));
    }
    throw std::runtime_error("Unexpected term '" + t + "'");
}

