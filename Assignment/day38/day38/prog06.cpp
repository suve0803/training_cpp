/*Banned Words Filter*/


#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	set<string>bannedWords{ "bad", "evil", "vulgar" };
	string text = "this is a bad example with evil words";
	cout << "Text: " << text << endl;
	string filter;
	string word;
	for (char ch : text) {
		if (ch == ' ') {
			if (!word.empty() && bannedWords.find(word) == bannedWords.end()) {
				if (!filter.empty()) {
					filter += " ";
				}filter += word;
			}word.clear();
		}
		else {
			word += ch;
		}
		/*if (!word.empty() && bannedWords.find(word) == bannedWords.end()) {
			if (!filter.empty()) {
				filter += " ";
			}filter += word;
		}*/
	}
		cout << "Filtered text: " << filter << endl;
		return 0;
	
}