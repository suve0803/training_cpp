
#include<iostream>
#include<string>
using namespace std;
class Employee {
protected:
	int empId;
	string name;
public:
	Employee(int empId,string name) {
		this->empId = empId;
		this->name = name;
	}
	
};
class Developer :public Employee {
protected:
	float codingHrs;
public:
	Developer(int empId, string name, float coadingHrs) :Employee(empId, name) {
		this->codingHrs = codingHrs;
	}
	
};
class Manager :public Employee {
protected:
	int teamSize;
public:
	Manager(int empId, string name, int teamSize) :Employee(empId, name) {
		teamSize = teamSize;
	}
	
	void dispEmp() {
		cout << "EmpId: " << empId << "\nName: " << name << endl;
	}
};
class TechLead :public Developer, public Manager {
private:
	int salary;
public:
	TechLead(int empId, string name, int teamSize, float codingHrs,int salary) :Developer(empId, name,codingHrs),Manager(empId,name,teamSize){
		this->salary = salary;
	}
	int calculateSalary() {
		int codinghr = salary * codingHrs;
		cout << "Salary based on coding: " << codinghr << endl;

		int codinghrteam = codinghr + (teamSize * 5000);
		cout << "Salary based on coding + team :" << codinghrteam << endl;
		return codinghrteam;
	}
	void display() {
		cout << "Tech Lead Info:" << endl;
		dispEmp();
			cout << endl;
			calculateSalary();
	}
};
int main() {
	TechLead t(501,"rajesh",5,120,500);
	t.display();
	return 0;
}
