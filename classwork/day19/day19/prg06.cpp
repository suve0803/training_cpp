#include<iostream>
using namespace std;
int main() {
	int a = 10;
	/*int* ptr = &a;
	*ptr = 101;
	cout <<*ptr << endl;*/
	int* ptr = (int*)malloc(sizeof(int)*3);
	int* temp = ptr;
	cout << "Address of ptr= " << (unsigned long int)ptr << endl;
	*ptr = 202;
	ptr++;
	cout << "Address of ptr= " << (unsigned long int)ptr << endl;
	*ptr = 203;
	ptr++;
	cout << "Address of ptr= " << (unsigned long int)ptr << endl;
	*ptr = 204;
	ptr = temp;//reassign back to the base address of the list

	cout << *ptr++ << endl;
	cout << *ptr++ << endl;
	cout << *ptr++ << endl;
	return 0;
}