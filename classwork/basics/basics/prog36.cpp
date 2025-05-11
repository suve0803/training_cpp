#include<iostream>
using namespace std;

int binarytodecimal(int binary);
int decimaltobinary(int decimal);
int octaltodecimal(int octal);
int decimaltooctal(int decimal);

int main() {

}
int binarytodecimal(int binary) {
	int decimal = 0;
	int base = 1;
	while (binary > 0) {
		int last = decimal % 10;
		decimal += last * base;
		base = base * 2;
		binary = binary / 10;
	}
}