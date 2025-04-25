/*Amstrong Number*/
#include<iostream>
using namespace std;
int main() {
	int n1, n2, reminder, result = 0;
	cout << "Enter the number: " << endl;
	cin >> n1;
	n2 = n1;
	while (n2 != 0) {
		reminder = n2 % 10;
		result = result + reminder * reminder * reminder;
		n2 /= 10;
	}
	if (result == n1) {
		cout << n1 << " is a amstrong number" << endl;
	}
	else {
		cout << n1 << " is a not amstrong number" << endl;
	}
	return 0;
}