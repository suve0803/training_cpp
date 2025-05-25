/*Queue*/
#include<iostream>
using namespace std;
#define MAX 5
using namespace std;
int front=0;
int rear=0;
int arr[MAX];
int enqueue(int);
int dequeue();
void display();

int main() {
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
	dequeue();
	dequeue();
	dequeue();
	display();
	return 0;
}

int enqueue(int v) {
	if (rear == MAX - 1) {
		cout << "Queue is full" << endl;
		return EXIT_SUCCESS;
	}
	arr[rear] = v;
	rear++;
}

int dequeue()
{
	if ((rear == front) || (front == MAX)) {
		cout << "Queue is empty" << endl;
		rear = 0;
		front = 0;
		return EXIT_SUCCESS;
	}
	cout << arr[front] << "is dequeued" << endl;
	front++;
	return EXIT_SUCCESS;
}
void display() {
	if ((rear == front) || (front == MAX)) {
		cout << "Queue is empty" << endl;
		rear = 0;
		front = 0;
		return;
	}
}