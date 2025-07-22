#include "Parser.h"
#include <iostream>

int main() {
    std::vector<Token> tokens = {
        {TokenType::Keyword, "PRINT"},
        {TokenType::String, "\"HELLO\""},
        {TokenType::EOL, "\n"},
        {TokenType::Keyword, "LET"},
        {TokenType::Identifier, "X"},
        {TokenType::Operator, "="},
        {TokenType::Number, "100"},
        {TokenType::EOL, "\n"},
        {TokenType::EndOfFile, ""}
    };

    Parser parser(tokens);
    auto ast = parser.parse();

    for (const auto& node : ast) {
        std::cout << "Node Type: " << static_cast<int>(node->type)
            << " Value: " << node->value << "\n";
    }

    return 0;
}
