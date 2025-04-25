/*sum and percentage of student mark*/
#include<iostream>
using namespace std;
int main() {
	float m1, m2, m3, m4, m5;
	float total = 500.00;
	float sum, percent;
	cout << "Enter the marks:" << endl;
	cin >> m1 >> m2 >> m3 >> m4 >> m5;
	if (m1 <= 100 && m2 <= 100 && m3 <= 100 && m4 <= 100 && m5 <= 100) {
		sum = m1 + m2 + m3 + m4 + m5;
		percent = sum / 5;

		cout << "sum: " << sum << endl;
		cout << "percent: " << percent << endl;
	}
	else {
		cout << "The mark is invalid" << endl;
	}



}