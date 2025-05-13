/*program to sort the list in ascending order using pointers */
#include<iostream>
using namespace std;
int* allocMem(int*, int);
int getValues(int*, int);
int sortAsc(int*, int);
void display(int*, int);
void swap(int&, int&);

int main() {
	int* ptr = nullptr;
	int size = 5;
	ptr = allocMem(ptr, size);
	getValues(ptr, size);
	cout << "Before sort: " << endl;
	display(ptr, size);
	sortAsc(ptr, size);
	cout << "After sort: " << endl;
	display(ptr, size);

	return 0;
}

int* allocMem(int* arr, int size) {
	arr = (int*)malloc(size * sizeof(int));
	return arr;
}
int getValues(int* arr, int size) {
	cout << "Enter values: " << endl;
	for (int i = 0;i<size;i++)
		cin >> *(arr++);
	return 0;
}
void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}
int sortAsc(int*arr, int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}return 0;
}
void display(int* arr, int size) {
	int i = 0;
	while (i < size) {
		cout << *arr++ << "\t";
		i++;
	}
}



