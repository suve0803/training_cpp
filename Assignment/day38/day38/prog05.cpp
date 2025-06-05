/*Unique Visitor Tracker*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	set<string> userId;
	string s = "";
	while (s != "exit")
	{
		getline(cin, s);
		if (s.find("VISIT ") != string::npos)
			userId.insert(s.substr(6));
		else if (s == "UNIQUE")
			cout << userId.size() << endl;
		else if (s == "TOP")
		{
			for (string id : userId)
				cout << id << " ";
		}
	}
	return 0;
}
