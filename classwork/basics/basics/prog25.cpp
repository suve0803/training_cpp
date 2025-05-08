#include <iostream>
using namespace std;

int main() {
    int arr[] = { 5, 2, 9, 3, 2, 6 };
    int smallest = arr[0], second = 1;

    for (int i = 1; i < 6; i++) {
        if (arr[i] < smallest) {
            second = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second && arr[i] != smallest) {
            second = arr[i];
        }
    }

    cout << second << endl;
    return 0;
}
