#include<iostream>
using namespace std;
class B{
public:
	void printB() {
		cout << "Print B" << endl;
	}
	virtual void disp() = 0;
};
class D {
public:
	void printD() {
		cout << "Print B" << endl;
	}
	 void disp(){
		 cout << "D" << endl;
}
};
int main() {
	D d;
	d.printD();
	//d.disp();
}