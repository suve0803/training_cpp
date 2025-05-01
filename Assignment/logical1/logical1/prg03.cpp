#include <iostream>
using namespace std;

int main() {
    int hour;
    cin >> hour;

    cout << "Minutes when the clock will ring: ";

    for (int minute = 1; minute <= 60; minute++) {
        if (hour % minute == 0) {
            cout << minute << " ";
        }
    }
    cout << endl;

    return 0;
}
