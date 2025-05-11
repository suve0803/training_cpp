/*	Write a Program to Check the Prime Number */
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "is prime";
	}
	else if (n == 0 || n == 1) {
		cout << "neither prime nor composite";
	}

	for (int i = 2;i*i <= n;i++) {
		if (n % i == 0) {
			cout << "not a prime";
			return 0;
		}
	}cout << "prime";

}