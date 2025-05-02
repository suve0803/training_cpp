/*Problem Statement 1
Write a program that performs the following tasks:

Finds the starting positions (0-based index) of the substrings "are" and "i" in a given input string.
Calculates and prints the sum of these two positions.
If either of the substrings is not found in the input, treat its position as -1.*/


#include<iostream>
#include<string>
using namespace std;

int findstr(const string text,string substring) {
	for (int i = 0;i <= text.length() - substring.length();i++)
	{
		if (text.substr(i, substring.length()) == substring) {
			return i;
		}
	}
	return -1;

}


/*int findchar(string text, char character) {
	for (int i = 0;i < text.length();i++) {
		if (text[i] == character) {
			return i;
		}
	}return -1;
}
*/


int main() {
	string text;
	getline(cin, text);
	int position1 = findstr(text, "are");
	int position2 = findstr(text, "i");
	int sum = position1 + position2;
	cout << "sum = " << sum << endl;
	return 0;
}

/*
output

there are fruits in the basket
sum = 19

The sun is beautiful
sum = 7

We are playing football
sum = 14

he works at tcs
sum = -2
*/