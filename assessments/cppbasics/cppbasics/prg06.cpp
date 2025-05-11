/*Write a Program to Print Check Whether a Character is an Alphabet or Not*/
#include<iostream>
using namespace std;
int main() {
	char ch;
	cin >> ch;
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
		{
			cout << ch << " is a Alphabet";
	}
	else {
		cout << ch << " is not a alphabet";
	}
	return 0;
}