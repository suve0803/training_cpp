#include "Lexer.h"
#include "parser.h"
#include <iostream>
#include <vector>

void printAST(ASTNode* node, int indent = 0) {
    if (node == nullptr) {
        return;  
    }
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
        std::cout << pad << "FOR " << fn->var << "\n";
        printAST(fn->start, indent + 2);
        std::cout << pad << "  TO\n";
        printAST(fn->end, indent + 4);
        std::cout << pad << "  STEP\n";
        printAST(fn->step, indent + 4);
        std::cout << pad << "  BODY\n";
        printAST(fn->body, indent + 4);
        break;
    }
    case ASTType::IfElseStmt: {
        IfElseNode* fe = static_cast<IfElseNode*>(node);
        std::cout << pad << "IF\n";
        printAST(fe->left, indent + 2);
        std::cout << pad << "  Op: " << fe->op << "\n";
        printAST(fe->right, indent + 2);
        std::cout << pad << "THEN\n";
        printAST(fe->thenStmt, indent + 2);
        if (fe->elseStmt) {
            std::cout << pad << "ELSE\n";
            printAST(fe->elseStmt, indent + 2);
        }
        break;
    }
    case ASTType::PrintStmt:
        std::cout << pad << "PRINT\n";
        printAST(static_cast<PrintNode*>(node)->expr, indent + 2);
        break;
    case ASTType::LetStmt: {
        LetNode* ln = static_cast<LetNode*>(node);
        std::cout << pad << "LET " << ln->name << "\n";
        printAST(ln->expr, indent + 2);
        break;
    }
    case ASTType::GotoStmt:
        std::cout << pad << "GOTO " << static_cast<GotoNode*>(node)->line << "\n";
        break;
    case ASTType::InputStmt:
        std::cout << pad << "INPUT " << static_cast<InputNode*>(node)->name << "\n";
        break;
    case ASTType::BinOpExpr: {
        BinOpNode* bn = static_cast<BinOpNode*>(node);
        std::cout << pad << "BinOp (" << bn->op << ")\n";
        printAST(bn->left, indent + 2);
        printAST(bn->right, indent + 2);
        break;
    }
    case ASTType::NumberExpr:
        std::cout << pad << "Number " << static_cast<NumberNode*>(node)->value << "\n";
        break;
    case ASTType::IdentExpr:
        std::cout << pad << "Ident " << static_cast<IdentNode*>(node)->name << "\n";
        break;
    case ASTType::StringExpr:
        std::cout << pad << "String \"" << static_cast<StringNode*>(node)->value << "\"\n";
        break;
    default:
        break;
    }
}

int main() {
    Lexer lexer;
    Parser parser;

    std::vector<std::string> tests = {
        "PRINT \"HELLO\"",
        "LET X = 5",
        "IF X > 3 THEN PRINT X",
        "IF X = 3 THEN PRINT \"Yes\" ELSE PRINT \"No\" ",
        "LET Y = (1 + 2) * 3 - 4",
        "PRINT 2+3",
        "FOR I = 1 TO 5 STEP 2 : PRINT I",
        "FOR X = 0 TO 2 : LET Y = X",
        "LET A=5",
        "100 IF A = 5 THEN",
        "110 GOTO 130",
        "120 ELSE PRINT \"A is not 5\"",
        "125 PRINT \"A is not 5\"",
        "130 END",
        "140 PRINT \"Done!\""
       /* "10 PRINT \"GW - BASIC DEMO PROGRAM\"",
"20 LET A = 5",
"30 LET B = 10",
"40 FOR I = 1 TO 5",
"50   PRINT \"LOOP #\"; I",
"60   IF I = A THEN PRINT \"I equals A!\"",
"70   IF I = 3 THEN GOTO 100",
"80 NEXT I",
"90 GOTO 110",

"100 PRINT \"I was 3, jumped here!\"",
"105 LET B = B + 1",

"110 IF B > 10 THEN",
"120   PRINT \"B is greater than 10\"",
"130 ELSE",
"140   PRINT \"B is 10 or less\"",
"150 END IF",

"160 PRINT \"Program ending.\"",
"170 END"*/
    };

    for (const auto& line : tests) {
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
