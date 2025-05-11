/* Write a program in C++ that converts kilometers per hour to miles per hour. */
#include<iostream>
using namespace std;
int main() {
	float kmph, mph;
	cout << "Enter speed in km/hr : " << endl;
	cin >> kmph;
	mph = kmph * 0.621;
	cout << "Speed in m/hr: " << mph << endl;
	return 0;
}