#include<iostream>
using namespace std;
int pow(int a, int b) {
	if (b == 0)
		return 1;
	return a * pow(a, b - 1);
}

int main() {
	int base, expo;
	cout << "Enter base and exponent: ";
	cin >> base >> expo;
	int res = pow(base, expo);
	cout << base << "^" << expo << "=" << res << endl;
	return 0;

}