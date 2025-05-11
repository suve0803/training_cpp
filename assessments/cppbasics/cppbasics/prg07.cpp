/*Write a Program to Find the Length of the String Without using strlen() Function*/
#include<iostream>
using namespace std;
int main() {
	char str[100];
	cin.getline(str, 100);
	int length = 0;
	while (str[length] != 0) {
		length++;
	}cout << length;
}