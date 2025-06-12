#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m1;
mutex m2;
void thread1() {
	lock(m1, m2);
	lock_guard<mutex>lock1(m1,adopt_lock);
	this_thread::sleep_for(chrono::milliseconds(100));
	lock_guard<mutex>lock2(m2,adopt_lock);
	cout << "Thread 1 is executed." << endl;
}
void thread2() {
	lock(m1, m2);
	lock_guard<mutex>lock2(m2,adopt_lock);
	this_thread::sleep_for(chrono::milliseconds(100));
	lock_guard<mutex>lock1(m1,adopt_lock);
	cout << "Thread 2 is executed." << endl;
}
int main() {
	thread t1(thread1);
	thread t2(thread2);
	t1.join();
	t2.join();
	return 0;
}