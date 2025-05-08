#include<iostream>
using namespace std;
int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a > b) 
	{
		if (a > c) 
		{
			if (a > d) 
			{
				cout << "a is greater";
			}
			else {
				cout<<"e is greater";
			}
		}
	}
	else if (b > c) {
		if (b > d) {
			cout << "b is greater";
		}
		else {
			cout << "e is greater";
		}
	}
	else if (c > d) {
		cout << "c is greater";
	}
	else {
		cout << "e is greater";
	}
	return 0;
}