#include<iostream>
using namespace std;
int main() {
	int arr[3] = { 101,201,301 };//dec with initialization
	cout << "arr[0]= " << arr[0] << endl;
	cout << "arr[1]= " << arr[1] << endl;
	cout << "arr[2]= " << arr[2] << endl;
	cout << "arr[3]= " << arr[3] << endl;//garbage value as arr is out of bound

	for (int i = 0; i < 3; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
		arr[0] = 103;
		arr[1] = arr[0] * 10;
		for (int i = 0; i < 3; i++) {
			cout << "arr[" << i << "] = " << arr[i] << endl;
	}

}