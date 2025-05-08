#include<iostream>
using namespace std;
int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a > b && a > c && a > d && a > e) {
		cout << "a is greater" << endl;
	}
	else if (b > a && b > c && b > d && b > e) {
		cout << "b is greater" << endl;
	}
	else if (c > a && c > b && c > d && c > e) {
		cout << "c is greater" << endl;
	}
	else if (e > a && e > b && e > c && e > d) {
		cout << "e is greater" << endl;
	}
	else{
		cout << "d is greater" << endl;
	}
}