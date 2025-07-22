// MathApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../MyMathLib/MathFunctions.h"  // Update path if needed

int main() {
    int x = 10, y = 5;

    std::cout << "Add: " << add(x, y) << std::endl;
    std::cout << "Subtract: " << subtract(x, y) << std::endl;

    return 0;
}

