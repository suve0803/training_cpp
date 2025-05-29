/*Multilevel Inheritance->order matters*/
#include<iostream>
using namespace std;
//base class 1
class A {
protected:
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

class B:protected A {
//protected://access mode properties got inherited from A
//	int a;
protected:
	int b;
public:
	B(int x,int y) :A(x),b(y) {
		cout << "constructor B got called" << endl;
	}
	~B() {
		cout << "destructor B got called" << endl;
	}
	void dispB() {
		cout << "a= " << a <<"b= "<< b << endl;
	}
};
class C :public B {
protected:
	int c;
public:
	C(int x, int y, int z) :B(x, y), c(z) {
		cout << "constructor C got called" << endl;
	}
	~C() {
		cout << "destructor C got called" << endl;
	}
	void dispC() {
		cout << "a= " << a << " b= " << b <<" c= " << c << endl;
	}
};
class D:public C{
	int d;
public:
	D(int x, int y, int z, int w) :C(x, y, z), d(w) {
		cout << "a= " << a << " b= " << b << " c= " << c <<"d= "<<d << endl;
}
};

int main() {
	C obj(20, 10,30);
	obj.dispC();
	//obj.dispA();

}