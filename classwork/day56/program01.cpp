#include<iostream>
using namespace std;
void display(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
}
void move_neg(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		//int key=0;
		//if (key < 0) {
		//	//int key = arr[i];
		//	int j = i;
		//	while (j > 0 && arr[j - 1] >= 0) {
		//		arr[j] = arr[j - 1];
		//		j--;
		//	}
		//	arr[j] = key;
		//}
		if (arr[i] < 0) {
			int temp = arr[i];
			int j = i;
			while (j > 0 && arr[j - 1] >= 0) {
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = temp;
		}
	}
}
int main() {
	int arr[8] = { 9,-3,5,-2,-8,-6,1,3 };
	int n = sizeof(arr) / sizeof(arr[8]);
	move_neg(arr,n);
	display(arr, n);
	return 0;
}