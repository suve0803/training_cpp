/* Write a Program to Count the Sum of Numbers in a String */

#include<iostream>
using namespace std;
int main() {
	int sum = 0;
	char s[100];
	cin.getline(s, 100);
	for (int i = 0;i < strlen(s);i++) {
		if (s[i] >= 48 && s[i] <= 59) {
			sum += s[i]-48;
		}
	}
	cout << sum;
}