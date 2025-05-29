#include<iostream>
using namespace std;
class A {
protected:
	int a;
	void dispPrt() {
		cout << "A:Method of protected" << endl;
	}
public:
	A() {
		a = 10;
	}
	void dispA() {
		cout << "A: a= " << a << endl;
	}
};
class B:private A {
public:
	void dispB() {
		a = 20;
		dispPrt();
		dispA();
	}
};
class C :public B {
public:
	void dispC() {
		dispB();
	}
};
int main() {
	/*B objB;
	objB.dispB();*/
	//objB.dispA();
	C objC;
	objC.dispC();
 }