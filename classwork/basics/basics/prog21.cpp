#include<iostream>
using namespace std;
void palindrome(int arr[], int n) {
	int temp = 0;
	for (int i = 0;i <= n / 2 && i != 0;i++) {
		if (arr[i] != arr[n - i - 1]) {
			temp = 1;
			break;
		}
	}if (temp == 0) {
		cout << "not a palindrome";
	}
	else {
		cout << "It is a palindrome";
	}
}
int main() {
	int arr[] = { 1,2,3,4,5 };
	int n= sizeof(arr) /sizeof(arr[0]);
	palindrome(arr, n);
	return 0;

}