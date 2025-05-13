#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
void add_Stud(int id[], string std_name[], int age[], string std_dept[], float grade[], int& std_count);
void view_Stud(const int id[], const string std_name[], const int age[], const string std_dept[], const float grade[], int std_count);
void update_Stud(int id[], string std_name[], int age[], string std_dept[], float grade[], int std_count);
void edit_Stud(int id[], string std_name[], int age[], string std_dept[], float grade[], int& std_count);
void list_Stud(const int id[], const string std_name[], const int age[], const string std_dept[], const float grade[], int std_count);
void generate_Reports(const string std_dept[], int count);
int main(){
int choice;

do {
    cout << "\n--- College Admission Management System ---\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Update Student\n";
    cout << "4. Edit Student\n";
    cout << "5. List Students by Department\n";
    cout << "6. Generate Department Reports\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        add_Stud(id,std_name,age,std_dept,grade,std_count);
        break;
    case 2:
        view_Stud(id, std_name, age, std_dept, grade, std_Count);
        break;
    case 3:
        update_Stud(id, std_name, age, std_dept, grade, std_Count);
        break;
    case 4:
        edit_Stud(id, std_name, age, std_dept, grade, std_Count);
        break;
    case 5:
        list_Stud(id, std_name, age, std_dept, grade, std_Count);
        break;
    case 6:
        generate_Reports(std_dept, std_Count);
        break;
    case 7:
        cout << "Exit\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
} while (choice != 7);

return 0;
}
void add_Stud(int id[], string std_name[], int age[], string std_dept[], float grade[], int& std_count) {
    if (std_count >= MAX_STUDENTS) {
        cout << "Maximum limit reached \n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> id[std_count];
    //cin.ignore();
    cout << "Enter Name: ";
    getline(cin, std_name[std_count]);
    cout << "Enter Age: ";
    cin >> age[count];
    //cin.ignore();
    cout << "Enter Department: ";
    getline(cin, std_dept[std_count]);
    cout << "Enter Grade: ";
    cin >> grade[std_count];

    std_count++;
    cout << "Student added successfully!\n";
}

void view_Stud(const int id[], const string std_names[], const int age[], const string std_dept[], const float grade[], int count) {
    if (count == 0) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- All Students ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << id[i] << ", Name: " << std_names[i] << ", Age: " << age[i]
            << ", Department: " << std_dept[i] << ", Grade: " << grade[i] << "\n";
    }
}
void 