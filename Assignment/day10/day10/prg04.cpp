#include<iostream>
using namespace std;

int countzeros(int n) {
	if (n == 0) {
		return 1;
	}
	else if(n < 10) {
		return 0;
	}
	else{
		if (n % 10 == 0) {
			return 1 + countzeros(n / 10);
	}
		else {
			return countzeros(n / 10);
		}
	}
}

int main() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	int zerocount = countzeros(num);
	cout << "Number of zeros " << zerocount;


}