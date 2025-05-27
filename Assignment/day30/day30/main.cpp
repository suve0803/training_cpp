#include <iostream>
#include "linkedlist.h"

using namespace std;

void menu() {

    cout << "1. Add Employee\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Linkedlist employeeList;
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
            employeeList.addEmpend(id, name, salary);
            break;
        }
        
        case 0:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 0);

    return 0;
}
