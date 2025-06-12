#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
typedef unsigned long long ull;
int amt = 0;
mutex m;
void addMoney(int x) {
	ull start = 0, end = 190000000000;
	cout << "add amt: " << amt <<"X: "<<x << endl;
	m.lock();
	amt += x;
	/*for(ull i=start;i<=end;i++){}*/
	m.unlock();
}
void subMoney(int x) {
	cout << "sub amt: " << amt << endl;
	m.lock();
	amt -= x;
	m.unlock();
}
int main() {
	thread t1(addMoney, 150);
	thread t2(subMoney, 100);
	t2.join();
	cout << "amt: " << amt << endl;
	t1.join();
	cout << "amt: " << amt << endl;
	return 0;
}