/*Write a Program to Check if the Given String is Palindrome or Not*/

#include<iostream>
using namespace std;
int main() {
	char arr[100];
	cin.getline(arr, 100);
	char revarr[100];
	int i, j = 0;
	int n = strlen(arr);
	for (int i = n - 1;arr[i] > 0;i--) {
		revarr[j] = arr[i];
		j++;
	}
	revarr[j] = '\0';
	if (strcmp(arr, revarr) == 0) {
		cout << "It is a palindrome";
	}
	else {
		cout << "It is not a palindrome";
	}
	return 0;
}


