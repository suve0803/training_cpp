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
    case ASTType::PrintStmt: {
        std::cout << pad << "PRINT\n";
        printAST(static_cast<PrintNode*>(node)->expr, indent + 2);
        break;
    }
    case ASTType::LetStmt: {
        LetNode* ln = static_cast<LetNode*>(node);
        std::cout << pad << "LET " << ln->name << "\n";
        printAST(ln->expr, indent + 2);
        break;
    }
    case ASTType::IfElseStmt: {
        IfElseNode* fn = static_cast<IfElseNode*>(node);
        std::cout << pad << "IF\n";
        printAST(fn->left, indent + 2);
        std::cout << pad << "  Op: " << fn->op << "\n";
        printAST(fn->right, indent + 2);
        std::cout << pad << "THEN\n";
        printAST(fn->thenStmt, indent + 2);
        if (fn->elseStmt) {
            std::cout << pad << "ELSE\n";
            printAST(fn->elseStmt, indent + 2);
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
    case ASTType::GotoStmt: {
        std::cout << pad << "GOTO " << static_cast<GotoNode*>(node)->line << "\n";
        break;
    }
    case ASTType::DataStmt: {
        auto* dn = static_cast<DataNode*>(node);
        std::cout << pad << "DATA ";
        for (auto& v : dn->values) std::cout << v << ",";
        std::cout << "\n";
        break;
    }
    case ASTType::ReadStmt:
        std::cout << pad << "READ " << static_cast<ReadNode*>(node)->var << "\n"; break;
    case ASTType::GosubStmt:
        std::cout << pad << "GOSUB " << static_cast<GosubNode*>(node)->line << "\n"; break;
    case ASTType::ReturnStmt:
        std::cout << pad << "RETURN\n"; break;
    case ASTType::StopStmt:
        std::cout << pad << "STOP\n"; break;
    case ASTType::RemStmt:
        std::cout << pad << "REM " << static_cast<RemNode*>(node)->comment << "\n"; break;

    //case ASTType::OnErrorStmt: {
    //    auto* n = static_cast<OnErrorNode*>(node);
    //    std::cout << pad << "ON ERROR GOTO " << n->line << "\n";
    //    break;
    //}

    //case ASTType::FieldStmt: {
    //    auto* f = static_cast<FieldNode*>(node);
    //    std::cout << pad << "FIELD " << f->fileNum;
    //    for (auto& p : f->fields)
    //        std::cout << " , " << p.first << " AS " << p.second;
    //    std::cout << "\n";
    //    break;
    //}

    case ASTType::InputStmt: {
        std::cout << pad << "INPUT " << static_cast<InputNode*>(node)->name << "\n";
        break;
    }
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
        "DATA 1,2,3,4",
       "READ A",
       "PRINT A",
       "GOSUB 200",
       //"FIELD 1,20 AS N$,10 AS ID$,40 AS ADD$",
       "RETURN",
       "STOP",
       "REM This is comment",
       "PRINT \"Hi\": REM This part is comment",
       //"ON ERROR GOTO 100",


        "PRINT \"HELLO\"",
        "LET X = 5",
        "IF X > 3 THEN PRINT X",
        "IF X = 3 THEN PRINT \"Yes\" ELSE PRINT \"No\"",
        "LET Y = (1 + 2) * 3 - 4",
        "PRINT 2+3",
        "FOR I = 1 TO 5 STEP 2 : PRINT I",
        "FOR B=2 TO 40 STEP 2",
        "PRINT B",
        "NEXT B",
        "100 IF A = 5 THEN PRINT \"Ok\"",
        "110 GOTO 130",
        //"120 ELSE PRINT \"A is not 5\"",
        //"120 IF A=5 THEN PRINT \"Ok\": ELSE PRINT \"A is not 5\"",
        "125 PRINT \"A is not 5\"",
        /*"ON ERROR GOTO 200",
        "FIELD 1, 20 AS N$, 10 AS ID$, 40 AS ADD$",*/
        "130 END",
        "200 PRINT \"Done!\""
    };

    for (const std::string& line : tests) {
        std::cout << "\n-- Input: " << line << "\n";
        std::vector<Token> tokens = lexer.tokenize(line);
        ASTNode* ast = nullptr;
        try {
            ast = parser.parse(tokens);
            printAST(ast);
        }
        catch (const std::exception& ex) {
            std::cerr << "Parse error: " << ex.what() << "\n";
        }
        delete ast;
    }

    return 0;
}
