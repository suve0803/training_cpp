#include<iostream>
using namespace std;
void f() {
	cout << "Hello";
}

int main() {
	/*auto greet = []() {cout << "Hello world";};
	greet();*/
	//f();
	auto greet = [](const string name) {cout << "Hello! " << name << endl; return "Greeted";};
	cout<<greet("suvetha") << endl;
	return 0;
}