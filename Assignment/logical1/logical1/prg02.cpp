#include <iostream>
using namespace std;

int main() {
    int coin;
    cin >> coin;

    int sum = 0;

    while (coin > 0) {
        int digit = coin % 10;
        if (digit % 2 != 0) { // Odd digit
            sum += digit;
        }
        coin /= 10;
    }

    cout << "Sum of odd digits: " << sum << endl;

    return 0;
}
