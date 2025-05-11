/*Write a Program for Decimal Octal Conversion*/
#include <iostream>
using namespace std;

int main() {
    int decimal;
    cin >> decimal;
    int octal[20];
    int i = 0;
    while (decimal > 0)
    {
        octal[i++] = (decimal % 8);
        decimal /= 8;
    }    for (int j = i - 1; j >= 0; j--)
        cout << octal[j];

    return 0;
}