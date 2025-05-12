
/* Write a Program to Check if the Given String is Palindrome or not Using Recursion */
#include <iostream>
#include <cstring>

using namespace std;

int pal(char a[], int s, int e) {
    if (s >= e) return 1;
    if (a[s] != a[e]) return 0;
    return pal(a, s + 1, e - 1);
}

int main() {
    char str[100];
    cin.getline(str, 100);

    if (pal(str, 0, strlen(str) - 1))
        cout << "Palindrome" << endl;
    else
        cout << "Not palindrome" << endl;

    return 0;
}