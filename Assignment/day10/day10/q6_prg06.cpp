#include<iostream>
using namespace std;

bool sumofeven(int a, int b) {
	int sum = a + b;
	return(sum % 2 == 0);
}

int main() {
	int n1, n2;
	cout << "Enter 2 numbers: ";
	cin >> n1 >> n2;
	if (sumofeven(n1, n2)) {
		cout << "The sum is even" << endl;
	}
	else {
		cout << "The sum is odd" << endl;
	}
	return 0;
}