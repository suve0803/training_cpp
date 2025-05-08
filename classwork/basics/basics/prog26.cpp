#include<iostream>
using namespace std;
int main() {
	int arr[] = { 2,7,5,43,7,12,4,2,43 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < n - 1;i++) {
		for (int j = i + 1;j < n;j++) {
			if (arr[i] == arr[j]) {
				for (int k = j;k < n - 1;k++) {
					arr[k] = arr[k + 1];
				}n--;
			}
			else {
				j++;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
}