#include <iostream>
#include <string>
#define MAX 5

using namespace std;

class Employee {
private:
    int id;
    string name;

public:
 
    void setId(int eid) { 
        id = eid; 
    }
    void setName(string ename) {
        name = ename; 
    }

    int getId() const { 
        return id; 
    }
    string getName() const { 
        return name; 
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

class StackOp {
private:
    int top;
    Employee arr[MAX]; 

public:
   
    StackOp() {
        top = -1; 
    }

    bool push(const Employee& emp) {
        if (top == MAX - 1) {
            cout << "Stack is full."<<endl;
            return false;
        }
        arr[++top] = emp; 
        cout << "Employee added successfully."<<endl;
        return true;
    }
    bool pop() {
        if (top == -1) {
            cout << "Stack is empty."<<endl;
            return false;
        }
        cout << "Removed Employee: ";
        arr[top--].display();
        return true;
    }

    void display() const {
        if (top == -1) {
            cout << "Stack is empty. No employees to display."<<endl;
            return;
        }
        cout << "==== Employee List ===="<<endl;
        for (int i = top; i >= 0; i--) {
            arr[i].display();
        }
        cout << endl;
    }
};

int main() {
    StackOp stack;
    Employee emp1, emp2, emp3;
    emp1.setId(101);
    emp1.setName("suvetha");
    stack.push(emp1);

    emp2.setId(102);
    emp2.setName("manikandan");
    stack.push(emp2);

    emp3.setId(103);
    emp3.setName("saranya");
    stack.push(emp3);

    cout << "Current Stack:" << endl;
    stack.display();

    stack.pop();
    cout << "After Removing Top Employee:" << endl;
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}