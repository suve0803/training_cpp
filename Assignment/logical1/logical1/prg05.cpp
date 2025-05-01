#include <iostream>
using namespace std;

int main() {
    int Number;
    cin >> Number;

    int sum = 0;

    for (int i = 1; i <= Number / 2; i++) {
        if (Number % i == 0) {
            sum += i;
        }
    }

    if (sum == Number) {
        cout << "Perfect Army" << endl;
    }
    else {
        cout << "Not a Perfect Army" << endl;
    }

    return 0;
}
