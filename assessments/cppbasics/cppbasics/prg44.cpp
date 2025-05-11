/*Write a Program to Check for the Equality of Two Numbers Without Using Arithmetic or 
Comparison Operator*/
#include<iostream>
using namespace std;
int main() {
	int n1,n2;
	cin >> n1 >> n2;
	if ((n1 ^ n2) == 0) {
		cout << n1 << " and " << n2 << " are equal";
	}
	else {
		cout << n1 << " and " << n2 << " are not equal";
	}
}