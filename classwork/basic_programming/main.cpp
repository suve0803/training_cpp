#include "Lexer.h"
#include "parser.h"
#include <iostream>
#include <vector>

void printAST(ASTNode* node, int indent = 0) {
    if (!node) return;
    std::string pad(indent, ' ');
    switch (node->type()) {
    case ASTType::Program: {
        std::cout << pad << "Program\n";
        for (ASTNode* s : static_cast<ProgramNode*>(node)->stmts) {
            printAST(s, indent + 2);
        }
        break;
    }
    case ASTType::ForStmt: {
        ForNode* fn = static_cast<ForNode*>(node);
        std::cout << std::string(indent, ' ') << "FOR " << fn->var << "\n";
        printAST(fn->start, indent + 2);
        std::cout << std::string(indent + 2, ' ') << "TO\n";
        printAST(fn->end, indent + 4);
        std::cout << std::string(indent + 2, ' ') << "STEP\n";
        printAST(fn->step, indent + 4);
        std::cout << std::string(indent + 2, ' ') << "BODY\n";
        printAST(fn->body, indent + 4);
        break;
    }
    case ASTType::IfStmt: {
        IfNode* i = static_cast<IfNode*>(node);
        std::cout << pad << "IF\n";
        printAST(i->lhs, indent + 2);
        std::cout << pad << "  Op: " << i->op << "\n";
        printAST(i->rhs, indent + 2);
        std::cout << pad << "THEN\n";
        printAST(i->thenStmt, indent + 2);
        break;
    }
    case ASTType::StringExpr:
        std::cout << pad << "String \"" << static_cast<StringNode*>(node)->value << "\"\n";
        break;
    case ASTType::GotoStmt:
        std::cout << pad << "GOTO " << static_cast<GotoNode*>(node)->line << "\n";
        break;

    case ASTType::InputStmt:
        std::cout << pad << "INPUT " << static_cast<InputNode*>(node)->name << "\n";
        break;

    case ASTType::IfElseStmt: {
        auto* n = static_cast<IfElseNode*>(node);
        std::cout << pad << "IF\n";
        printAST(n->left, indent + 2);
        std::cout << pad << "  Op: " << n->op << "\n";
        printAST(n->right, indent + 2);
        std::cout << pad << "THEN\n";
        printAST(n->thenStmt, indent + 2);
        if (n->elseStmt) {
            std::cout << pad << "ELSE\n";
            printAST(n->elseStmt, indent + 2);
        }
        break;
    }
    case ASTType::PrintStmt:
        std::cout << pad << "PRINT\n";
        printAST(static_cast<PrintNode*>(node)->expr, indent + 2);
        break;

    case ASTType::LetStmt: {
        LetNode* l = static_cast<LetNode*>(node);
        std::cout << pad << "LET " << l->name << "\n";
        printAST(l->expr, indent + 2);
        break;
    }

    case ASTType::BinOpExpr: {
        BinOpNode* b = static_cast<BinOpNode*>(node);
        std::cout << pad << "BinOp (" << b->op << ")\n";
        printAST(b->left, indent + 2);
        printAST(b->right, indent + 2);
        break;
    }

    case ASTType::NumberExpr:
        std::cout << pad << "Number " << static_cast<NumberNode*>(node)->value << "\n";
        break;

    case ASTType::IdentExpr:
        std::cout << pad << "Ident " << static_cast<IdentNode*>(node)->name << "\n";
        break;
    }

}

int main() {
    Lexer lexer;
    Parser parser;
    //std::string l = "PRINT \"HELLO\" ";
    std::vector<std::string> tests = {
        //l,
        "PRINT \"HELLO\" "
        "LET X = 5",
        "IF X > 3 THEN PRINT X",
        "LET Y = (1 + 2) * 3 - 4",
        "FOR I = 1 TO 5 STEP 2 : PRINT I",
        "FOR X = 0 TO 2 : LET Y = X",
        "100 IF A = 5 THEN",
        "110 GOTO 130",
        "120 ELSE",
        "125 PRINT \"A is not 5\"",
        "130 END IF"
        "140 PRINT \"Done!\""

    };

    for (const std::string& line : tests) {
        std::cout << "\n-- Input: " << line << "\n";
        std::vector<Token> tokens = lexer.tokenize(line);
        ASTNode* ast = nullptr;
        try {
            ast = parser.parse(tokens);
            printAST(ast);
        }
        catch (const std::exception& e) {
            std::cerr << "Parse error: " << e.what() << "\n";
        }
        delete ast;
    }

    return 0;
}
