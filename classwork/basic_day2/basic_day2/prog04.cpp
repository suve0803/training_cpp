/*Amstrong Number*/
#include<iostream>
using namespace std;
int main() {
	int n1, n2, reminder, result = 0;
	cout << "Enter the number: " << endl;
	cin >> n1;
	n2 = n1;
	int digit = 0;

	int temp = n1;
	while (temp > 0) {
		digit++;
		temp /= 10;
	}
	temp = n1;
	while (temp > 0) {
		reminder = temp % 10;

		int num = 1;
		for (int i = 0;i < digit;i++) {
			num *= reminder;
		}
		result += num;
		temp /= 10;
	}
	if (result == n1) {
		cout << n1 << " is a Armstrong number" << endl;
	}
	else {
		cout << n1 << " is a not Armstrong number" << endl;
	}
	return 0;
}