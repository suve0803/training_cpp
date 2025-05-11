#include<iostream>
using namespace std;
int findval(int n1, int n2, int n3) {
	if ((n1 > n2 && n1 < n3) || (n1<n2 && n1>n3)) {
		return n1;
	}
	else if ((n2 > n1 && n2 < n3) || (n2<n1 && n2>n3)) {
		return n2;
	}
	else {
		return n3;
	}
}



int main() {
	int n1, n2, n3;
	cout << "Enter the numbers : ";
	cin >> n1, n2, n3;
	int mid_val = findval(n1, n2, n3);
	cout << "The middle value is: " << mid_val;
	return 0;
}