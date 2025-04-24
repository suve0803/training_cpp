#include<iostream>
#include"primefn.h"
using  namespace std;
int main() {
	int num;
	cout << "num: ";
	cin >> num;
	bool ret = isprime(num);//function calling
	if (ret == true)
		cout << "Given number: " << num << " is a prime number" << endl;
	else
		cout << "Given number:" << num << " is not a prime number" << endl;
	return 0;
}