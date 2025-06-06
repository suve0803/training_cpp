#include<iostream>
#include<map>
using namespace std;
class Employee {
private:
	int Id;
	string name;
	string gender;
	int salary;
public:
	Employee(int Id, string name, string gender, int salary) {
		this->Id = Id;
		this->name = name;
		this->gender = gender;
		this->salary = salary;
	}
	void display() {
		cout << "ID: " << Id << "\t" << "Name: " << name << "\t" << "Gender: " << "\t" << gender << "\t" << "Salary: " << "\t" << salary << endl;
	}
};
int main() {
	map<int,Employee>
}