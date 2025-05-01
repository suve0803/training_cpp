#include <iostream>
using namespace std;

int main() {
    int code;
    cin >> code;

    while (code > 0) {
        int digit = code % 10;
        if (digit != 0) {
            if (digit % 2 == 0) {
                cout << "First non-zero digit is even: " << digit << endl;
            }
            else {
                cout << "First non-zero digit is odd: " << digit << endl;
            }
            break;
        }
        code /= 10;
    }

    return 0;
}
