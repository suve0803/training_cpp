#include<iostream>
using namespace std;
class Student {
protected:
	int std_id;
	string name;
	static int nextId;
public:
	Student(int std_id, string name) :name(name) {
		std_id = nextId++;
	}
		virtual void displayDetails() = 0;
		virtual ~Student(){}
};
int Student::nextId = 101;
class UG :public Student {

};