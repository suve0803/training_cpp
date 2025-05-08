#include<iostream>
using namespace std;
int main()
{
	int n = 6;
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (i <= n / 2 && j <= n / 2) {
				cout << "*";
			}
			else if (i <= n / 2 && j >= n / 2) {
				cout << "*";
			}
			else if (i <= n / 2 && j >= n / 2) {
				cout << "*";
			}
			else {
				cout << "*";
			}
		}cout << endl;
	}
}