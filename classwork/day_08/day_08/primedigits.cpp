#include<iostream>
using namespace std;
bool nprime(int);
int getdigit(int);
int main() {
	int N;
	cout << "num: ";
	cin >> N;
	bool ret = nprime(N);//function calling
	if (ret == true)
		cout << "Given number: " << N << endl;
}
bool nprime(int N) {

	bool flag = false;
	if (N <= 1)
		return false;
	for (int i = 2;i <= N / 2;i++) {
		if (N % i == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
		return true;
	else
		return false;
}
int getdigit(int N) {
	int digit;
	while (N > 0) {
		digit = N % 10;
		cout << digit;
		if (nprime(digit) == true) {
			cout << digit;
		}
		N /= 10;
	}
	return 0;
}