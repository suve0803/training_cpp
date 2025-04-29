#include<iostream>
using namespace std;
int main() {
	int arr[3];
	cout << "Capacity of Array= " << sizeof(arr) << endl;
	cout << "Address of arr[0]= " << &arr[0] << endl;
	cout << "Address of arr[1]= " << &arr[1] << endl;
	cout << "Address of arr[2]= " << &arr[2] << endl;
	cout << "Address of arr[0]= " << (unsigned long) & arr[0] << endl;



	printf("Address of arr[0]= %u\n", &arr[0]);
	printf("Address of arr[1]= %u\n", &arr[1]);
	printf("Address of arr[2]= %u\n", &arr[2]);

}