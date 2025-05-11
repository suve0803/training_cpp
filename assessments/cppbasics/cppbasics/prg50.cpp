/* Write a Program for Decimal to Hexadecimal Conversion */
/*Write a Program for Decimal to Hexadecimal Conversion*/
#include <iostream>
using namespace std;
int main() {
	int dec_Num;
	cin >> dec_Num;
	char hexDigits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'A', 'B', 'C', 'D', 'E', 'F' };
	string hexNumber = "";
	while (dec_Num > 0) {
		int rem = dec_Num % 16;
		hexNumber = hexDigits[rem] + hexNumber;
		dec_Num /= 16;
	}
	cout << "Hexadecimal number: " << hexNumber << endl;

	return 0;
}