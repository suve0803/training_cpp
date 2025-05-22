//dedault constructor
//parameterized constructor

#include<iostream>
using namespace std;
class Employee {
private:
	int e_id;
	string e_name;
public:
	Employee();
	Employee(int , string );
	void disp();
	//destructor used to clean up memory
	~Employee() {
		cout << "Destructor is called" << endl;
	}
};
//default
Employee::Employee() {
	cout << "default Construct got called" << endl;
	e_id = 101;
	e_name = "suvetha";
}
//parameterized
Employee::Employee(int id, string name) {
	cout << "parameterized Construct got called" << endl;
	e_id = id;
	e_name = name;
}
void Employee::disp() {
	//cout << "disp function got called" << endl;
	cout << e_id << "\t" << e_name << endl;
}
int main() {
	//default constructor is getting called
	Employee e;
	e.disp();
	//paramiterized constructor is getting called
	Employee e1(101, "abc");
	e1.disp();
	//default copy constructor is getting called
	Employee e2(e1);
	e2.disp();
	//default copy constructor is getting called
	Employee e3 = e;
	e3.disp();
	return 0;
}