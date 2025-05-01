#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;  

    int smallestDigit = 9;  
    while (num > 0) {
        int digit = num % 10;  
        if (digit < smallestDigit) {
            smallestDigit = digit;  
        }
        num = num / 10;  
    }

    cout << smallestDigit << endl;  

    return 0;
}
