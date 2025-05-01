#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    int count = 0;
    while (number > 0) {
        if (number % 2 == 1) {
            count++;
        }
        number /= 2;
    }

    cout << "Number of 1s in binary form: " << count << endl;

    return 0;
}
