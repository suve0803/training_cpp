#include<iostream>
using namespace std;

int subarr(int arr[], int n, int sum1) {
	for (int i = 0;i < n;i++) {
		int sum2 = 0;
		for (int j = i;j < n;j++) {
			int sum2 = sum2 + arr[j];
			if (sum2 == sum1) {
				cout << "sum between" << i << j << endl;
			}
		}
	}
	cout << "subarrays are not found" << endl;
}

int main() {
	int n, sum;
	cout << "Enter size of array : " << endl;
	cin >> n;
	int arr[n];
	cout << "Enter the element: " << endl;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	cout << "Enter the sum: " << endl;
	cin >> sum;
	subarr(arr, n, sum);
		return 0;
}