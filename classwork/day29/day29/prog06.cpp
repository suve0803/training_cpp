<<<<<<< HEAD
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node {
	int data;
	struct node* next;
}NODE;
NODE* createNode();
NODE* addNodeBeg(NODE*, NODE*);
NODE* addNodeEnd(NODE*, NODE*);
//NODE* addNodeAfter(NODE*, NODE*);
//NODE* addNodeBefore(NODE*, NODE*);
NODE* deleteNodeBeg(NODE*);
NODE* deleteNodeEnd(NODE*);
//NODE* deleteNodeAfter(NODE*);
//NODE* deleteNodeBefore(NODE*);
void searchNode(NODE*,int);
void updateNode(NODE*,int,int);
int dispList(NODE*);
int dispMenu();
void freeNodes(NODE*);

int main() {
	NODE* head = NULL;
	int ch = 1;
	while (ch) {
		switch (dispMenu()) {
		case 1:

			head = addNodeBeg(head, createNode());
			break;
		case 2:
			head = addNodeEnd(head, createNode());
			break;
		case 3:
			head = deleteNodeBeg(head);
			break;
		case 4:
			head = deleteNodeEnd(head);
		case 5:
			int val;
			cin >> val;
			searchNode(head,val);
		case 6:
			int o_val, u_val;
			cin >> o_val >> u_val;
			updateNode(head, o_val, u_val);
			break;
		case 7:
			dispList(head);
			break;
		case 8:
			ch = 0;
			break;
		default:
			cout << "Something went wrong" << endl;

		}
	}
	freeNodes(head); //*very improtant Memory Leaks
	cout << "Exiting program...." << endl;
	return 0;
}
int dispMenu()
{
	int ch;
	cout << "Press,\n1. Add Node Begining\n2. Add Node End\n";
	cout << "3.Delete Node Beginning\n4.Delete Node End\n5.search value\n6. update value\n7. Display List\n8.Exit\nChoice: ";
	cin >> ch;
	return ch;
}

int dispList(NODE* head)
{
	cout << "List is " << endl;
	
	while (head != NULL)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
	return EXIT_SUCCESS;
}

NODE* addNodeEnd(NODE* head, NODE* nn)
{
	NODE* temp = head;
	if (head == NULL) {
		head = nn;
		return head;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = nn;
	head = temp;
	return head;
}

NODE* addNodeBeg(NODE* head, NODE* nn)
{
	if (head == NULL)
	{
		head = nn;
		return head;
	}
	nn->next = head;
	head = nn;
	return head;
}

NODE* deleteNodeBeg(NODE* head) {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return head;
	}
	NODE* temp = head;
	head = head->next;
	return head;
}
NODE* deleteNodeEnd(NODE*head) {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return head;
	}
	NODE* temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	return head;
}

void searchNode(NODE* head, int val) {
	int place = 0;
	while (head != NULL) {
		if (head->data == val) {
			cout << val << " found at position " << place << endl;
			return;
		}
		head = head->next;
		place++;
	}
	cout <<val << " not found " << endl;
}
void updateNode(NODE*head, int o_val, int u_val) {
	/*while (head == NULL) {
		cout << "list is empty" << endl;
	}*/
	while (head != NULL) {
		if (head->data = o_val) {
			head->data = u_val;
			cout << o_val << "updated to" << u_val << endl;
			return ;
		}
		head = head->next;
	}cout << o_val << "not found" << endl;

}
=======
>>>>>>> 2743ddc523f0980d44eccf26e0b21f6825d41f43

NODE* createNode()
{
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	cout << "Enter the value of node: ";
	cin >> nn->data;
	nn->next = NULL;
	return nn;
}

void freeNodes(NODE* head)
{
	NODE* temp = head;
	while (head->next != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}