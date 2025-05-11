/*Write a Program for Hexadecimal to Decimal Conversion*/
#include <iostream>
using namespace std;
int main()
{
	char hex[20];
	int decimal = 0, base = 1;
	cin >> hex;
	int i = 0;
	while (hex[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - '0') * base;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 'A' + 10) * base;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 'a' + 10) * base;
		}
		else
		{
			cout << "invalid hex digit:" << hex[i] << endl;
			return 1;
		}
		base *= 16;
		i--;
	}
	cout << "decimal: " << decimal << endl;
	return 0;
}