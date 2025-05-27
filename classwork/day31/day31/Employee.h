#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee {
	int e_id;
	string e_name;
	string e_address;
	int e_phn;
public:

	void set_e_id(int);
	void set_e_name(string);
	void set_e_address(string);
	void set_e_phn(int);

	int get_e_id();
	string get_e_name();
	string set_e_address();
	int set_e_phn();

};
