/* Write a Program to Find the Sum of the First N Natural Numbers */
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		sum+=i;
	}
	cout << sum;
}