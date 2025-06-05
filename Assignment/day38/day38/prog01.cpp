/*std::list<string> – Text Editor Buffer (Doubly Linked List)*/

#include<iostream>
#include<list>
#include<string>
using namespace std;

int main() {
	std::list<std::string> T;
	int cur_pos = 0;
	std::string commands, line;
	while (true) {
		cout << "Enter command: ";
		cin >> commands;
		if (commands == "INSERT") {
			cout << "Enter line to insert: " << endl;
			cin >> line;
			auto it = T.begin();          
			for (int i = 0; i < cur_pos; i++) {
				it++;
			}

			T.insert(it, line);             
			cur_pos++;                       
		}
		else if (commands == "UP") {
			if (cur_pos > 0) {
				cur_pos--;
			}
			else {
				cout << "Cursor is already in the top";
			}
		}
		else if (commands == "DOWN") {
			if (cur_pos < T.size()) {
				cur_pos++;
			}
			else {
				cout << "Cursor is already in the bottom";
			}
		}
		else if (commands == "PRINT") {
			cout << "Text Buffer: ";
			for (auto& line : T) {
				cout << line << endl;         
			}
		}
		else if (commands == "EXIT") {
			break;                                
		}
		else{
			cout << "Invalid command." << endl;

		}
	}
	return 0;
}