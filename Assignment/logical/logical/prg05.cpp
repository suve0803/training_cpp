#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 2, c = 1;

    int sumOfSquares = a * a + b * b + c * c;

    cout << a << "^2 + " << b << "^2 + " << c << "^2 = "
        << a * a << " + " << b * b << " + " << c * c
        << " = " << sumOfSquares << endl;

    return 0;
}