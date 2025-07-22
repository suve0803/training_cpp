// parser.h
#pragma once
#include "Ast.h"
#include <string>
#include <vector>
#include <memory>

class Parser {
    const std::vector<std::string>& tokens;
    size_t pos = 0;
    std::string peek() const;
    bool match(const std::string& tok);
    std::string consume();
public:
    Parser(const std::vector<std::string>& tokens);
    std::vector<std::unique_ptr<Statement>> parseProgram();
private:
    std::unique_ptr<Statement> parseStmt();
    std::unique_ptr<Expression> parseExpr();
};
