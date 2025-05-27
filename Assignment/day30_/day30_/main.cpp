#include <iostream>
#include "LinkedList.h"

using namespace std;

void menu() {
    
    cout << "1. Add Employee\n";
    cout << "2. Display All Employees\n";
    cout << "3. Delete Employee by ID\n";
    cout << "4. Search Employee by Name\n";
    cout << "5. Update Salary by ID\n";
    cout << "6. Count Employees\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    LinkedList employeeList;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            float salary;
            cout << "Enter ID, Name, and Salary: ";
            cin >> id >> name >> salary;
            employeeList.addEmployee(id, name, salary);
            break;
        }
        case 2:
            employeeList.displayAll();
            break;
        case 3: {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            if (!employeeList.deleteById(id)) {
                cout << "Employee with ID " << id << " not found.\n";
            }
            break;
        }
        case 4: {
            string name;
            cout << "Enter Name to search: ";
            cin >> name;
            employeeList.searchByName(name);
            break;
        }
        case 5: {
            int id;
            float salary;
            cout << "Enter ID and new Salary: ";
            cin >> id >> salary;
            if (!employeeList.updateSalaryById(id, salary)) {
                cout << "Employee with ID " << id << " not found.\n";
            }
            break;
        }
        case 6:
            cout << "Total Employees: " << employeeList.countEmployees() << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

