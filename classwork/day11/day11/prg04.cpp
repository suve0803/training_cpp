#include<iostream>
using namespace std;
int main() {
	int a[10],countodd,counteven;
	int i;
	for (i = 0,countodd=0;i < 10;i++)
		 {
		if (i % 2 != 0){
			a[countodd] = i;
		countodd++;

		}
		}

	for (i = 0, counteven = countodd;i < 10;i++)
	{
		if (i % 2 == 0) {
			a[counteven] = i;
			counteven++;

		}
	}


	for (i = 0;i < 10;i++)
		cout << a[i] << endl;
}