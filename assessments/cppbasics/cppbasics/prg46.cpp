/*Write a Program for Octal to Decimal Conversion*/
#include <iostream>
using namespace std;
int main()
{
	int oct, dec = 0, place = 0;
	cin >> oct;
	int temp = oct;
	while (temp)
	{
		int lastdigit = temp % 10;
		temp /= 10;
		dec = dec + lastdigit * pow(8, place);
		place++;
	}
	cout << dec;
	return 0;
}