/*Queue*/
#include<iostream>
using namespace std;
#define MAX 5
using namespace std;

class QueueOp {
private:
	int front;
	int rear;
	int arr[MAX];
public:
	QueueOp();
	bool enqueue(int);
	bool dequeue();
	void display() const;

};
QueueOp::QueueOp() {
	rear = 0;
	front = 0;
}

bool QueueOp::enqueue(int v) {
	if (rear == MAX - 1) {
		cout << "Queue is full" << endl;
		return EXIT_SUCCESS;
	}
	arr[rear] = v;
	rear++;
}

bool QueueOp::dequeue() {
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
 
void QueueOp::display() const {
	if ((rear == front) || (front == MAX)) {
		cout << "Queue is empty" << endl;
		return;
	}
}

int main() {
	QueueOp q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();
	return 0;
}
