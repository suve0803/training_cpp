#include<iostream>
using namespace std;
class T {
private:
	static int val;
public:
	T() {
		val++;
	}
	static int getVal() {
		return val;
	}
	void disp() {
		cout << "val: " << val << endl;
	}
};
int T:: val=10;

int main() {
	/*T t1;
	t1.disp();
	T t2;
	t2.disp();
	t1.disp();*/

}