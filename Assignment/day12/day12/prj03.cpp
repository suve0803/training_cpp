#include<iostream>
using namespace std;
int main() {
	int arr1[2][2] = { {4,6},{6,9} };
	int arr2[2][2] = { {8,5},{6,9}};
	int arr3[2][2] = {0};
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 2;j++) {
			for (int k = 0;k < 2;k++) {
				arr3[i][j] +=arr1[i][k] * arr2[k][j];
			}
		}
	}
	cout << "Matrix : " << endl;
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 2;j++) {
			cout << arr3[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}