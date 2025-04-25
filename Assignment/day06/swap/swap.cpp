/*Swap 2 numbers*/
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "Enter the numbers : " << endl;
	cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "After Swapping : " << a << b << endl;
	return 0;

}