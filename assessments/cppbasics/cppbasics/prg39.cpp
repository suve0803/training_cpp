/* Write a Program to Calculate the Factorial of a Number Using Recursion */
#include <iostream>

using namespace std;

int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << fact(n) << endl;

    return 0;
}