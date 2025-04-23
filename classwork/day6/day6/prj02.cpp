/*incrementing squared number-star Pattern*/

#include<iostream>
using namespace std;
int main() {
	int n, i1 = 1;
	cout << "Enter the input n:" << endl;
	cin >> n;
	while (i1 <= (n * n)) {
		if (i1 % n == 0)
			cout << i1 << endl;
		else
			cout << i1 << "*";
		i1++;

	}
}

