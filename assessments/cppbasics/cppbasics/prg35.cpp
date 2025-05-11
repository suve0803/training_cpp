/* Write a Program to Print the Given String in Reverse Order */

#include<iostream>
using namespace std;
int main() {
	char str[50] = { 0 };
	cout << "Enter the String:";
	cin.getline(str, 50);
	int len = 0;
	while (str[len] != '\0') {
		len++;

	}for (int i = 0;i < len / 2;i++) {
		char t = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = t;
	}cout << str;
	return 0;
}