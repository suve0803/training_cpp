#include<iostream>
using namespace std;

bool palindrome(int num) {
	int o_num = num;
	int rev = 0;
	while (num > 0) {
		int digit = num % 10;
		rev = rev * 10 + digit;
		num /= 10;
	}return o_num = rev;

}
int main() {
	int num;
	cin >> num;
	if (palindrome(num)) {
		cout << "It is a palindrome" << endl;
	}
	else {
		cout << "It is not a palindrome" << endl;
	}
	return 0;
}