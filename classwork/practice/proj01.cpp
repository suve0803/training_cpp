/*write a program to implement stack using stl containers*/
#include<iostream>
#include<stack>
using namespace std;

void push(stack<int>& st) {
	
	int val;
	cout << "Enter a value: " << endl;
	cin >> val;
	st.push(val);
	cout << val << "is pushed nto the stack." << endl;
}
void pop(stack<int>& st) {
	if (st.empty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << st.top() << "the value is popped." << endl;
		st.pop();
	}
}
void printtop(stack<int>& st) {
	if (st.empty()) {
		cout << "stack is empty." << endl;
	}
	else {
		cout << "Top position in stack " << st.top() << endl;
	}
}
void st_size(stack<int>& st) {
	cout << "The size of the stack " << st.size() << endl;
}
void display(stack<int>st) {
	if (st.empty()) {
		cout << "Stack is empty" << endl;
		return;
	}
	while (!st.empty()) {
		cout << st.top() << " " << endl;
		st.pop();
	}
	cout << endl;

}

int main() {
	stack<int>st;
	int choice;
	do {

		cout << "1.push" << "\n" << "2.pop" << "\n" << "3.top" << "\n" << "4.size"<<"\n"<<"5.display" << endl;
		cout << "Enter the choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			push(st);
			break;
		case 2:
			pop(st);
			break;
		case 3:
			printtop(st);
			break;
		case 4:
			st_size(st);
			break;
		case 5:
			display(st);
			break;
		case 0:
			cout << "Exit" << endl;
			break;
		default:
			cout << "invalid choice" << endl;
			break;
		}

	} while (choice != 0);
		return 0;
}