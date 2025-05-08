#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << fib(n);
	return 0;
}
int fib(int n) {
	int n1 = 0, n2 = 1, res;
	if (n == 0) {
		return n1;
		for (int i = 2;i <= n;i++) {
			res = n1 + n2;
			n2 = res;
		}return res;
	}
	return 0;
}