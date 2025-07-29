////#include "Lexer.h"
//#include "parser.h"
//#include <iostream>
//#include <vector>
//
//void printAST(ASTNode* node, int indent = 0) {
//    if (node == nullptr) {
//        return;
//    }
//    std::string pad(indent, ' ');
//    switch (node->type()) {
//    case ASTType::Program: {
//        std::cout << pad << "Program\n";
//        for (ASTNode* s : static_cast<ProgramNode*>(node)->stmts) {
//            printAST(s, indent + 2);
//        }
//        break;
//    }
//    case ASTType::PrintStmt: {
//        std::cout << pad << "PRINT\n";
//        printAST(static_cast<PrintNode*>(node)->expr, indent + 2);
//        break;
//    }
//    case ASTType::LetStmt: {
//        LetNode* ln = static_cast<LetNode*>(node);
//        std::cout << pad << "LET " << ln->name << "\n";
//        printAST(ln->expr, indent + 2);
//        break;
//    }
//    case ASTType::IfElseStmt: {
//        IfElseNode* fn = static_cast<IfElseNode*>(node);
//        std::cout << pad << "IF\n";
//        printAST(fn->left, indent + 2);
//        std::cout << pad << "  Op: " << fn->op << "\n";
//        printAST(fn->right, indent + 2);
//        std::cout << pad << "THEN\n";
//        printAST(fn->thenStmt, indent + 2);
//        if (fn->elseStmt) {
//            std::cout << pad << "ELSE\n";
//            printAST(fn->elseStmt, indent + 2);
//        }
//        break;
//    }
//    case ASTType::ForStmt: {
//        ForNode* fn = static_cast<ForNode*>(node);
//        std::cout << pad << "FOR " << fn->var << "\n";
//        printAST(fn->start, indent + 2);
//        std::cout << pad << "  TO\n";
//        printAST(fn->end, indent + 4);
//        std::cout << pad << "  STEP\n";
//        printAST(fn->step, indent + 4);
//        std::cout << pad << "  BODY\n";
//        printAST(fn->body, indent + 4);
//        break;
//    }
//    case ASTType::NextStmt: {
//        NextNode* n = static_cast<NextNode*>(node);
//        std::cout << pad << "NEXT " << n->var << "\n";
//        break;
//    }
//
//    case ASTType::GotoStmt: {
//        std::cout << pad << "GOTO " << static_cast<GotoNode*>(node)->line << "\n";
//        break;
//    }
//    case ASTType::DataStmt: {
//        auto* dn = static_cast<DataNode*>(node);
//        std::cout << pad << "DATA ";
//        for (auto& v : dn->values) std::cout << v << ",";
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::ReadStmt:
//        std::cout << pad << "READ " << static_cast<ReadNode*>(node)->var << "\n"; break;
//        /*std::cout << pad << "READ\n";
//        printAST(static_cast<ReadNode*>(node)->var, indent + 2);
//        break;
//
//        ReadNode* ln = static_cast<ReadNode*>(node);
//        std::cout << pad << "READ " << ln->var << "\n";
//        printAST(ln->var, indent + 2);
//        break;*/
//    case ASTType::GosubStmt:
//        std::cout << pad << "GOSUB " << static_cast<GosubNode*>(node)->line << "\n"; break;
//    case ASTType::ReturnStmt:
//        std::cout << pad << "RETURN\n"; break;
//    case ASTType::StopStmt:
//        std::cout << pad << "STOP\n"; break;
//    case ASTType::RemStmt:
//        std::cout << pad << "REM " << static_cast<RemNode*>(node)->comment << "\n"; break;
//
//    case ASTType::OnErrorStmt: {
//        auto* n = static_cast<OnErrorNode*>(node);
//        std::cout << pad << "ON ERROR GOTO " << n->line << "\n";
//        break;
//    }
//    case ASTType::FieldStmt: {
//        auto* f = static_cast<FieldNode*>(node);
//        std::cout << pad << "FIELD " << f->fileNum;
//        for (auto& p : f->fields) {
//            std::cout << ", " << p.first << " AS " << p.second;
//        }
//        std::cout << "\n";
//        break;
//    }
//
//
//    case ASTType::InputStmt: {
//        std::cout << pad << "INPUT " << static_cast<InputNode*>(node)->name << "\n";
//        break;
//    }
//    case ASTType::BinOpExpr: {
//        BinOpNode* bn = static_cast<BinOpNode*>(node);
//        std::cout << pad << "BinOp (" << bn->op << ")\n";
//        printAST(bn->left, indent + 2);
//        printAST(bn->right, indent + 2);
//        break;
//    }
//    case ASTType::NumberExpr:
//        std::cout << pad << "Number " << static_cast<NumberNode*>(node)->value << "\n";
//        break;
//    case ASTType::IdentExpr:
//        std::cout << pad << "Ident " << static_cast<IdentNode*>(node)->name << "\n";
//        break;
//    case ASTType::StringExpr:
//        std::cout << pad << "String \"" << static_cast<StringNode*>(node)->value << "\"\n";
//        break;
//    default:
//        //std::cout << pad << "?? Unknown AST\n";
//        break;
//    }
//}
//
//int main() {
//    Lexer lexer;
//    Parser parser;
//
//    std::vector<std::string> tests = {
//        "DATA 1,2,3,4",
//       "READ A",
//       "PRINT A",
//       "GOSUB 200",
//       "FIELD 1,20 AS N$,10 AS ID$,40 AS ADD$",
//       "RETURN",
//       "STOP",
//       "REM This is comment",
//       "PRINT \"Hi\": REM This part is comment",
//       "ON ERROR GOTO 100",
//
//
//
//        "PRINT \"HELLO\"",
//        "LET X = 5",
//        "IF X > 3 THEN PRINT X",
//        "IF X = 3 THEN PRINT \"Yes\" ELSE PRINT \"No\"",
//        "LET Y = (1 + 2) * 3 - 4",
//        "PRINT 2+3",
//        "FOR I = 1 TO 5 STEP 2 : PRINT I",
//        "FOR B=2 TO 40 STEP 2",
//        "PRINT B",
//        "NEXT B",
//        "100 IF A = 5 THEN PRINT \"Ok\"",
//        "110 GOTO 130",
//        //"120 ELSE PRINT \"A is not 5\"",
//        //"120 IF A=5 THEN PRINT \"Ok\": ELSE PRINT \"A is not 5\"",
//        "FOR I = 1 TO 5 STEP 2 : PRINT I : NEXT I",
//        "125 PRINT \"A is not 5\"",
//        /*"ON ERROR GOTO 200",
//        "FIELD 1, 20 AS N$, 10 AS ID$, 40 AS ADD$",*/
//        "130 END",
//        "135 STOP",
//        "200 PRINT \"Done!\""
//    };
//
//    for (const std::string& line : tests) {
//        std::cout << "\n-- Input: " << line << "\n";
//        std::vector<Token> tokens = lexer.tokenize(line);
//        ASTNode* ast = nullptr;
//        try {
//            ast = parser.parse(tokens);
//            printAST(ast);
//        }
//        catch (const std::exception& ex) {
//            std::cerr << "Parse error: " << ex.what() << "\n";
//        }
//        delete ast;
//    }
//
//    return 0;
//}

//#include "Lexer.h"
//#include "Parser.h"
//#include "ASTNode.h"
//#include <iostream>
//#include <vector>
//#include <string>
//
//// Forward declaration
//void printAST(ASTNode* node, int indent = 0);
//
//int main() {
//    Lexer lexer;
//    Parser parser;
//
//    std::vector<std::string> tests = {
//    "LET X = 5",
//    "WHILE X < 3 : PRINT X : WEND",
//    "DO : PRINT X : LOOP WHILE X < 10",
//    "RUN",
//    "SAVE \"MYPROG\"",
//    "DEFINT A-C",
//    "PRINT SIN(3.14)",
//    "PRINT X + COS(Y)",
//    "ON ERROR GOTO 100",
//    "FIELD 1,20 AS N$,10 AS ID$",
//    "DATA 1,2,3,4",
//    "READ A",
//    "GOSUB 200",
//    "RETURN",
//    "STOP",
//    "RUN",
//    "EDIT file.txt",
//    "PRINT \"HELLO\"",
//    "IF X = 3 THEN PRINT \"Yes\" ELSE PRINT \"No\"",
//    "FOR I = 1 TO 5 STEP 2 : PRINT I : NEXT I",
//    "FOR I=1 TO 5 STEP 2 ",
//    "PRINT I",
//    "NEXT I",
//    "10 WHILE A < 5",
//"20   PRINT A;",
//"30   A = A + 1",
//"40 WEND",
//
//
// /*   "10 INPUT \"Enter a number: \", N",
//"20 IF N > 0 THEN",
//"30     PRINT \"Positive number\"",
//"40 ELSE",
//"50     PRINT \"Zero or Negative number\"",
//"60 END IF",
//"70 END",*/
//    "WRITE \"Hello\",X",
//    //"END IF"
//    };
//
//    for (auto& line : tests) {
//        std::cout << "\n-- Input: " << line << "\n";
//        auto tokens = lexer.tokenize(line);
//        ASTNode* ast = nullptr;
//        try {
//            ast = parser.parse(tokens);
//            printAST(ast);
//        }
//        catch (const std::exception& ex) {
//            std::cerr << "Parse error: " << ex.what() << "\n";
//        }
//        delete ast;
//    }
//    return 0;
//}
//
//void printAST(ASTNode* node, int indent) {
//    if (!node) return;
//    std::string pad(indent, ' ');
//    switch (node->type()) {
//    case ASTType::Program: {
//        std::cout << pad << "Program\n";
//        for (auto s : static_cast<ProgramNode*>(node)->stmts) {
//            printAST(s, indent + 2);
//        }
//        break;
//    }
//    case ASTType::LetStmt: {
//        auto* n = static_cast<LetNode*>(node);
//        std::cout << pad << "LET " << n->name << "\n";
//        printAST(n->expr, indent + 2);
//        break;
//    }
//    case ASTType::PrintStmt: {
//        std::cout << pad << "PRINT\n";
//        printAST(static_cast<PrintNode*>(node)->expr, indent + 2);
//        break;
//    }
//    case ASTType::WhileStmt: {
//        auto* wn = static_cast<WhileNode*>(node);
//        std::cout << pad << "WHILE\n";
//        printAST(wn->cond, indent + 2);
//        if (wn->body) {
//            std::cout << pad << "  BODY\n";
//            printAST(wn->body, indent + 2);
//        }
//        break;
//    }
//    case ASTType::DoLoopStmt: {
//        auto* dn = static_cast<DoLoopNode*>(node);
//        std::cout << pad << "DO\n";
//        std::cout << pad << "  BODY\n";
//        printAST(dn->body, indent + 2);
//        if (dn->cond) {
//            std::cout << pad << "  COND (" << (dn->untilStyle ? "UNTIL" : "WHILE") << ")\n";
//            printAST(dn->cond, indent + 2);
//        }
//        break;
//    }
//    case ASTType::OnErrorStmt: {
//        auto* ne = static_cast<OnErrorNode*>(node);
//        std::cout << pad << "ON ERROR GOTO " << ne->line << "\n";
//        break;
//    }
//    case ASTType::FieldStmt: {
//        auto* fn = static_cast<FieldNode*>(node);
//        std::cout << pad << "FIELD file#=" << fn->fileNum;
//        for (auto& f : fn->fields) {
//            std::cout << ", width=" << f.first << " AS " << f.second;
//        }
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::DataStmt: {
//        auto* dn = static_cast<DataNode*>(node);
//        std::cout << pad << "DATA";
//        for (auto& v : dn->values) {
//            std::cout << " " << v;
//        }
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::ReadStmt: {
//        auto* rn = static_cast<ReadNode*>(node);
//        std::cout << pad << "READ " << rn->var << "\n";
//        break;
//    }
//    case ASTType::GosubStmt: {
//        auto* gs = static_cast<GosubNode*>(node);
//        std::cout << pad << "GOSUB " << gs->line << "\n";
//        break;
//    }
//    case ASTType::ReturnStmt:
//        std::cout << pad << "RETURN\n"; break;
//    case ASTType::StopStmt:
//        std::cout << pad << "STOP\n"; break;
//    case ASTType::CommandStmt: {
//        auto* cn = static_cast<CommandNode*>(node);
//        std::cout << pad << "CMD " << cn->cmd;
//        for (auto& a : cn->args) std::cout << " " << a;
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::IfElseStmt: {
//        auto* in = static_cast<IfElseNode*>(node);
//        std::cout << pad << "IF\n";
//        printAST(in->left, indent + 2);
//        std::cout << pad << "  OP " << in->op << "\n";
//        printAST(in->right, indent + 2);
//        std::cout << pad << "THEN\n";
//        printAST(in->thenStmt, indent + 2);
//        if (in->elseStmt) {
//            std::cout << pad << "ELSE\n";
//            printAST(in->elseStmt, indent + 2);
//        }
//        break;
//    }
//    case ASTType::ForStmt: {
//        auto* fn = static_cast<ForNode*>(node);
//        std::cout << pad << "FOR " << fn->var << "\n";
//        printAST(fn->start, indent + 2);
//        std::cout << pad << "  TO\n";
//        printAST(fn->end, indent + 2);
//        std::cout << pad << "  STEP\n";
//        printAST(fn->step, indent + 2);
//        std::cout << pad << "  BODY\n";
//        printAST(fn->body, indent + 2);
//        break;
//    }
//    case ASTType::NextStmt: {
//        auto* nn = static_cast<NextNode*>(node);
//        std::cout << pad << "NEXT " << nn->var << "\n";
//        break;
//    }
//
//    case ASTType::BinOpExpr: {
//        auto* bn = static_cast<BinOpNode*>(node);
//        std::cout << pad << "BinOp (" << bn->op << ")\n";
//        printAST(bn->left, indent + 2);
//        printAST(bn->right, indent + 2);
//        break;
//    }
//    case ASTType::NumberExpr:
//        std::cout << pad << "Number " << static_cast<NumberNode*>(node)->value << "\n"; break;
//    case ASTType::IdentExpr:
//        std::cout << pad << "Ident " << static_cast<IdentNode*>(node)->name << "\n"; break;
//    case ASTType::StringExpr:
//        std::cout << pad << "String \"" << static_cast<StringNode*>(node)->value << "\"\n"; break;
//
//
//    default:
//        std::cout << pad << "UNKNOWN NODE\n"; break;
//    }
//}

//#include "Lexer.h"
//#include "Parser.h"
//#include "ASTNode.h"
//#include <iostream>
//#include <vector>
//#include <string>
//
//// Helper: convert TokenType enum to readable string
//std::string tokenTypeToString(TokenType t) {
//    switch (t) {
//    case TokenType::Keyword: return "Keyword";
//    case TokenType::Number: return "Number";
//    case TokenType::String: return "String";
//    case TokenType::Identifier: return "Identifier";
//    case TokenType::Separator: return "Separator";
//    case TokenType::Operator: return "Operator";
//    case TokenType::END_OF_LINE: return "EndOfLine";
//    default: return "Unknown";
//    }
//}
//
//// Print tokens per line for debugging lexer output
//void printTokens(const std::vector<Token>& tokens) {
//    std::cout << "  Tokens: ";
//    for (const auto& t : tokens) {
//        std::cout << "(" << tokenTypeToString(t.type) << ", \"" << t.value << "\") ";
//    }
//    std::cout << std::endl;
//}
//
//// Recursively pretty-print any AST node tree
//void printAST(ASTNode* node, int indent = 0) {
//    if (!node) return;
//
//    std::string pad(indent, ' ');
//
//    switch (node->type()) {
//    case ASTType::Program: {
//        std::cout << pad << "Program\n";
//        for (ASTNode* stmt : static_cast<ProgramNode*>(node)->stmts) {
//            printAST(stmt, indent + 2);
//        }
//        break;
//    }
//    case ASTType::LetStmt: {
//        auto* letNode = static_cast<LetNode*>(node);
//        std::cout << pad << "LET " << letNode->name << "\n";
//        printAST(letNode->expr, indent + 2);
//        break;
//    }
//    case ASTType::PrintStmt: {
//        auto* printNode = static_cast<PrintNode*>(node);
//        std::cout << pad << "PRINT\n";
//        printAST(printNode->expr, indent + 2);
//        break;
//    }
//    case ASTType::PrintList: {
//        auto* printListNode = static_cast<PrintListNode*>(node);
//        std::cout << pad << "PRINT (list)\n";
//        for (ASTNode* expr : printListNode->exprs) {
//            printAST(expr, indent + 2);
//        }
//        break;
//    }
//    case ASTType::IfElseStmt: {
//        auto* ifNode = static_cast<IfElseNode*>(node);
//        std::cout << pad << "IF\n";
//        printAST(ifNode->left, indent + 2);
//        std::cout << pad << "  OP '" << ifNode->op << "'\n";
//        printAST(ifNode->right, indent + 2);
//        std::cout << pad << "THEN\n";
//        printAST(ifNode->thenStmt, indent + 2);
//        if (ifNode->elseStmt) {
//            std::cout << pad << "ELSE\n";
//            printAST(ifNode->elseStmt, indent + 2);
//        }
//        break;
//    }
//    case ASTType::ForStmt: {
//        auto* forNode = static_cast<ForNode*>(node);
//        std::cout << pad << "FOR " << forNode->var << "\n";
//        printAST(forNode->start, indent + 2);
//        std::cout << pad << "  TO\n";
//        printAST(forNode->end, indent + 2);
//        std::cout << pad << "  STEP\n";
//        printAST(forNode->step, indent + 2);
//        std::cout << pad << "  BODY\n";
//        printAST(forNode->body, indent + 2);
//        break;
//    }
//    case ASTType::NextStmt: {
//        auto* nextNode = static_cast<NextNode*>(node);
//        std::cout << pad << "NEXT " << nextNode->var << "\n";
//        break;
//    }
//    case ASTType::WhileStmt: {
//        auto* whileNode = static_cast<WhileNode*>(node);
//        std::cout << pad << "WHILE\n";
//        printAST(whileNode->cond, indent + 2);
//        if (whileNode->body) {
//            std::cout << pad << "  BODY\n";
//            printAST(whileNode->body, indent + 2);
//        }
//        break;
//    }
//    case ASTType::DoLoopStmt: {
//        auto* doLoopNode = static_cast<DoLoopNode*>(node);
//        std::cout << pad << "DO\n";
//        std::cout << pad << "  BODY\n";
//        printAST(doLoopNode->body, indent + 2);
//        if (doLoopNode->cond) {
//            std::cout << pad << "  COND (" << (doLoopNode->untilStyle ? "UNTIL" : "WHILE") << ")\n";
//            printAST(doLoopNode->cond, indent + 2);
//        }
//        break;
//    }
//    case ASTType::GotoStmt: {
//        auto* gotoNode = static_cast<GotoNode*>(node);
//        std::cout << pad << "GOTO " << gotoNode->line << "\n";
//        break;
//    }
//    case ASTType::InputStmt: {
//        auto* inputNode = static_cast<InputNode*>(node);
//        std::cout << pad << "INPUT " << inputNode->name << "\n";
//        break;
//    }
//    case ASTType::DataStmt: {
//        auto* dataNode = static_cast<DataNode*>(node);
//        std::cout << pad << "DATA";
//        for (const std::string& val : dataNode->values) {
//            std::cout << " " << val;
//        }
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::ReadStmt: {
//        auto* readNode = static_cast<ReadNode*>(node);
//        std::cout << pad << "READ " << readNode->var << "\n";
//        break;
//    }
//    case ASTType::GosubStmt: {
//        auto* gosubNode = static_cast<GosubNode*>(node);
//        std::cout << pad << "GOSUB " << gosubNode->line << "\n";
//        break;
//    }
//    case ASTType::ReturnStmt:
//        std::cout << pad << "RETURN\n";
//        break;
//    case ASTType::StopStmt:
//        std::cout << pad << "STOP\n";
//        break;
//    case ASTType::CommandStmt: {
//        auto* cmdNode = static_cast<CommandNode*>(node);
//        std::cout << pad << "CMD " << cmdNode->cmd;
//        for (const auto& arg : cmdNode->args) std::cout << " " << arg;
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::OnErrorStmt: {
//        auto* onErrorNode = static_cast<OnErrorNode*>(node);
//        std::cout << pad << "ON ERROR GOTO " << onErrorNode->line << "\n";
//        break;
//    }
//    case ASTType::FieldStmt: {
//        auto* fieldNode = static_cast<FieldNode*>(node);
//        std::cout << pad << "FIELD file#=" << fieldNode->fileNum;
//        for (const auto& field : fieldNode->fields) {
//            std::cout << ", width=" << field.first << " AS " << field.second;
//        }
//        std::cout << "\n";
//        break;
//    }
//    case ASTType::DefTypeStmt: {
//        auto* defTypeNode = static_cast<DefTypeNode*>(node);
//        std::cout << pad << defTypeNode->typ << " " << defTypeNode->range << "\n";
//        break;
//    }
//    case ASTType::MathFuncExpr: {
//        auto* mathFuncNode = static_cast<MathFuncNode*>(node);
//        std::cout << pad << mathFuncNode->func << "(\n";
//        printAST(mathFuncNode->argument, indent + 2);
//        std::cout << pad << ")\n";
//        break;
//    }
//    case ASTType::RndFuncExpr: {
//        auto* rndNode = static_cast<RndFuncNode*>(node);
//        std::cout << pad << "RND(\n";
//        printAST(rndNode->argument, indent + 2);
//        std::cout << pad << ")\n";
//        break;
//    }
//    case ASTType::AbsFuncExpr: {
//        auto* absNode = static_cast<AbsFuncNode*>(node);
//        std::cout << pad << "ABS(\n";
//        printAST(absNode->argument, indent + 2);
//        std::cout << pad << ")\n";
//        break;
//    }
//    case ASTType::TimeExpr:
//        std::cout << pad << "TIME$\n";
//        break;
//    case ASTType::DateExpr:
//        std::cout << pad << "DATE$\n";
//        break;
//    case ASTType::LeftFuncExpr: {
//        auto* leftNode = static_cast<LeftFuncNode*>(node);
//        std::cout << pad << "LEFT$\n";
//        printAST(leftNode->strExpr, indent + 2);
//        printAST(leftNode->lengthExpr, indent + 2);
//        break;
//    }
//    case ASTType::MidFuncExpr: {
//        auto* midNode = static_cast<MidFuncNode*>(node);
//        std::cout << pad << "MID$\n";
//        printAST(midNode->strExpr, indent + 2);
//        printAST(midNode->startExpr, indent + 2);
//        if (midNode->lengthExpr)
//            printAST(midNode->lengthExpr, indent + 2);
//        break;
//    }
//    case ASTType::RestoreStmt:
//        std::cout << pad << "RESTORE\n";
//        break;
//    case ASTType::WriteStmt: {
//        auto* writeNode = static_cast<WriteNode*>(node);
//        std::cout << pad << "WRITE\n";
//        printAST(writeNode->expr, indent + 2);
//        break;
//    }
//    case ASTType::GetStmt: {
//        auto* getNode = static_cast<GetNode*>(node);
//        std::cout << pad << "GET\n";
//        printAST(getNode->expr, indent + 2);
//        break;
//    }
//    case ASTType::PutStmt: {
//        auto* putNode = static_cast<PutNode*>(node);
//        std::cout << pad << "PUT\n";
//        printAST(putNode->expr, indent + 2);
//        break;
//    }
//    case ASTType::LoadStmt: {
//        auto* loadNode = static_cast<LoadNode*>(node);
//        std::cout << pad << "LOAD \"" << loadNode->filename << "\"\n";
//        break;
//    }
//    case ASTType::SaveStmt: {
//        auto* saveNode = static_cast<SaveNode*>(node);
//        std::cout << pad << "SAVE \"" << saveNode->filename << "\"\n";
//        break;
//    }
//    case ASTType::DirStmt:
//        std::cout << pad << "DIR\n";
//        break;
//    case ASTType::BinOpExpr: {
//        auto* bn = static_cast<BinOpNode*>(node);
//        std::cout << pad << "BinOp (" << bn->op << ")\n";
//        printAST(bn->left, indent + 2);
//        printAST(bn->right, indent + 2);
//        break;
//    }
//    case ASTType::NumberExpr:
//        std::cout << pad << "Number " << static_cast<NumberNode*>(node)->value << "\n";
//        break;
//    case ASTType::IdentExpr:
//        std::cout << pad << "Ident " << static_cast<IdentNode*>(node)->name << "\n";
//        break;
//    case ASTType::StringExpr:
//        std::cout << pad << "String \"" << static_cast<StringNode*>(node)->value << "\"\n";
//        break;
//    default:
//        std::cout << pad << "UNKNOWN NODE TYPE\n";
//        break;
//    }
//}
//
//int main() {
//    Lexer lexer;
//    Parser parser;
//
//    std::vector<std::string> tests = {
//    "10 DEFINT A-Z",
//    "20 LET A = 5",
//    "25 LET B = 2",
//    "30 FOR I = 1 TO 3 STEP 1",
//    "35 PRINT \"FOR loop i = \"; I",
//    "40 NEXT I",
//    "50 WHILE A > 0",
//    "55 PRINT A, TIME$",
//    "60 LET A = A - 1",
//    "65 WEND",
//    "70 DO",
//    "75 PRINT DATE$; MID$(\"HelloWorld\", 2, 3)",
//    "80 LOOP UNTIL A = 0",
//    "90 IF B > 0 THEN PRINT \"B is positive\" ELSE PRINT \"B is zero or negative\"",
//    "100 PRINT RND(0.5), ABS(-42), SIN(3.1415), COS(0), LOG(10), SQR(16)",
//    "110 PRINT LEFT$(\"Example\", 4)",
//    "120 RESTORE",
//    "130 WRITE B",
//    "140 GET A",
//    "150 PUT B",
//    "160 LOAD \"file.bas\"",
//    "170 SAVE \"file.bas\"",
//    "180 DIR",
//    "190 ON ERROR GOTO 300",
//    "200 DATA 10,20,30",
//    "210 READ C",
//    "220 GOSUB 500",
//    "230 RETURN",
//    "240 STOP"
//    };
//
//    for (auto& line : tests) {
//        std::cout << "\n-- Input: " << line << "\n";
//        auto tokens = lexer.tokenize(line);
//        ASTNode* ast = nullptr;
//        try {
//            ast = parser.parse(tokens);
//            printAST(ast);
//        }
//        catch (const std::exception& ex) {
//            std::cerr << "Parse error: " << ex.what() << "\n";
//        }
//        delete ast;
//    }
//    return 0;
//}

#include "Lexer.h"
#include "Parser.h"
#include "ASTNode.h"
#include <iostream>
#include <vector>
#include <string>

// Forward declaration
void printAST(ASTNode* node, int indent = 0);

int main() {
    Lexer lexer;
    Parser parser;

    std::vector<std::string> tests = {
    "LET X = 5",
    "WHILE X < 3 ",
    "PRINT X",
    "WEND",
    "DO : PRINT X : LOOP WHILE X < 10",
    "RUN",
    "SAVE \"MYPROG\"",
    "DEFINT A-C",
    "PRINT SIN(3.14)",
    "PRINT X + COS(Y)",
    "ON ERROR GOTO 100",
    "FIELD 1,20 AS N$,10 AS ID$",
    "DATA 1,2,3,4",
    "READ A",
    "GOSUB 200",
    "RETURN",
    "STOP",
    "RUN",
    "EDIT file.txt",
    "PRINT \"HELLO\"",
    "IF X = 3 THEN PRINT \"Yes\" ELSE PRINT \"No\"",
    "FOR I = 1 TO 5 STEP 2 : PRINT I : NEXT I",
    "FOR I=1 TO 5 STEP 2 ",
    "PRINT I",
    "NEXT I",
    "WHILE X < 3 : PRINT X : WEND",
    "PRINT X",


    /* "10 INPUT \"Enter a number: \", N",
 "20 IF N > 0 THEN",
 "30     PRINT \"Positive number\"",
 "40 ELSE",
 "50     PRINT \"Zero or Negative number\"",
 "60 END IF",
 "70 END",*/
     "WRITE \"Hello\",X",
     "END "
    };

    for (auto& line : tests) {
        std::cout << "\n-- Input: " << line << "\n";
        auto tokens = lexer.tokenize(line);
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

void printAST(ASTNode* node, int indent) {
    if (!node) return;
    std::string pad(indent, ' ');
    switch (node->type()) {
    case ASTType::Program: {
        std::cout << pad << "Program\n";
        for (auto s : static_cast<ProgramNode*>(node)->stmts) {
            printAST(s, indent + 2);
        }
        break;
    }
    case ASTType::LetStmt: {
        auto* n = static_cast<LetNode*>(node);
        std::cout << pad << "LET " << n->name << "\n";
        printAST(n->expr, indent + 2);
        break;
    }
    case ASTType::PrintStmt: {
        std::cout << pad << "PRINT\n";
        printAST(static_cast<PrintNode*>(node)->expr, indent + 2);
        break;
    }
    case ASTType::WhileStmt: {
        auto* wn = static_cast<WhileNode*>(node);
        std::cout << pad << "WHILE\n";
        printAST(wn->cond, indent + 2);
        if (wn->body) {
            std::cout << pad << "  BODY\n";
            printAST(wn->body, indent + 2);
        }
        break;
    }
    case ASTType::DoLoopStmt: {
        auto* dn = static_cast<DoLoopNode*>(node);
        std::cout << pad << "DO\n";
        std::cout << pad << "  BODY\n";
        printAST(dn->body, indent + 2);
        if (dn->cond) {
            std::cout << pad << "  COND (" << (dn->untilStyle ? "UNTIL" : "WHILE") << ")\n";
            printAST(dn->cond, indent + 2);
        }
        break;
    }
    case ASTType::OnErrorStmt: {
        auto* ne = static_cast<OnErrorNode*>(node);
        std::cout << pad << "ON ERROR GOTO " << ne->line << "\n";
        break;
    }
    case ASTType::FieldStmt: {
        auto* fn = static_cast<FieldNode*>(node);
        std::cout << pad << "FIELD file#=" << fn->fileNum;
        for (auto& f : fn->fields) {
            std::cout << ", width=" << f.first << " AS " << f.second;
        }
        std::cout << "\n";
        break;
    }
    case ASTType::DataStmt: {
        auto* dn = static_cast<DataNode*>(node);
        std::cout << pad << "DATA";
        for (auto& v : dn->values) {
            std::cout << " " << v;
        }
        std::cout << "\n";
        break;
    }
    case ASTType::ReadStmt: {
        auto* rn = static_cast<ReadNode*>(node);
        std::cout << pad << "READ " << rn->var << "\n";
        break;
    }
    case ASTType::GosubStmt: {
        auto* gs = static_cast<GosubNode*>(node);
        std::cout << pad << "GOSUB " << gs->line << "\n";
        break;
    }
    case ASTType::ReturnStmt:
        std::cout << pad << "RETURN\n"; break;
    case ASTType::StopStmt:
        std::cout << pad << "STOP\n"; break;
    case ASTType::CommandStmt: {
        auto* cn = static_cast<CommandNode*>(node);
        std::cout << pad << "CMD " << cn->cmd;
        for (auto& a : cn->args) std::cout << " " << a;
        std::cout << "\n";
        break;
    }
    case ASTType::IfElseStmt: {
        auto* in = static_cast<IfElseNode*>(node);
        std::cout << pad << "IF\n";
        printAST(in->left, indent + 2);
        std::cout << pad << "  OP " << in->op << "\n";
        printAST(in->right, indent + 2);
        std::cout << pad << "THEN\n";
        printAST(in->thenStmt, indent + 2);
        if (in->elseStmt) {
            std::cout << pad << "ELSE\n";
            printAST(in->elseStmt, indent + 2);
        }
        break;
    }
    case ASTType::ForStmt: {
        auto* fn = static_cast<ForNode*>(node);
        std::cout << pad << "FOR " << fn->var << "\n";
        printAST(fn->start, indent + 2);
        std::cout << pad << "  TO\n";
        printAST(fn->end, indent + 2);
        std::cout << pad << "  STEP\n";
        printAST(fn->step, indent + 2);
        std::cout << pad << "  BODY\n";
        printAST(fn->body, indent + 2);
        break;
    }
    case ASTType::NextStmt: {
        auto* nn = static_cast<NextNode*>(node);
        std::cout << pad << "NEXT " << nn->var << "\n";
        break;
    }
    case ASTType::BinOpExpr: {
        auto* bn = static_cast<BinOpNode*>(node);
        std::cout << pad << "BinOp (" << bn->op << ")\n";
        printAST(bn->left, indent + 2);
        printAST(bn->right, indent + 2);
        break;
    }
    case ASTType::NumberExpr:
        std::cout << pad << "Number " << static_cast<NumberNode*>(node)->value << "\n"; break;
    case ASTType::IdentExpr:
        std::cout << pad << "Ident " << static_cast<IdentNode*>(node)->name << "\n"; break;
    case ASTType::StringExpr:
        std::cout << pad << "String \"" << static_cast<StringNode*>(node)->value << "\"\n"; break;
    default:
        std::cout << pad << "UNKNOWN NODE\n"; break;
    }
}