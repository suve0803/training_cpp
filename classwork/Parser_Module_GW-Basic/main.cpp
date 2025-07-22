#include "parser.h"
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> code = {
        "10 LET A = 5",
        "20 LET B = 3",
        "30 PRINT A + B * 2",
        "40 PRINT (A + B) * 2"
    };

    Parser parser;
    parser.parse(code);
    parser.run();

    return 0;
}
