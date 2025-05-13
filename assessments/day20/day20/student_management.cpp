#include<iostream>
#include<string>

using namespace std;

void std_data(int std_id, char std_name[50], int std_ph_1, int std_ph_2, char std_add[300], char std_dept[10], char std_mail[50], int tenth_percent, int twelth_percent, char quota[10], char category[10])
{
	cout << "Enter Student ID";
	cin >> std_id;

	cout << "Enter Student Name";
	cin.getline(std_name, 50);

	cout << "Enter Student's Primary Phone Number";
	cin >> std_ph_1;

	cout << "Enter Student's Secondary Phone Number";
	cin >> std_ph_2;

	cout << "Enter Student Address";
	cin.getline(std_add, 300);

	cout << "Enter Student Department";
	cin.getline(std_dept, 10);

	cout << "Enter Student Mail ID";
	cin.getline(std_mail, 50);

	cout << "Enter 10th percentage";
	cin >> tenth_percent;

	cout << "Enter 12th percentage";
	cin >> twelth_percent;

	cout << "Enter Quota";
	cin.getline(quota, 10);

	cout << "Enter Category";
	cin.getline(category, 10);
}