//Function Template
#include<iostream>
using namespace std;
//template<class T>
//void myswap(T& a, T& b) {
//	T temp;
//	a = b;
//	b = t;
//}
template<class T1,class T2>
float add(T1 a, T2 b) {
	return a + b;
	
}
int main() {
	cout << add(10, 12.2) << endl;
	cout << add(12.2, 10) << endl;
}
