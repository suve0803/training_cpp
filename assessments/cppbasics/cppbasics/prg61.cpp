/* Sum of First N Natural Numbers */

#include<iostream>
using namespace std;

int sumNum(int n) {
	if (n <= 0) {
		return 0;
	}
	return n + sumNum(n - 1);
}



int main() {
	int N;
	cout << "Enter value of N: ";
	cin >> N;
	int sum = sumNum(N);
	cout << "The sum of N natural numbers are " << sum;
	return 0;
}