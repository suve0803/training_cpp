#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
	int id;
	string name;
	float salary;
	Employee* next;
public:
	Employee(int i = 0 , string n = "", float s = 0 ) {
		i = id;
		n = name;
		s = salary;
	}
	void setid(int i) {
		id = i;
	}
	int getid() {
		return id;
	}
	void setname(string n) {
		name = n;
	}
	string getname() {
		return name;
	}
	void setsalary(float s) {
		salary = s;
	}
	float getsalary() {
		return salary;
	}
	void setnext(Employee* nn) {
		next = nn;
	}
	Employee* getnext() {
		return next;
	}
};