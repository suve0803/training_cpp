/*Problem Statement 3
You are given an array A of size N containing positive integers. For each element in the array, count the number of elements to its right that are smaller than the current element.

Your task is to compute and print a list of counts corresponding to each element.*/


#include<iostream>
#define SIZE 100
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[SIZE], res[SIZE] = { 0 };
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (arr[j] < arr[i]) {
				res[i]++;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}



/*
OUTPUT
4
4 4 2 1
2 2 1 0
*/