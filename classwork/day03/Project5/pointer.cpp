#include<iostream>
using namespace std;
int* func(int);
int main()
{
	int* ptr = NULL;
	ptr = func(10);
	cout << ptr << endl;
	*ptr = 201;
	cout << *ptr << endl;

	return 0;
}
int *func(int v)
{
	int r = 100;
	r = r + v;
	return &r;
}