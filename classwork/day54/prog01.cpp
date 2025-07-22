/*binary search*/
#include<iostream>
using namespace std;
int binary_search(int arr[],int target,int start,int end) {
	while (start <= end) {
		int count=0;
		//int mid = (start + end) / 2;
		int mid = start+(end-start) / 2;
		count++;
		if (arr[mid] == target) {
			cout << "iteration: " << count << endl;
			cout << 'A' << endl;
			return mid;
		}
		else if (arr[mid] > target) {
			cout << 'B' << endl;
			end = mid - 1;
		}
		else if (arr[mid] < target) {
			cout << 'C' << endl;
			start = mid + 1;
		}
		else {
			cout << 'D' << endl;
			return -1;
		}
	}

}
int main() {
	int arr[7] = {3,6,7,11,32,33,53};
	int n = sizeof(arr) / sizeof(arr[0]);
	int res= binary_search(arr,33,0,n-1);
	if (res != -1) {
		cout << "The target is found in the index :" << res << endl;
	}
	else {
		cout << "The target is not found" << endl;
	}return 0;


}