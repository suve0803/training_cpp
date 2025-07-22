#pragma once
#include "Token.h"
#include "ASTNode.h"
#include <vector>
#include <memory>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::vector<std::shared_ptr<ASTNode>> parse();

private:
    std::vector<Token> tokens;
    size_t pos = 0;

    Token peek();
    Token advance();
    bool match(TokenType type, const std::string& text = "");

    std::shared_ptr<ASTNode> parseStatement();
    std::shared_ptr<ASTNode> parsePrint();
    std::shared_ptr<ASTNode> parseLet();
    std::shared_ptr<ASTNode> parseIf();
    std::shared_ptr<ASTNode> parseGoto();
    std::shared_ptr<ASTNode> parseExpression();
};
