#include<iostream>
using namespace std;
int main() {
	int* ptr = nullptr;
	int* temp = nullptr;
	int noofelement = 5;
	ptr = (int*)malloc(sizeof(int) * noofelement);
	temp = ptr;
	for (int i = 0;i < noofelement;i++,ptr++) {
		cout << "Enter the " << i + 1 << " value" << endl;
		cin >> *ptr;
	}
	temp = ptr;//reassign back the BA to the pointer
	for (int i = 0;i < noofelement;i++, ptr++)
		cout << i + 1 << " value= " << *ptr << endl;

	temp = ptr;//reassign back the BA to the pointer
	for (int i = 0;i < noofelement;i++)
		cout << i + 1 << " value= " << ptr[i] << endl;
	return 0;
}