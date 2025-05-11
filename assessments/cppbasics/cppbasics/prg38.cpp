/* Write a Program to Calculate the Length of the String Using Recursion */

#include<iostream>
#define MAX 100
using namespace std;

int str_len(char str[], int count) {
	if (str[count] == '\0')
		return count;
	else
		return str_len(str, count + 1);
}


int main() {
	char str[MAX];
	cin.getline(str, MAX-1);
	cout << str_len(str, 0);
	return 0;
}