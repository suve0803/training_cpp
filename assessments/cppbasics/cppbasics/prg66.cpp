#include<iostream>
using namespace std;

void swap(int a, int b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int main() {
	int x, y;
	cout << "Enter 2 nums: ";
	cin >> x >> y;
	cout << "Before swapping: " << x << " , " << y << endl;
	swap(x, y);
	cout << "After swapping: " << y << " , " << x << endl;
	return 0;

}