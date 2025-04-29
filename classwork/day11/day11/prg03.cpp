#include<iostream>
using namespace std;
int main() {
	int arr[10];
	int search;
	int find;
	cout << "Enter the elements: " << endl;
	for (int i = 0;i < 10;i++) {
		cin >> arr[i];
	}
	cout << "The numbers are: " << endl;
	for (int i = 0;i < 10;i++) {
		cout << arr[i];
	}
	cout << endl;
	cout << "Enter the number: " << endl;
	cin >> search;
	for (int i = 0;i < 10;i++) {
		if (arr[i] == search) {
			 find= true;
		}
		if (find) {
			cout << search << "found" << endl;
		}
		else {
			cout << search << "not found"<< endl;
		}
	}
}