#include <iostream> using namespace std;

class Node { public: int data; Node* next;

Node(int value) : data(value), next(nullptr) {}

};

class LinkedList { private: Node* head;

public: LinkedList() : head(nullptr) {}

void addNodeBeg(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void addNodeEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() const {
    if (head == nullptr) {
        cout << "\tList is empty." << endl;
        return;
    }

    cout << "\tList is: " << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void freeList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

~LinkedList() {
    freeList();
}

};

int displayMenu() { int choice; cout << "\tPress,\n\t1. Add Node Beginning\n\t2. Add Node End\n"; cout << "\t3. Display List\n\t4. Exit\n\tChoice: "; cin >> choice; return choice; }

int main() { LinkedList list; int choice = 1;

while (choice) {
    switch (displayMenu()) {
    case 1: {
        int value;
        cout << "Enter the value of the node: ";
        cin >> value;
        list.addNodeBeg(value);
        break;
    }
    case 2: {
        int value;
        cout << "Enter the value of the node: ";
        cin >> value;
        list.addNodeEnd(value);
        break;
    }
    case 3:
        list.displayList();
        break;
    case 4:
        choice = 0;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}

cout << "Exiting program...." << endl;
return 0;

}

