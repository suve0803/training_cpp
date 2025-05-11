/* Write a Program to Check Palindrome */
#include<iostream>
using namespace std;

int main() {
	int num , rev=0;
	cin >> num;
	int o_num = num;
	while (num > 0) {
		int dig = num % 10;
		rev = rev * 10 + dig;
		num /= 10;
	}
	if (o_num==rev) {
		cout << "It is a palindrome" << endl;
	}
	else {
		cout << "It is not a palindrome" << endl;
	}
	return 0;
}