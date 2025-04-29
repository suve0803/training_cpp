#include<iostream>
using namespace std;

int sumofdigits(int n) {
	int sum = 0;
	while (n > 0) {
		sum = sum + (n % 10);
		n = n / 10;
	}
	return sum;
}
int singledigit(int n) {
	while (n >= 10) {
		n = sumofdigits(n);
	}
	return n;
}



int main() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	int res = singledigit(num);
	cout << "The single digit is: " << res << endl;
	return 0;
}