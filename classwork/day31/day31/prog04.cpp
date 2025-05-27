/*Single Inheritance*/
#include<iostream>
using namespace std;
//base class
class A {
private:
	int x;
	/*void proMethod() {
		cout << "A:protected method got called" << endl;//private members cannot be inherited
	}*/
protected:
	int y;
	void proMethod() {
		cout << "A:protected method got called" << endl;
	}

public:
	A() {
		cout << "A constructor got called" << endl;
		x = 10;
		y = 20;
	}
	void dispA() {
		cout << "Hello from A" << endl;
		cout << "x= " << x << "y= " << y << endl;
	}
	
};
//derived class
class B :public A {
private :
	int a;
protected:
	int b;
public:
	B() {
		cout << "B constructor got called" << endl;
		a = 11;
		b = 21;
	}
	void dispb() {
		cout << "Hello from B" << endl;
		cout << "a= " << a << "b= " << b << endl;
	}
	void protectB() {
		//proMethod();
		y = 10;
	}
};
int main() {
	A objA;
	B objB;

	objA.dispA();
	objB.dispb();
	objB.dispA();
	//objB.proMethod();//compile error accessing outside the class
	objB.protectB();
	
	return 0;
}