#include<iostream>
#include"header.h"
using namespace std;
int elseifladder()
{
	int amtInHand;
	cout << "Enter the amount in hand: ";
	cin >> amtInHand;
	if(amtInHand<10)
	{
		cout << "Please get more amount" << endl;
	}
	else if (amtInHand >= 10 and amtInHand <= 50)
	{
		cout << "I can order Snacks" << endl;
	}
	else if (amtInHand > 50 and amtInHand <= 100)
	{
		cout << "I can order roti " << endl;
	}
	else if (amtInHand > 100 and amtInHand < 500)
	{
		cout << "I can order for complete meals" << endl;
	}
	else
	{
		cout << "You can order anything" << endl;
	}
	return 0;

}