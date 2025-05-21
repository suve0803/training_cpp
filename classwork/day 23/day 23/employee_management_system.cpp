#include<iostream>
//#include<string>
#define MAX 100
using namespace std;

struct emp {
	int id;
	string name;
};

void add_emp(emp employee[], int count);
void disp_emp(emp employee[], int count);

int main() {
	emp employee[MAX];
	int empcount = 0;
	int choice;
	while(1){
		cout << "1.Add Employee";
		cout << "2.Display Employee";
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			add_emp(employee, empcount);
			break;
		case 2:
			disp_emp(employee, empcount);
			break;
		case 3:
			cout << "Exit" << endl;
		default:
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
}
void add_emp(emp employee[], int count) {
	if (count >= MAX) {
		cout << "Maximum limit reached" << endl;
		return;
	}cout << "Enter employee ID: ";
	cin.ignore();
	cin >> employee[count].id;

	cout << "Enter employee name: ";
	cin>>employee[count].name;
	count++;
	//cout<<""
}
void disp_emp(emp employee[], int count) {
	if (count == 0) {
		cout << "No employee";
		return;
	}
	cout << "Employee list";
	for (int i = 0;i < count;++i) {
		cout << employee[i].id << " " << employee[i].name << endl;
	}
}
