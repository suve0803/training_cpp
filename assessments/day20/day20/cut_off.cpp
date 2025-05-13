#include<iostream>
using namespace std;
int cut_off(int physics, int chemistry, int maths) {
	int cut_off = (physics / 100) + (chemistry / 100) + (maths / 100) / 3;
	if ((cut_off >= 100) && (cut_off < 120)) {
		cout << "Eligible for the department ECE";
	}
	else if ((cut_off >= 120) && (cut_off < 130)) {
		cout << "Eligible for the department CSE";
	}
	else if ((cut_off >= 130) && (cut_off < 140)) {
		cout << "Eligible for the department EEE";
	}
	else {
		cout << "Not Eligible";
	}
	return 0;
}
int main() {
	int cut_off();
	int physics;
	int chemistry;
	int maths;
	cout << "Enter Physics Mark:" << endl;
	cin >> physics;
	cout << "Enter Chemistry Mark:" << endl;
	cin >> chemistry;
	cout << "Enter Maths Mark:" << endl;
	cin >> maths;


}