/*calculate gross salary*/
#include<iostream>
using namespace std;
int main() {
	float BS, DA, HRA, GA;
	cout << "Enter the basic salary" << endl;
	cin >> BS;
	HRA = 40 * (BS / 100);
	cout << "House Rent Allowance: " << HRA << endl;
	DA = 20 * (BS / 100);
	cout << "Dearness Allowance: " << DA << endl;
	GA = HRA + DA;
	cout << "Gross Salary : " << GA << endl;
}