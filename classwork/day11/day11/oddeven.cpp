#include<iostream>
using namespace std;
int main() {
	int a[10], countodd, counteven=5;
	int i;
	for (i = 0, countodd = 0;i < 10;i++)
	{
		if (i % 2 != 0) {
			a[countodd] = i;
			countodd++;
		}
		else {
			a[counteven++] = i;
		}
	}


	for (i = 0;i < 10;i++)
		cout << a[i] << endl;
}