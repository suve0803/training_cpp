#include<iostream>
using namespace std;

bool prime(int n) {
	if (n <= 1) {
		return 0;
	}for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			return 0;
		}
	}return 1;
}
int main() {
	int n;
	cin >> n;
	if (prime(n)) {
		cout << n << " is a prime num" << endl;
	}
	else {
		cout << n << " is not a prime num" << endl;
	}

}