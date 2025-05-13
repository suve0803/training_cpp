#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
void add_Stud(int id[], string std_name[], int age[], string std_dept[], float tenth_mark[], float twelth_mark[], float cut_off[], int& std_count);
void view_Stud(const int id[], const string std_name[], const int age[], const string std_dept[], float tenth_mark[], float twelth_mark[], const float cut_off[], int std_count);
void update_Stud(int id[], string std_name[], int age[], string std_dept[], float tenth_mark[], float twelth_mark[], float cut_off[], int std_count);
void edit_Stud(int id[], string std_name[], int age[], string std_dept[], float tenth_mark[], float twelth_mark[], float cut_off[], int& count);
void list_Stud(const int id[], const string std_name[], const int age[], const string std_dept[], float tenth_mark[], float twelth_mark[], const float cut_off[], int std_count);
void generate_Reports(const string std_dept[], int std_count);

int main() {
    
    int id[MAX_STUDENTS];
    string std_name[MAX_STUDENTS];
    int age[MAX_STUDENTS];
    string std_dept[MAX_STUDENTS];
    float tenth_mark[MAX_STUDENTS];
    float twelth_mark[MAX_STUDENTS];
    float cut_off[MAX_STUDENTS];
    int std_count = 0;  

    int choice;

    do {
        cout << "STUDENT ADMISSDION SYSTEM" << endl;;
        cout << "================================" << endl;
        cout << "1. Add Student"<<endl;
        cout << "2. View All Students"<<endl;
        cout << "3. Update Student"<<endl;
        cout << "4. Edit Student\n";
        cout << "5. List Students by Department"<<endl;
        cout << "6. Generate Department Reports\n";
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            add_Stud(id, std_name, age, std_dept,tenth_mark,twelth_mark, cut_off, std_count);
            break;
        case 2:
            view_Stud(id, std_name, age, std_dept, tenth_mark, twelth_mark, cut_off,std_count);
            break;
        case 3:
            update_Stud(id, std_name, age, std_dept, tenth_mark, twelth_mark, cut_off, std_count);
            break;
        case 4:
            edit_Stud(id, std_name, age, std_dept, tenth_mark, twelth_mark, cut_off, std_count);
            break;
        case 5:
            list_Stud(id, std_name, age, std_dept, tenth_mark, twelth_mark, cut_off, std_count);
            break;
       case 6:
            generate_Reports(std_dept, std_count);
            break;
        case 7:
            cout << "Exiting the program.!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}


void add_Stud(int id[], string std_name[], int age[], string std_dept[], float tenth_mark[], float twelth_mark[], float cut_off[], int& std_count) {
    if (std_count >= MAX_STUDENTS) {
        cout << "Maximum limit reached \n";
        return;
    }
    
    cout << "Enter Student ID: ";
    cin >> id[std_count];
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, std_name[std_count]);
    cout << "Enter Age: ";
    cin >> age[std_count];
    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, std_dept[std_count]);
    cout << "Enter Tenth mark: ";
    cin >> tenth_mark[std_count];
    cout << "Enter Twelth mark: ";
    cin >> twelth_mark[std_count];
    cout << "Enter Cut Off: ";
    cin >> cut_off[std_count];
   // id++;
    std_count++;
    
    cout << "Student added successfully!"<<endl;
    cout << "=============================" << endl;
}

void view_Stud(const int id[], const string std_names[], const int age[], const string std_dept[], float tenth_mark[], float twelth_mark[], const float cut_off[], int count) {
    if (count == 0) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n All Students \n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << id[i] << ", Name: " << std_names[i] << ", Age: " << age[i]
            << ", Department: " << std_dept[i] <<", Tenth Mark: "<<tenth_mark[i] << ", Twelth Mark: " << twelth_mark[i] << ", Cut Off: " << cut_off[i] << "\n";
    }
}
void update_Stud(int id[], string std_name[], int age[], string std_dept[], float tenth_mark[], float twelth_mark[], float cut_off[], int std_count) {
    int ids;
    cout << "Enter Student ID to update: ";
    cin >> ids;
    for (int i = 0; i < std_count; i++) {
        if (id[i] == ids) {
            cout << "Enter new details for the student:\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, std_name[i]);
            cout << "Age: ";
            cin >> age[i];
            cin.ignore();
            cout << "Department: ";
            getline(cin, std_dept[i]);
            cout << "Tenth Mark: ";
            cin >> tenth_mark[i];
            cout << "Twelth Mark: ";
            cin >> twelth_mark[i];
            cout << "Cut Off: ";
            cin >> cut_off[i];

            cout << "Student details updated successfully!\n";
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}
void edit_Stud(int id[], string std_name[], int age[], string std_dept[], float tenth_mark[], float twelth_mark[], float cut_off[], int& std_count) {
    int ids;
    cout << "Enter Student ID to delete: ";
    cin >> ids;

    for (int i = 0; i < std_count; i++) {
        if (id[i] == ids) {
            for (int j = i; j < std_count - 1; j++) {
                id[j] = id[j + 1];
                std_name[j] = std_name[j + 1];
                age[j] = age[j + 1];
                std_dept[j] = std_dept[j + 1];
                cut_off[j] = cut_off[j + 1];
            }
            std_count--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}
void list_Stud(const int id[], const string std_name[], const int age[], const string std_dept[], float tenth_mark[], float twelth_mark[], const float cut_off[], int std_count) {
    string department;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, department);

    cout << " Students in Department: " << department ;
    bool found = false;
    for (int i = 0; i < std_count; i++) {
        if (std_dept[i] == department) {
            cout << "ID: " << id[i] << ", Name: " << std_name[i] << ", Age: " << age[i]<<", Tenth Mark: " << tenth_mark[i] << ", Twelth Mark: " << twelth_mark[i] <<", Cut Off: " << cut_off[i] << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No students found in department: " << department << ".\n";
    }
}

void generate_Reports(const string std_dept[], int std_count) {
    if (std_count == 0) {
        cout << "No students to generate reports.\n";
        return;
    }

    cout << "Department Reports";
    for (int i = 0; i < std_count; i++) {
        int deptCount = 1;
        if (i == 0 || std_dept[i] != std_dept[i - 1]) {
            for (int j = i + 1; j < std_count; j++) {
                if (std_dept[i] == std_dept[j]) {
                    deptCount++;
                }
            }
            cout << "Department: " << std_dept[i] << ", Total Students: " << deptCount << "\n";
        }
    }
}