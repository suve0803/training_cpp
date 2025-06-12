/*1. Print Numbers Using Two Threads
Problem: Create two threads. One thread prints numbers from 1 to 10, and the other thread 
prints numbers from 11 to 20. Use std::thread to demonstrate concurrent execution.
Objective: Understand basic thread creation and joining.*/

#include<iostream>
#include<thread>
using namespace std;
void print(int start,int end) {
	for (int i = start;i <= end;i++) {
		cout << i << endl;
	}
}
int main() {
	thread t1(print,1,10);
	cout << endl;
	thread t2(print,11,20);
	t1.join();
	t2.join();
	return 0;
}