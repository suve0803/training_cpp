#include<iostream>
using namespace std;

void binaryArray(int arr[], int n) {
	int i = 0;
	for (int j = 0;j < n;j++) {
		if (arr[j] == 0) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	/*int index = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i] == 0) {
			arr[index++] = 0;
			while(index<n)
				arr[index++] = 1;
			
		}
	}*/
}
void display(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
		cout << endl;
	}
}
int main() {
	int arr[] = { 1,0,0,0,1,0,1,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	binaryArray(arr, n);
	display(arr, n);
	return 0;
}