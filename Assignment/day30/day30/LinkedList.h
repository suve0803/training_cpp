#pragma once
#include"employee.h"
#include<iostream>

class Node {
public:
	Employee data;
	Node* next;
	Node(Employee emp) {
		data = emp;
		next = nullptr;
	}
};
class Linkedlist
{
private:

	Node* head;
public:
	Linkedlist() {
		head = nullptr;
	}
	void addEmpend(int id,string name,float salary);
	void displayall();
	void deleteEmpId(int id);
	void searchEmpName(string name);
	void updateSalaryId(float salary);
	int countEmp();
};