#include<iostream>
using namespace std;
class Data {
public:
	int a;
	void print() {
		cout << "a is " << a;
	}
};
int main() {
	Data d, * dp;
	dp = &d;
	int Data::* ptr = &Data::a;
	int Data::* ptrM = &Data::a;
	d.print();
	//->ptrM = 104;

	d.*ptr = 10;
	d.print();
	dp->*ptr = 20;
	dp->print();
}