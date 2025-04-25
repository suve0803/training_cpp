#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "Enter the N: " << endl;
	cin >> n;
	if (n >= 2 && n <= 10) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				cout << "*";
			}
			cout << endl;

		}{
		cout << "n is incorrect";
	}
	return 0;
	}
}