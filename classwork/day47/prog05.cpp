#include<iostream>
#include<memory>
using namespace std;

unique_ptr<int>fun() {
	unique_ptr<int>p(new int(10));
	return move(p);
}
int main() {
	unique_ptr<int>p(fun());
	cout << *p << endl;
}