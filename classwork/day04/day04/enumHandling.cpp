#include<iostream>
using namespace std;


void enumHandling()
{
	enum Day { Monday = 100, Tuesday, Wednesday = 200, Thursday, Friday, Saturday };
	Day today = Tuesday;
	cout << "value of today : " << today << endl;
	
}