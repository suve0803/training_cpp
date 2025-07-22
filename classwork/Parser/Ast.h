// Ast.h
#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <memory>

struct ASTNode { virtual ~ASTNode() = default; };

struct Expression : ASTNode {
    virtual int evaluate() const = 0;
};

struct IntegerLiteral : Expression {
    int value;
    IntegerLiteral(int v) : value(v) {}
    int evaluate() const override { return value; }
};

struct Statement : ASTNode {
    virtual void execute() const = 0;
};

struct PrintStmt : Statement {
    std::unique_ptr<Expression> expr;
    PrintStmt(std::unique_ptr<Expression> e) : expr(std::move(e)) {}
    void execute() const override { std::cout << expr->evaluate() << "\n"; }
};
