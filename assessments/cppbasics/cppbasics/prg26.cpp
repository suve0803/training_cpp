/*Write a Program to Check if Two Strings are Anagram or Not*/
#include<iostream>
using namespace std;
int main() {
	string str1, str2;
	int count1[26] = { 0 };
	int count2[26] = { 0 };
	cin >> str1;
	cin >> str2;
	if (str1.length() != str2.length()) {
		cout << "The given string is not an anagram" << endl;
		return 0;
	}for (int i = 0;i < str1.length();i++) {
		count1[str1[i] - 'a']++;
		count2[str2[i] - 'a']++;
	}for (int i = 0;i < 26;i++) {
		if (count1[i] != count2[i]) {
			cout << str1 << " " << "and" << " " << str2 << " " << "are not an anagram" << endl;
			return 0;
		}
	}cout << str1 << " " << "and" << " " << str2 << " " << "is an anagram" << endl;
	return 0;

}