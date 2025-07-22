/*insertion sort*/
#include<iostream>
using namespace std;
void display(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void insertionsort(int arr[], int n) {
	for (int i = 1;i < n;i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key<arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main() {
	int arr[7] = { 2,4,1,6,3,9,6 };
	int n = sizeof(arr) / sizeof(arr[7]);
	cout << "Before swap: ";
	display(arr, n);
	insertionsort(arr, n);
	cout << "after swap: ";
	display(arr, n);
	return 0;
}