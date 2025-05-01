#include <iostream>
using namespace std;

void energy(int n) {
    if (n <= 0) {
        return;
    }

    cout << n << " ";

    energy(n / 2);
}

int main() {
    int n;

    cout << "Enter the energy: ";
    cin >> n;

    energy(n);

    return 0;
}