/*selection sort*/
#include<iostream>
using namespace std;
void display(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout <<endl;
}
void selectionsort(int arr[], int n) {
	for (int i = 0;i < n - 1;i++) {
		int min_index = i;
		for (int j = i + 1;j < n;j++) {
			if (arr[j]<arr[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(arr[i], arr[min_index]);
		}
	}
}
int main() {
	int arr[7] = { 2,4,1,6,3,9,6 };
	int n = sizeof(arr) / sizeof(arr[7]);
	cout << "Before swap: ";
	display(arr, n);
	selectionsort(arr, n);
	cout << "after swap: ";
	display(arr, n);
	return 0;
}