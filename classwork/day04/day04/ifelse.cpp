#include<iostream>
using namespace std;
typedef struct users {
	int _id;
	int userType;
	string userName;
}USERS;
void dispMenuNU();
void dispMenuAU();

int main()
{
	USERS u;
	cout << "Enter id";
	cin >> u._id;
	cout << "Enter userType(0/1)";
	cin >> u.userType;
	cout << "Enter User Name: ";
	cin >> u.userName;

	if (u.userType == 0)
	{
		dispMenuAU();
	}
	else {
		dispMenuNU(u.userName);
	}
	cout << "Application Ended successfully" << endl;

}