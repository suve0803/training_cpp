#include<iostream>
using namespace std;
int main() {
	int a[3] = { 10,20,30 };
	int* ptr = a;
	cout << *ptr++ << endl;
	cout << *++ptr << endl;//points to the next location
	cout << *ptr++ << endl;

	ptr = a;//reassign to the base address
	int prod = *ptr * *ptr;
	cout << prod << endl;

	cout << sizeof(ptr) << " " << sizeof(void*) << endl;
	return 0;
}