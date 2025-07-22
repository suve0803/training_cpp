#include<iostream>
using namespace std;
int main() {
	auto calculator = [](int a, int b) {
		cout<< a + b<<endl;
		cout<< a - b<<endl;
		cout<< a * b<<endl;
		cout<< a / b<<endl;
		};
	calculator(10, 20);

}