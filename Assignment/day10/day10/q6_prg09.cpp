#include<iostream>
using namespace std;

bool triangle(int a, int b, int c) {
	return(a + b + c == 180);
}

int main() {
	int a1, a2, a3;
	cout << "Enter 3 angles: ";
	cin >> a1 >> a2 >> a3;
	if (triangle(a1, a2, a3)) {
		cout << "It is a triangle" << endl;
	}
	else {
		cout << "It is not a triangle" << endl;
	}
	return 0;
}