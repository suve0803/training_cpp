/*Problem Statement 4
You are given an array A of N positive or negative integers. Your task is to find the first equilibrium position in the array.

An equilibrium position is an index i such that the sum of elements before index i is equal to the sum of elements after index i.

Return the first equilibrium index (0-based indexing). If no such index exists, return -1.*/

#include<iostream>
using namespace std;
#define SIZE 40

int check(int* arr, int integer)
{
	int l, r;
	for (int i = 0;i < integer;i++) {
		r = r + arr[i];
	}
	for (int i = 0;i < integer;i++) {
		r = r - arr[i];
		if (l == r)
			return 1;
		l = l + arr[i];

	}
	return 0;
}


int main() {
	int arr[SIZE];
	int integer;
	cin >> integer;
	for (int i = 0;i < integer;i++) {
		cin >> arr[i];
	}
	int start = check(arr, integer);
	cout << start << endl;
}