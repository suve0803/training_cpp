/* Write a program in C++ to convert temperature in Fahrenheit to Celsius. */
#include<iostream>
using namespace std;
int main() {
	float f, c;
	cout << "Enter temperature in Fahrenheit: " << endl;
	cin >> f;
	c = (f - 32) * 5.0 / 9.0;
	cout << "The temperature in celsius " << c;
	return 0;
}