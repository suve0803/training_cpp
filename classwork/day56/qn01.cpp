#include<iostream>
using namespace std;
void display(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
}
	void i_sort(int arr[], int n) {
		for (int i = 1;i < n;i++) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && key < arr[j]) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}
int main() {
	int arr[8] = { 9,-3,5,-2,-8,-6,1,3};
	int n = sizeof(arr) / sizeof(arr[8]);
	i_sort(arr, n);
	display(arr, n);
	return 0;
}
