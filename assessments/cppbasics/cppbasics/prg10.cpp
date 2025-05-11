/*	Write a Program to Remove the Vowels from a String */

#include<iostream>
using namespace std;
int main() {
	char str[100];
	char result[100];
	int j = 0;
	cout << "Enter a string: " << endl;
	cin.getline(str, 100);

	for (int i = 0;str[i] != '\0';i++) {
		char ch = str[i];
		if (!(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			result[j] = ch;
			j++;
		}

	}
	result[j] = '\0';
	cout << result;
	return 0;
}