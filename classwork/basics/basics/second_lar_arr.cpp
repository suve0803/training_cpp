#include <iostream>
using namespace std;

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int largest = arr[0], second = 1;

    for (int i = 1; i < 6; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    cout<<second << endl;
    return 0;
}
