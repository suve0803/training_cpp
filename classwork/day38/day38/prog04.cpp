#include<iostream>
#include<list>
using namespace std;
void addTask(std::list < std::string>& task, std::string& t) {
	task.push_back(t);
}
void urgentTask(std::list<std::string>& task, std::string& t) {
	task.push_front(t);
}
void RemoveTask(std::list<std::string>& task, std::string& t) {
	task.remove(t);

}
void display(std::list<std::string>& task) {
	for (auto& t : task) {
		cout << t << endl;
	}

}
int main() {
	std::list<std::string>& task;
	std::string commands, t;
	while (true) {
		cout << "Enter commands: " << endl;
		cin >> commands;
		if (commands == "addTask") {
			cout << "Enter task: " << endl;
			cin>>t;
			addTask(task, t);
		}
		else if (commands == "urgentTask") {
			cout << "Enter urgent Task: " << endl;
			cin >> t;
			urgentTask(task, t);
		}
		else if (commands == "RemoveTask") {
			cout << "Enter task to be removed: " << endl;
			cin >> t;
			RemoveTask(task, t);
		}
		else if (commands == "showDisplay") {
			display(task);
		}
		else if (commands == "Exit") {
			break;
		}
		else {
			cout << "Invalid commands " << endl;
		}
	}
}