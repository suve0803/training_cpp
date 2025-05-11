/* Write a Program to Find the Nth Term of the Fibonacci Series */
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int fst = 0, snd = 1, nth;
	for (int i = 3;i <= n;i++) {
		nth = fst + snd;
		fst = snd;
		snd = nth;
	}
	cout << nth;
	return 0;
}