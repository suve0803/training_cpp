#include "Lexer.h"
#include "parser.h"
#include "ASTNode.h"
#include <iostream>
#include <fstream>

// Recursive AST printer
void printAST(ASTNode* node, int indent = 0) {
    if (!node) return;

    std::string indentStr(indent, ' ');
    std::cout << indentStr;

    switch (node->type()) {
    case ASTType::Program: {
        std::cout << "Program\n";
        auto* prog = dynamic_cast<ProgramNode*>(node);
        for (auto* stmt : prog->stmts)
            printAST(stmt, indent + 2);
        break;
    }
    case ASTType::PrintStmt: {
        std::cout << "PrintStmt\n";
        auto* print = dynamic_cast<PrintNode*>(node);
        printAST(print->expr, indent + 2);
        break;
    }
    case ASTType::LetStmt: {
        auto* let = dynamic_cast<LetNode*>(node);
        std::cout << "LetStmt " << let->name << "\n";
        printAST(let->expr, indent + 2);
        break;
    }
    case ASTType::InputStmt: {
        auto* in = dynamic_cast<InputNode*>(node);
        std::cout << "InputStmt " << in->name << "\n";
        break;
    }
    case ASTType::NumberExpr: {
        auto* n = dynamic_cast<NumberNode*>(node);
        std::cout << "Number " << n->value << "\n";
        break;
    }
    case ASTType::IdentExpr: {
        auto* id = dynamic_cast<IdentNode*>(node);
        std::cout << "Ident " << id->name << "\n";
        break;
    }
    case ASTType::StringExpr: {
        auto* str = dynamic_cast<StringNode*>(node);
        std::cout << "String \"" << str->value << "\"\n";
        break;
    }
    case ASTType::BinOpExpr: {
        auto* bin = dynamic_cast<BinOpNode*>(node);
        std::cout << "BinOp '" << bin->op << "'\n";
        printAST(bin->left, indent + 2);
        printAST(bin->right, indent + 2);
        break;
    }
    case ASTType::IfElseStmt: {
        auto* iff = dynamic_cast<IfElseNode*>(node);
        std::cout << "IfElse " << iff->op << "\n";
        printAST(iff->left, indent + 2);
        printAST(iff->right, indent + 2);
        printAST(iff->thenStmt, indent + 2);
        if (iff->elseStmt) printAST(iff->elseStmt, indent + 2);
        break;
    }
    case ASTType::GotoStmt: {
        auto* go = dynamic_cast<GotoNode*>(node);
        std::cout << "Goto " << go->line << "\n";
        break;
    }
    case ASTType::ForStmt: {
        auto* f = dynamic_cast<ForNode*>(node);  
        std::cout << "For " << f->var << "\n";
        printAST(f->start, indent + 2);
        printAST(f->end, indent + 2);
        printAST(f->step, indent + 2);
        printAST(f->body, indent + 2);
        break;
    }
    case ASTType::MathFuncExpr: {
        auto* m = dynamic_cast<MathFuncNode*>(node);
        std::cout << "MathFunc " << m->func << "\n";
        printAST(m->argument, indent + 2);
        break;
    }

    case ASTType::DataStmt: {
        auto* d = dynamic_cast<DataNode*>(node);
        std::cout << "DATA ";
        for (const auto& val : d->values)
            std::cout << val << " ";
        std::cout << "\n";
        break;
    }
    case ASTType::ReadStmt: {
        auto* r = dynamic_cast<ReadNode*>(node);
        std::cout << "READ ";
        for (const auto& var : r->var)
            std::cout << var << " ";
        std::cout << "\n";
        break;
    }
    case ASTType::GosubStmt: {
        auto* g = dynamic_cast<GosubNode*>(node);
        std::cout << "GOSUB " << g->line << "\n";
        break;
    }

    case ASTType::DoLoopStmt: {
        auto* d = dynamic_cast<DoLoopNode*>(node);
        std::cout << "DoLoop" << (d->untilStyle ? " Until" : " While") << "\n";
        printAST(d->body, indent + 2);
        printAST(d->cond, indent + 2);
        break;
    }
    case ASTType::WhileStmt: {
        auto* w = dynamic_cast<WhileNode*>(node);
        std::cout << "While\n";
        printAST(w->cond, indent + 2);
        printAST(w->body, indent + 2);
        break;
    }
    case ASTType::CommandStmt: {
        auto* c = dynamic_cast<CommandNode*>(node);
        std::cout << "Command " << c->cmd;
        for (const auto& arg : c->args)
            std::cout << " " << arg;
        std::cout << "\n";
        break;
    }
    case ASTType::ReturnStmt: {
        std::cout << "Return\n";
        break;
    }
    case ASTType::StopStmt: {
        std::cout << "Stop\n";
        break;
    }
    
    default:
        std::cout << "(Other AST node type)\n";
        break;
    }
}

int main() {
    std::ifstream file("program.txt");
    if (!file) {
        std::cerr << "Error opening program.txt\n";
        return 1;
    }

    Lexer lexer;
    Parser parser;

    std::string line;
    while (std::getline(file, line)) {
        std::cout << "\n-- Input: " << line << "\n";
        try {
            std::vector<Token> tokens = lexer.tokenize(line);
            ASTNode* ast = parser.parse(tokens);
            printAST(ast);
            delete ast;
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\n";
            std::cerr << e.what() << "\n";
        }
    }

    return 0;
}
