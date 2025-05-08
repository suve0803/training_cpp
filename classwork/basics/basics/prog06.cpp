#include<iostream>
using namespace std;
int main() {
	char ch;
	cin >> ch;
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ){
		cout <<ch<< " is a alphabet" << endl;
	}
	else {
		cout << ch<<" is not a alphabet" << endl;
	}
}