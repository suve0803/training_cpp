#include<iostream>
using namespace std;
class Person {
protected:
	string name;
	char g;
	int age;
	int phno;
public:
	Person(string n, char g, int a, int ph) :name(n), g(g), age(a), phno(ph) {
		//cout << "Person\n";
	}
	void dispPerson() {
		cout << "Name: " << name << endl;
		cout << "Gender: " << g << endl;
		cout << "Age: " << age << endl;
		cout << "phno: " << phno << endl;
	}

};
class Employee :public Person {
protected:
	int e_id;
	float e_sal;
	string e_dept;
public:
	Employee(string n, char g, int a, int ph, int id, float sal, string dept)
		:Person(n, g, a, ph), e_id(id), e_sal(sal), e_dept(dept) {
		//cout << "Employee\n";
	}
	void dispEmp() {
		cout << "ID: " << e_id << endl;
		cout << "Salary: " << e_sal << endl;
		cout << "Department: " << e_dept << endl;
	}
};
class EmpFin :public Employee {
private:
	int e_pt;
	int e_pf;
	int e_vp;
	int e_days;
public:
	EmpFin(string n, char g, int a, int ph, int id, float sal, string dept, int pt, int pf, int vp, int nday)
		:Employee(n, g, a, ph, id, sal, dept), e_pt(pt), e_pf(pf), e_vp(vp), e_days(nday) {
		cout << "EmpFin\n";
	}
	void dispEmpFin() {
		dispPerson();
		dispEmp();
		cout << "P Tax: " << e_pf << endl;
		cout << "PF: " << e_pf << endl;
		cout << "VP: " << e_vp << endl;
		cout << "No Days" << e_days << endl;

		int gs = (e_sal - e_pt - e_pf ) / 30;
		gs = gs * e_days;
		cout << "Gross Salary: " << gs << endl;
	}
};

class LMS :public Employee
{
private:
	int hours;
	int days;
public:
	LMS(string n, char g, int a, int ph, int id, float sal, string dept,int hours,int days)
		:Employee(n, g, a, ph, id, sal, dept),hours(hours),days(days){}
	void displms() {
		cout << "Hours: " << hours << endl;
		cout << "Days: " << days << endl;
	}
};


int main() {
	cout << "main\n";
	EmpFin e("suve", 'F', 22, 94567898, 101, 26000, "AM", 200, 2600, 100000, 30);
	e.dispEmpFin();
}
