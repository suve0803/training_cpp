#include<iostream>
using namespace std;
int main() {
	int binary;
	cin >> binary;
	int decimal = 0;
	int base = 2;
	while (binary > 0) {
		int last = decimal % 10;
		decimal += last * base;
		base = base * 2;
		binary = binary / 10;
	}cout <<binary;
	return 0;
}