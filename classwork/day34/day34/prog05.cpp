#include <iostream>
#include <fstream>
using namespace std;
class Employee {
private:
    int id;
    char name[50];
    float salary;
public:
    void details() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "ID: " << id<< ", Name: " << name<< ", Salary: " << salary << "\n";
    }
    void save(string& filename) {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cerr << "Error opening file for writing."<<endl;
            return;
        }
        outFile << id << " " << name << " " << salary << endl;
        outFile.close();
        cout << "Employee details saved successfully." << endl;
    }
};
int main() {
        string filename = "employees.txt";
        Employee emp;
        emp.details();
        emp.save(filename);
        

}
