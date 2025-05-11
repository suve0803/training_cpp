/* Write a Program for Decimal to Binary Conversion */
#include<iostream>
using namespace std;
int decimalToBinary(int decimal);
int main() {
	int num;
	cin >> num;
	cout << "Decimal to Binary: " << decimalToBinary(num) << endl;
	return 0;
}
int decimalToBinary(int decimal) {
	int binary = 0, base = 1;

	while (decimal > 0) {
		int remainder = decimal % 2;
		binary += remainder * base;
		base *= 10;
		decimal /= 2;
	}

	return binary;
}