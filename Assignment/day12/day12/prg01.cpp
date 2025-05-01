#include<iostream>
#define ROW 3
#define COL 3


using namespace std;
int main() {
	int arr1[ROW][COL] = { {10,20,30},{40,50,60},{70,80,90} };
	int arr2[ROW][COL] = { 10,20,30,40,50,60,70,80,90 };
	int arr3[ROW][COL];

	for (int i = 0, count = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			cout << "Address of array[" << count++ << "] = " << (unsigned long int) & arr1[i][j] << endl;
		}
	}cout << "==================================" << endl;
	for (int i = 0, count = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			cout << "Address of array[" << count++ << "] = " << (unsigned long int) & arr1[i][j] << endl;
		}
	}cout << "==================================" << endl;
	for (int i = 0, count = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			cout << "Enter the : "<<count++<<"item value: " << endl;
			cin >> arr3[i][j];
		}
	}cout << "==================================" << endl;
	return 0;
}