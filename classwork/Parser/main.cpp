// main.cpp
#include "parser.h"
#include <iostream>
#include <sstream>

int main() {
    std::istringstream in("PRINT 42 PRINT 100");
    std::string tok;
    std::vector<std::string> tokens;
    while (in >> tok) tokens.push_back(tok);

    Parser p(tokens);
    auto prog = p.parseProgram();

    for (auto& stmt : prog) stmt->execute();
    return 0;
}
