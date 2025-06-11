#include<iostream>
//#include<vector>
#include<iterator>
#include<string>
#include<list>
using namespace std;
class Employee {
	int id;
	string name;
public:
	Employee():id(0),name(" "){}
	Employee(int id, string name):id(id),name(name) {}

	Employee(const Employee& others) {
		this->id = others.id;
		this->name = others.name;
	}
	void setId(int id) {
		this->id = id;
	}
	void setname(string name) {
		this->name = name;
	}
	int getid() {
		return id;
	}
	string getname() {
		return name;
	}
	void disp() {
		cout  << "ID: " << id <<"\t" << "NAME: " << name << endl;
	}
	void setvalues() {
		cin >> id >> name;
	}
	friend istream& operator >> (istream& is, Employee& e) {
		is >> e.id;
		is >> e.name;
		return is;
	}
	friend ostream& operator << (ostream& os, Employee& e) {
		os << "ID: " << e.id << "Name: " << e.name << endl;
		return os;
	}
};
 
int main() {

	istream_iterator<Employee> inIt(cin);
	istream_iterator<Employee>endIt;
	//vector<Employee>emp;
	list<Employee>emp1;
	while (inIt != endIt) {
		emp1.push_back(*inIt);
		inIt++;
	}
	for (auto e:emp1) {
		e.disp();
	}
	return 0;
}