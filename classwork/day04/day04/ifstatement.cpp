#include<iostream>
#define MAXCAP 100
using namespace std;
int ifstatement()
{
	int capCurrent, unusedCap=0;
	cout << "Enter the current Capacity : ";
	cin >> capCurrent;
	unusedCap = MAXCAP - capCurrent;
	if (unusedCap == 0)
	{
		cout << "Storage is full" << endl;
		return 0;
	}
	cout << "you can store items in the storage" << endl;
	return 0;
}
