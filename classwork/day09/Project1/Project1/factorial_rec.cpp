#include<iostream>
using namespace std;
int main() {
	int n = 5;
	int ret= fact(n);
	cout << ret;
	return 0;
		
}
int fact(int n) {
	int retval = 1;
	cout << n << endl;
	if (n == 0||n==1)
		return 1;
	retval = n * fact (n-1);
	return retval;
	
}