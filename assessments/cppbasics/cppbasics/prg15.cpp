/* Write a Program to Find a Leap Year or Not */
#include<iostream>
using namespace std;
int main() {
	int year;
	cin >> year;
	if((year % 4 == 0&&year%100!=0)||(year%400==0)) {
		cout << year << " is a leap year";
	}
	else {
		cout << year << " is not a leap year";
	}
}