/*Problem Statement 5
You are given an array A of positive integers. Your task is to find and print all the leaders in the array.

An element is considered a leader if it is greater than all elements to its right. The rightmost element is always considered a leader.

Return the list of leaders in the same order as they appear from right to left in the original array.

*/


#include<iostream>
using namespace std;
#define SIZE 40


void leaders(int *arr, int integer) {
	int leaders = arr[integer-1] -1;
	for (int i = integer ;i >= 0;i--) {
		if (arr[i] > leaders) {
			cout << arr[i] <<" ";
			leaders = arr[i];
		}
	}
}


int main() {
	int arr[SIZE];
	int num;
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> arr[i];
	}

	leaders(arr, num);
}


/*output
6
6 7 4 3 5 2
2 5 7

5
2 6 3 8 4
4 8

*/