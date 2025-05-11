/*Write a C++ Program to Check Whether a Number is a Positive or Negative Number*/
#include<iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	if (num > 0) {
		cout << num << " is positive";
	}
	else if(num<0){
		cout << num << " is negative";
	}
	else {
		cout << "It is zero";
	}
	return 0;
}