#include<iostream>
#include<vector>
using namespace std;
class students {
	int id;
	string name;
public:
	students(int id,string name):id(id),name(name){}
	void display() {
		cout << "ID: " << id << endl;
		cout << "NAME: " << name << endl;
	}
};
int main() {
	students s[3] = { {101,"abc1"},{102,"abc2"},{103,"abc3"} };
	students s1 = { 104,"abc4" };
	students s2 = { 105,"abc5" };
	for (auto e : s)
		e.display();
	vector<students>emp;
	emp.push_back(s1);
	emp.push_back(s2);

	for (auto e : emp)
		e.display();
	cout << emp.capacity() << endl;
	cout << emp.size() << endl;
	emp.front().display();
	emp.back().display();
	emp.at(3).display();

	return 0;
}