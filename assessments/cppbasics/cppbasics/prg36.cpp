/* Write a C++ Program to Print the Given String in Reverse Order Using Recursion */

#include <iostream>
using namespace std;
void rev(char a[], int i) {
    if (i < 0) return;
    cout << a[i];
    rev(a, i - 1);
}
int main() {
    char s[100];
    cin.getline(s, 100);
    rev(s, strlen(s) - 1);
    cout << endl;
    return 0;
}

