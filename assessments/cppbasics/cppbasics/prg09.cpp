/*Write a Program to Count the Number of Vowels*/
#include<iostream>
using namespace std;
int main() {
	char str[100];
	int count = 0;
	cin.getline(str, 100);
	for (int i = 0;str[i]!='\0';i++) {
		char ch = str[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
			count++;
		}
		
	}cout << count;
}