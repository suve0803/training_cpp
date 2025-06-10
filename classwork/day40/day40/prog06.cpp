#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static int StudentID = 0;
static int ProfessorID = 0;
class Person {
    string name;
    int age;
    virtual void getdata(string name, int age) {
        this->name = name;
        this->age = age;
    }
    virtual void putdata() {
        cout << name << " " << age << " " << endl;
    }
};
class Student :public Person {
public:
    int marks[6];
    int id;
    Student() {
        StudentID++;
    }
    void getdata() {
        Person::getdata();
        for (int i = 0;i < 6;i++) {
            cin >> marks[i];
        }
        id = StudentID;
    }
    void putdata() {
        Person::putdata();
        cout << this->sum() << " " << id << endl;
    }
    void sum() {
        int sum = 0;
        for (int i = 0;i < 6;i++) {
            sum = sum + marks[i];

        }
        return sum;
    }
};
class Professor :public Person {
    int publications;
    int cur_id;
    Professor() {
        ProfessorID++;
    }
    void getdata() {
        Person::getdata();
        cin >> publications;
        this->id = ProfessorID;
    }
    void putdata() {
        cout << publications << " " << id << endl;
    }
};
int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0;i < n;i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0;i < n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
