#pragma once
#include <string>
#include <memory>
#include <vector>

enum class ASTNodeType {
    PrintStmt,
    LetStmt,
    IfStmt,
    GotoStmt,
    Expression,
};

struct ASTNode {
    ASTNodeType type;
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;

    ASTNode(ASTNodeType t, const std::string& v) : type(t), value(v) {}
};
