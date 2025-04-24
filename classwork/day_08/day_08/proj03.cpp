/*Function no arg and with return type*/

#include<iostream>
using namespace std;
void display(void);
int displayRet(void);
void sumOfIntegers(int, int);
int main() {
	/*int ch;
	display();
	cin >> ch;
	switch (ch)*/
	switch(displayRet())
	{
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

int displayRet()
{
	int ch;
	cout << "Press" << endl;
	cout << "1.Add" << endl;
	cout << "2.sub" << endl;
	cout << "3.exit" << endl;
	cout << "choice" << endl;
	cin >> ch;
	return ch;
}

void sumOfIntegers(int v1, int v2) {
	cout << v1 << "+" << v2 << "=" << (v1 + v2) << endl;
}