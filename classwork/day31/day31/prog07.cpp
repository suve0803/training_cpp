#include<iostream>
using namespace std;
class Person {
protected:
	int ssn;
	string name;
	string gender;
	int age;
public:
	Person(int ssn, string name, string gender, int age) {
		this->ssn = ssn;
		this->name = name;
		this->gender = gender;
		this->age = age;
	}
	void dispp()const {
		cout << "Person details are: " << endl;
		cout << "=======================" << endl;
		cout << "ssn: " << ssn << endl;
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "age: " << age << endl;
		cout << "=========================" << endl;
	}
	~Person() {
		cout << "Person destructor got called" << endl;
	}
	void setssn(int s) {
		ssn = s;
	}//generate getters and setters
	void setPerson(int ssn, string name, string gender, int age) {
		this->ssn = ssn;
		this->name = name;
		this->gender = gender;
		this->age = age;
		cout << "Person constructor got called" << endl;
	}
};
class Employee :public Person {
private:
	int e_id;
	float e_sal;
	string e_desg;
public:
	Employee(int ssn, string name, string gender, int age, int e_id, float e_sal, string e_desg) : Person(ssn, name, gender, age) {
		this->e_id = e_id;
		this->e_desg = e_desg;
		this->e_sal = e_sal;
		cout << "Employee constructor got called" << endl;
	}
	void dispemp()const {
		dispp();
		cout << "Employee Details are: " << endl;
		cout << "=========================" << endl;
		cout << "Id: " << e_id << endl;
		cout << "Designation: " << e_desg << endl;
		cout << "Salary: " << e_sal << endl;
		cout << "===========================" << endl;

	}
	~Employee() {
		cout << "Employee destructor got called" << endl;
	}
	void updateName(string name) {
		this->name = name;
	}
	void updatessn(int ssn) {
		this->ssn = ssn;
	}
};
int main() {
	Employee e(12345, "Suvetha", "Female", 21, 101, 100000, "Developer");
	//e.dispp();
	e.dispemp();
	e.updateName("Vishalini");
	//e.dispp();
	e.dispemp();
	e.setPerson(6543, "saranya", "female", 30);
	e.dispemp();
	return 0;
}