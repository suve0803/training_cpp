#include <iostream>
#include<thread>
using namespace std;
void greet() {
	cout << "Hello World" << endl;
}
void disp(int x) {
	cout << "X: " << x << endl;
}
void modify(int &x) {
	x *= 2;
	
}
int main() {
	int val = 10;
	thread t1(greet);
	t1.join();
	cout << "End of the program" << endl;
	//t.join();//joinable or not
	thread t2(disp, 101);//call by valye
	t2.join();
	thread t3(modify, ref(val));//call by referrence
	cout << "val: " << val << endl;
	t3.join();
	cout << "val: " << val << endl;
	return 0;
}