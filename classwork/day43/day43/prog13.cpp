/* Browser History Navigation (Stack)*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
class BrowsingHistory {
private:
	stack<string>backstack;
	stack<string>forwardstack;
	string currentPage;
public:
	BrowsingHistory() {
		currentPage = "about:blank";
	}
	void visit(const string& url) {
		if (!currentPage.empty()) {
			backstack.push(currentPage);
		}
		currentPage = url;
		while (!forwardstack.empty()) {
			forwardstack.pop();
		}
		cout << "Visited: " << currentPage << endl;
	}
	void back() {
		if (backstack.empty()) {
			cout << "No back history" << endl;
			return;
		}
		backstack.push(currentPage);
		currentPage = backstack.top();
		backstack.pop();
		cout << "Back: " << currentPage << endl;
	}
	void forward() {
		if (forwardstack.empty()) {
			cout << "No forward history" << endl;
			return;
		}
		forwardstack.push(currentPage);
		currentPage = forwardstack.top();
		forwardstack.pop();
		cout << "Forward: " << currentPage << endl;

	}
	void current() {
		cout << "current page" <<currentPage<< endl;
	}
};
int main() {
	BrowsingHistory b;
	string commands;
	while (true) {
		getline(cin, commands);
		if (commands.substr(0, 6) == "visit") {
			string url = commands.substr(6);
			b.visit(url);
		}
		else if(commands=="back") {
			b.back();
		}
		else if (commands == "forward") {
			b.forward();
		}
		else if (commands == "exit") {
			break;
		}
		else {
			cout << "Invalid commands.Try again" << endl;
		}
	}
	return 0;
}