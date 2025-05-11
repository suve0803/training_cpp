/*Write a Program to Remove Spaces From a String*/
#include<iostream>
using namespace std;
int main() {
	char str[100];
	char result[100];
	int j = 0;
	cin.getline(str, 100);
	for (int i = 0;str[i] != '\0';i++) {
		if (str[i] != ' ') {
			result[j++] = str[i];
		}
	}
	result[j] = '\0';
	cout << result;
	return 0;
}