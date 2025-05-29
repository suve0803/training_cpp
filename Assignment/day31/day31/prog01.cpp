#include<iostream>
using namespace std;
class Student {
protected:
	int rollNo;
	string name;
	int age;
public:
	Student(int rollNo, string name, int age) {
		this->rollNo = rollNo;
		this->name = name;
		this->age = age;
	}
	void dispemp() {
		cout << "Student Info" << endl;
		cout << "Enter Roll No: " <<rollNo<< endl;
		cout << "Enter Name: " <<name<< endl;
		cout << "Enter Age: " <<age<< endl;
		
	}
};
class Marks:public Student {
private:
	int Mark1;
	int Mark2;
	int Mark3;
	
public:
	Marks(int rollNo, string name, int age,int Mark1, int Mark2, int Mark3):Student(rollNo,name,age) {
		this->Mark1 = Mark1;
		this->Mark2 = Mark2;
		this->Mark3 = Mark3;
	}
	void calculate() {
		int totalmarks = Mark1 + Mark2 + Mark3;
		cout << "Total Marks: " << totalmarks << endl;
		float Avg = totalmarks / 3;
		cout << "Average: " << Avg << endl;
	}
	void dispMark() {
		dispemp();
		cout << "Full Result:" << endl;
		calculate();
	}
};
int main() {
	Marks m(100, "suve", 21, 50, 50, 50);
	m.dispMark();
	//m.calculate();
}