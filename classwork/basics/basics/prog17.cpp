#include<iostream>
using namespace std;
int find(int a, int b) {
	while (b != 0) {
		int rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int gcd = find(n1, n2);
	cout << "The gcd is " << gcd;
	return 0;
}
