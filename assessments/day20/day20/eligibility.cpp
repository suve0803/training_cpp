#include<iostream>
using namespace std;
int eligibility(int cut_off) {
	cout << "Enter the cut_off: " << endl;
	cin >> cut_off;
	if ((cut_off > 100) && (cut_off < 120)) {
		cout << "Eligible for ECE department";
	}
	else if ((cut_off >= 120) && (cut_off < 130)) {
		cout << "Eligible for CSE department";
	}
	else if ((cut_off >= 130) && (cut_off < 140)) {
		cout << "Eligible for AI/ML department";
	}
	else {
		cout << "Not Eligible";
	}
}