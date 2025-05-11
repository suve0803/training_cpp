/* Write a program in C++ to check whether the primitive values crossing the limits or not.*/
#include <iostream>
#include <limits>
using namespace std;
int main() {
	int num;
	cout << "enter a number: ";
	cin >> num;
	if (num<INT_MIN || num>INT_MAX)
	{
		cout << "The number is out of integer limits" << endl;
	}
	else
	{
		cout << "The number is within integer limit" << endl;
	}

	return 0;
}