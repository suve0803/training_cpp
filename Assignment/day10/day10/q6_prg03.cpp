#include<iostream>
using namespace std;
bool leapyear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int year;
	cout << "Enter a year: ";
	cin >> year;
	if (leapyear(year)) {
		cout << "It is a leap year" << endl;
	}
	else {
		cout << "It is not a leap year" << endl;
	}
	return 0;

}