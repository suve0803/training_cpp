#include<iostream>
using namespace std;
int main() {
	int n = 4;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= i;j++) {
			cout << "* ";
		}for (int k = 0;k < 2 * (n - i) -1 ;k++) {
			cout << "  ";
	
		}
		
		/*if (i != n )
			cout << "  ";
		else
		*/
		if (i == n)
		{
			for (int j = 0; j <  n ; j++)
				cout << "* ";
			continue; 
		}
		

		
		for (int l = 0;l <=i;l++) {
			cout << "* ";
		}cout << endl;
	}
	for (int i = n - 1;i >= 0;i--) {
		for (int j = 0;j <= i;j++) {
			cout << "* ";
		}for (int k = 0;k < 2 * (n - i) -1 ;k++) {
			cout << "  ";
		
		}
		//cout << "  ";
		for (int l = 0;l <= i;l++) {
			cout << "* ";
		}cout << endl;
	}
}

