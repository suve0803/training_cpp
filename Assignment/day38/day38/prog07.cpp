/*Unique Stock Prices*/

#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	set<int>s;
	string commands;
	int price;
	while (true) {
		cout << "Enter commands: " << endl;
		cin >> commands;
		if (commands == "ADD") {
			cin >> price;
			s.insert(price);
			
			cout << price;
		}
		else if (commands == "REMOVE") {
			s.erase(price);
			cout << "Price after removed: " << price;
		}
		else if (commands == "MIN") {
			s.lower_bound(price);
			cout << "Minimum Price: " << price;
		}
		else if (commands == "MAX") {
			s.upper_bound(price);
			cout << "Maximum Price: " << price;
		}
		else {
			cout << "Invalid commands" << endl;
		}
	}
	return 0;
}