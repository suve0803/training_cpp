/*Linked List*/
#include<iostream>
using namespace std;
struct node {
	int v;
	struct node* ptr;
};
int main() {
	struct node n1, n2, n3;
	cout << sizeof(n1) << "\t Address of n1: " << (unsigned long int) &n1<< endl;
	cout << sizeof(n2) << "\t Address of n1: " << (unsigned long int) & n1 << endl;
	cout << sizeof(n3) << "\t Address of n1: " << (unsigned long int) & n1 << endl;

	//step 2:initialize val to all nodes
	n1.v = 10;
	n1.ptr = NULL;

	n2.v = 20;
	n2.ptr = NULL;

	n3.v = 30;
	n3.ptr = NULL;
	cout << "n1 val: " << n1.v << "\tptr" << (unsigned long int)n1.ptr << endl;
	cout << "n2 val: " << n2.v << "\tptr" << (unsigned long int)n2.ptr << endl;
	cout << "n3 val: " << n3.v << "\tptr" << (unsigned long int)n3.ptr << endl;

	//step 3:make a relationship
	n1.ptr = &n2;
	n2.ptr = &n3;

	cout << "After making relationship" << endl;
	cout<<"n1 val: "<<n1.v<<"\tptr"<< (unsigned long int)n1.ptr << endl;
	cout <<"n2 val: " << n2.v << "\tptr" << (unsigned long int)n2.ptr << endl;
	cout <<"n3 val: " << n3.v << "\tptr" << (unsigned long int)n3.ptr << endl;

	//step 4:Traversing in the list
	struct node* head = &n1;//n1=>BA of the list


	//cout << n1.v << endl;//10
	//cout << head->v << endl;
	//cout << "Address od head->ptr" << (unsigned long int)head->ptr << endl;

	//head = &n2;
	//head = head->ptr;
	//cout << n2.v;//20
	//cout << head->v << endl;

	//head = &n3;
	/*head = head->ptr;
	cout << head->v << endl;
	return 0;*/

	while (head!=NULL) {
		cout << head->v <<"->";
		head = head->ptr;
	}
	cout << "NULL" << endl;

	struct node n4;
	n4.v = 40;
	n4.ptr = NULL;

	//add node btw 2 nodes
	n1.ptr = &n4;
	n4.ptr = &n2;

	head = &n1;
	while (head != NULL) {
		cout << head->v << "->";
		head = head->ptr;
	}
	cout << "NULL" << endl;

	struct node n5;
	n5.v = 50;
	n5.ptr = NULL;

	head = &n1;
	n5.ptr = &n1;

	head = &n5;
	while (head != NULL) {
		cout << head->v << "->";
		head = head->ptr;
	}
	cout << "NULL" << endl;

	struct node n6;
	n6.v = 60;
	n6.ptr = NULL;

	n4.ptr = &n6;
	n6.ptr = NULL;

	head = &n5;
	while (head != NULL) {
		cout << head->v << "->";
		head = head->ptr;
	}
	cout << "NULL" << endl;

	return 0;
}
