#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    cin >> number;

    int product = 1;
    while (number > 0) {
        int digit = number % 10;
        product *= digit;
        number /= 10;
    }

    if (isPrime(product)) {
        cout << "The box opens!" << endl;
    }
    else {
        cout << "The box does not open." << endl;
    }

    return 0;
}
