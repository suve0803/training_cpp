#include<iostream>
#define cap 5

using namespace std;
int main() {
	int arr[cap];
	int search;
	int find;
	cout << "Enter the elements: " << endl;
	for (int i = 0;i < cap;i++) {
		cin >> arr[i];
	}
	cout << "The numbers are: " << endl;
	for (int i = 0;i < cap;i++) {
		cout << arr[i];
	}
	cout << endl;
	cout << "Enter the number: " << endl;
	cin >> search;
	int i;
	for (i = 0;i < cap;i++) {
		if (arr[i] == search) {
			break;
		}
	}
		if (i==cap) {
			cout << search << " not found" << endl;
		}
		else {
			cout << search << " found"<< endl;
		}
	
}