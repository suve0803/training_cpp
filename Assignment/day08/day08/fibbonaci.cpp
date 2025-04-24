#include<iostream>
using namespace std;
int fib(int n) {
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

/*int fact(int n2) {
	for (int i = 1;i <= n2;i++) {
		fact *= i;
	}
}*/
int main() {
	int n;
	cout << "Enter the number n: ";
	cin >> n;
	cout << fib(n);
	//cout << fact(n);
	return 0;

}