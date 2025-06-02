#include<iostream>
using namespace std;
class Adder {
	int val;
public:
	Adder(int v) :val(v) {}
	int operator()(int x)const {
		return x + val;
	}

};
int main() {
	Adder add5(5);
	cout << add5(10);
}