#include<iostream>
using namespace std;
int main() {
	int num,even=1,odd=1;
	cout << "Enter the num:" << endl;
	cin >> num;
	bool iseven = true;
	while (num > 0) {
		int digit = num % 10;
		if (iseven) {
			even *= digit;
		}
		else {
			odd *= digit;
		}
		num /= 10;
		iseven = !iseven;
	}
	if (odd == even) {
		cout << "yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}