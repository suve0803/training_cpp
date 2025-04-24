/*Function with arg and no return type*/

#include<iostream>
using namespace std;
void display(void);
void sumOfIntegers(int, int);
int main() {
	int ch;
	display();
	cin >> ch;
	switch (ch) {
	default:
		cout << "Wrong choice" << endl;
		break;
	case 1:
		cout << "Addition" << endl;
		sumOfIntegers(10, 20);
		break;
	case 2:
		cout << "subraction" << endl;
		break;
	case 3:
		cout << "Exit the application" << endl;
		break;
	}
	return 0;
}
void display()
{
	cout << "Press" << endl;
	cout << "1.Add" << endl;
	cout << "2.sub" << endl;
	cout << "3.exit" << endl;
	cout << "choice" << endl;
}

void sumOfIntegers(int v1, int v2) {
	cout << v1 << "+" << v2 << "=" << (v1 + v2) << endl;
}