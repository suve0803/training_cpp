/* Write a Program to Calculate the Greatest Common Divisor of Two Numbers */
#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	while (b != 0) {
		int rem = a % b;
		a = b;
		b = rem;
	}
	cout << a;
	return 0;
}