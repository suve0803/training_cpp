#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "Enter the value n: " << endl;
	cin >> n;

	int sum = 0;
	int product = 1;
	while (n > 0) {
		int digit = n % 10;
		sum = sum + digit;
		if(digit!=0){
		product = product * digit;
		}
		n = n / 10;
		//cout << digit;
	}
	cout << "sum of integers: " << sum << endl;
	cout << "product of integers: " << product << endl;
	{
		return 0;
	}
}