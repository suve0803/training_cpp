#include<iostream>
using namespace std;
int display();
int main() {
BEGIN:
	while (true) {
		int ret = display();
		switch (ret)
		{
		case 1:
			cout << "Addition" << endl;
			break;
		case 2:
			cout << "Subraction" << endl;
			break;
		case 3:
			cout << "multiplication" << endl;
			break;
		case 0:
			cout << "Existing the application" << endl;
			exit(0);
			break;
		default:
			cout << "Wrong choice" << endl;
		}
	}
END:
	cout << "\n Program ended successfully" << endl;
	goto BEGIN;
	return 0;
}
int display()
{
	int ch;
	cout << "Press, " << endl;
	cout << "1.Addition" << endl;
	cout << "2.Subraction" << endl;
	cout << "3.Multiplication" << endl;
	cout << "0.Exit" << endl;
	cout << "Choice: ";
	cin >> ch;
	return ch;
}