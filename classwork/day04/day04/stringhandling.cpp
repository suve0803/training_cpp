#include<iostream>
#include"stringHandling.h"
#include<cstring>
using namespace std;

void stringHandling()
{
	char ch = 'A';
	char fName[20];//array of chars
	string sName;//string

	cout << "ch value : " << ch << endl;
	cout << "Enter First Name: ";
	cin >> fName;
	cout << "Enter Second Name: ";
	cin >> sName;
	cout << "\nMy Name is : " << fName << "\a" << sName << endl;


	char Name[] = "Hello";
	cout << sizeof(Name) << endl;
	cout << "String length of Name: " << strlen(Name) << endl;

	//scanf("%s", Name);
	for (int i = 0;i < sizeof(Name);i++) {
		printf("\n%c=%d", Name[i], Name[i]);
		
	}
}

