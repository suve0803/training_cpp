/*Multiple Inheritance->order matters*/
#include<iostream>
using namespace std;
//base class 1
class A {
	int a;
public:
	A(int x) :a(x) {
		cout << "constructor A got called" << endl;
	}
	~A() {
		cout << "destructor A got called" << endl;
	}
	void dispA() {
		cout << "a= " << a << endl;
	}
};
//base class 2
class B {
	int b;
public:
	B(int y) :b(y) {
		cout << "constructor B got called" << endl;
	}
	~B() {
		cout << "destructor B got called" << endl;
	}
	void dispB() {
		cout << "a= " << b << endl;
	}
};
class C :public A, public B {
	int c;
public:
	C(int x, int y, int z) :A(x), B(y), c(z) {
		cout << "Constructor C got called" << endl;
	}
	~C() {
		cout << "destructor C got called" << endl;
	}
	void dispC() {
		cout << "C= " << c << endl;
	}
};
int main() {
	C obj(20, 10, 31);
	obj.dispC();

}