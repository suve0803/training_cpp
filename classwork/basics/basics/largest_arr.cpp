#include <iostream>
using namespace std;

int main() {

	int arr[] = { 12,5,8,20,3,15};
	//int size = sizeof(arr) / sizeof(arr[0]);
	int max = arr[0];
	int min = arr[0];

	for (int i = 1; i < 6; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}if (arr[i] < min) {
			min = arr[i];
		}
	}

	cout << max << endl;
	cout << min << endl;

	return 0;
}



