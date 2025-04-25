/*Reverse the number*/
#include<iostream>
using namespace std;
int main() {
	int n,j,rev=0;
	cout << "Enter a num: "<<endl;
	cin >> n;
	for (;n > 0;n /= 10) {
		j = n % 10;
		rev = rev * 10 + j;
	}
	cout << rev;
}