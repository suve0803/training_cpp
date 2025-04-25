#include<iostream>
#include<string>
using namespace std;
int main()
{
	int _id = 0;
	int itr1=0,itr2;
	char first_name[100] = { '\o', }, second_name[100] = { '\0', };
	memset(first_name, '\0', sizeof(first_name));
	for (int itr2 = 0;itr2 < 10;itr2++)
		cout << itr2 << endl;

	cout << itr1 << endl;

	strcat(first_name, "hello");
	cout << first_name << endl;
	register int i;
	for (i = 0;i < 100;i++)
		cout << i << endl;
	bool flag = true;

	cout << flag << endl;
	flag = false;
	cout << flag << endl;
	{
		int itr1 = 202;
		cout << itr1 << endl;
	}
}