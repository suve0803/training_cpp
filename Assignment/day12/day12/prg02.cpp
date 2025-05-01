#include<iostream>
using namespace std;

void matrixmul() {
	int arr1[3][3] = { {4,6,4},{6,9,10},{14,6,3} };
	int arr2[3][3] = { {8,5,2},{6,9,11},{8,3,12} };
	int arr3[3][3] = { {5,2,9},{7,9,3},{12,7,9} };
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				arr3[i][j] = arr3[i][j] + (arr1[i][j] * arr2[i][j]);
			}
		}
	}

}


int main() {


}