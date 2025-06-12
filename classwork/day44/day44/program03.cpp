/*3. Thread-safe Counter with Mutex
Problem: Create multiple threads that increment a shared counter 1000 times each. 
Use a mutex to protect the counter from race conditions.

Objective: Demonstrate data race and how to prevent it using std::mutex.*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int counter = 0;
mutex m;
void display(int n) {
	for (int i = 0;i < n;i++) {
		m.lock();
		counter++;
		m.unlock();
	}
}
int main() {
	const int num = 5;
	const int increments = 1000;
	thread t[num];
	for (int i = 0;i <= num;i++)
	{
		t[i] = thread(display, increments);
		
	}
	for (int i = 0; i < num; i++) {
		t[i].join();
	}
	cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}