#include<iostream>
using namespace std;
int main() {
	int n, i, j;
	cout << "Enter the input: ";
	cin >> n;
	if (n < 4 || n>10) {
		cout << "invalid input" << endl;
		return 0;
	}
	cout << "*" << endl;
	for (i = 1;i <= n;i++) {
		cout << "*";
		for (j = 1;j <= i;j++) {
			cout << j;
		}

		for (j = i - 1;j >= 1;j--) {
			cout << j;
		}
		cout << "*" << endl;
	}
	for (i = n - 1;i >= 1;i--) {
		cout << "*";

		for (j = 1;j <= i;j++) {
			cout << j;
		}
		for (j = i - 1;j >= 1;j--) {
			cout << j;
		}
		cout << "*" << endl;
	}
	cout << "*" << endl;
	return 0;
} 