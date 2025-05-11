/*Write a Program to Print a Triangle Star Pattern*/
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= i-1;j++) {
				cout << "*";
			}cout << endl;
		}
		/*cout << endl;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n-i;j++) {
				cout << "*";
			}cout << endl;
		}*/
}