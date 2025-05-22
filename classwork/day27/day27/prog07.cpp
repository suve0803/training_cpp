#include<iostream>
using namespace std;
class M;
class T {
private:
	int val;
	friend void fn1(T&,M&);
public:
	T(int v) {
		val = v;
	}
	void disp() {
		cout << val << endl;
	}
};

class M {
private:
	int j;
public:
	M(int v) {
		j = v;
	}
	void disp() {
		cout << j << endl;
	}
	friend void fn1(T&, M&);
};
void fn1( T& t,M&m) {
	t.disp();
	t.val = 1001;
	m.j = 2002;
}
int main() {

	T t1(10);
	t1.disp();
	M m1(20);
	m1.disp();

	fn1(t1, m1);
	t1.disp();
	m1.disp();

	//static int* a = new int(10);
	//delete a;
	////*a = 10;
	//T t1(10);
	//fn1(t1);
	//t1.disp();
	return 0;
}