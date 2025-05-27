#pragma once
#include <iostream>
#include <string>
using namespace std;

// Employee Class
class Employee {
public:
    int id;
    string name;
    float salary;

    Employee(int empId, string empName, float empSalary)
        : id(empId), name(empName), salary(empSalary) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};