#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Employee {
private:
	int id;
	string name;
	float salary;
public:
public:
    Employee(int id,string name,float salary) {
		this->id;

	}
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }
    void displayDetails() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
   /* int getID()  { 
        return id; 
    }*/

	void writeToFile(ofstream& outFile) const {
		outFile << id << " " << name << " " << salary << endl;
	}
	void readFromFile(ifstream& inFile) {
		inFile >> id >> name >> salary;
	}

};
class Employee1 {
private:
	vector<Employee> employees;
	string filename;

	void saveToFile() const {
		ofstream file(filename);
		if (file.is_open()) {
			for (const auto& emp : employees) {
				emp.writeToFile(file);
			}
			file.close();
		}
	}

public:
	Employee1(const string& file) : filename(file) {}

	void addEmployee() {
		Employee emp;
		emp.inputDetails();
		employees.push_back(emp);
		saveToFile();
		cout << "Employee added successfully.\n";
	}

};
int main() {
	Emp1.addEmployee()
}