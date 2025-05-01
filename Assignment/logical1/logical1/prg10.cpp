#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    int current = 1;

    for (int i = 1; i <= n; i++) {
        sum += current;
        current *= 2;
    }

    cout << "Sum of all numbers: " << sum << endl;

    return 0;
}
