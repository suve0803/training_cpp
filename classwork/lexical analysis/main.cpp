#include <iostream>
#include "Lexer.h"

int main() {
    std::string code = "10 PRINT \"HELLO\"";
    Lexer lexer(code);
    auto tokens = lexer.scanTokens();

    for (const Token& token : tokens) {
        std::cout << "Token: " << token.lexeme << std::endl;
    }

    return 0;
}
