/*Calculate Compound Interest
Given principal P, rate R, and time T, find Compound Interest.
Formula: A = P * (1 + R/100)^T, CI = A - P
Use only basic operators.*/


#include<iostream>
using namespace std;
int main() {
	int A, P, R, T;
	cout << "Enter the principal: " << endl;
	cin >> P;
	cout << "Enter the Rate of Interest: " << endl;
	cin >> R;
	cout << "Enter the time: " << endl;
	cin >> T;
	A = P * (1 + R / 100) ^ T;
	int CI = A - P;
	cout << "The compound interest is  " << CI << endl;
}