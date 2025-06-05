/*std::deque<string> – Recent Command Tracker*/

#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
	deque<string>commands;
	string s = "";
	while (s != "exit")
	{
		getline(cin, s);
		if (s.find("RUN") != string::npos)
		{
			commands.push_back(s.substr(4));
			if (commands.size() > 4)
				commands.pop_front();
		}
		else if (s == "HISTORY")
		{
			for (string i : commands)
				cout << i << endl;
		}
	}
}