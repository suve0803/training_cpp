#include<iostream>
using namespace std;
int main() {
	int start,end;
	cout << "Enter the start value: " << endl;
	cin >> start;
	cout << "Enter the end value: " << endl;
	cin >> end;
	if (start > end) {
		cout << "Invalid values" << endl;

	}
	for (int i = 1;i<= 10;i++) {
		//cout << i << endl;
		for (int j = start;j <= end;j++) {
			cout << j << "x" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}
	return 0;
}