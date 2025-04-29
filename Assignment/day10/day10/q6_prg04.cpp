#include<iostream>
using namespace std;
int secondlastdigit(int n) {
	n = n / 10;
	return n % 10;
}



int main() {
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;
	if (num < 10) {
		cout << "It does not have second last digit" << endl;

	}
	else {
		int res = secondlastdigit(num);
		cout << "The second last digit is: " << res << endl;
	}
	return 0;

}