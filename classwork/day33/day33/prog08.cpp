#include<iostream>
using namespace std;
template<class T1,class T2>
class Box {
private:
	T1 data1;
	T2 data2;
public:
	Box(T1 value1,T2 value2):data1(value1),data2(value2){}
	void printData() {
		cout << "Data T1: " << data1 << endl;
		cout << "Data T2: " << data2 << endl;
	}
};
int main() {
	Box<int, float>intBox(10, 10.5);
	intBox.printData();
	Box<int, string>stringBox(10,"erfds");
	stringBox.printData();
}