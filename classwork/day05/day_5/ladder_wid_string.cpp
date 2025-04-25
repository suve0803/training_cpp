#include<iostream>
using namespace std;
int main()
{
	string genre;
	cout << "Enter the Genre:";
	cin >> genre;
	if (genre[0] >= 48 && genre[0] <= 57)
	{
		cout << "Genre Name should no start with numeric characters" << endl;
		return 0;
	}
	if (genre.compare("Action") == 0)
	{
		cout<<"Selected genre is action"<<endl
	}
}