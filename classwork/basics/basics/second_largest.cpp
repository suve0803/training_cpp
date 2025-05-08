#include<iostream>
using namespace std;
int main() {
	int a[] = { 23,43,12,8,17,33 };
	int n = sizeof(a) / sizeof(a[0]);
	int t;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (a[j] > a[j + 1])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}

	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << endl;
	cout << a[n + 2] << endl;
}