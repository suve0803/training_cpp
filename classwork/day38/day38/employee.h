#pragma once
#include<iostream>
using namespace std;
class employee {
	int id;
	string name;
public:
	employee(int id, string name):id(id),name(name) {}
	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}
	void setname(string name) {
		this->name = name;
	}
	string getname() {
		return name;
	}
	void display() {

	}
};
