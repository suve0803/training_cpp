#pragma once
#include "Employee.h"

class Node {
public:
    Employee data;
    Node* next;

    Node(Employee emp) : data(emp), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Methods
    void addEmployee(int id, string name, float salary);
    void displayAll() const;
    bool deleteById(int id);
    void searchByName(const string& name) const;
    bool updateSalaryById(int id, float newSalary);
    int countEmployees() const;
};
