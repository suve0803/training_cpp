#include<iostream>
using namespace std;

namespace Square {
	double area(double r) {
		return r * r;
	}
	double area(double r) {
		return 2 * r;
	}
	
}
namespace Employee {
	class stack {
	public:
		stack() {
			cout << "Employee" << endl;
		}
	};
}
namespace finance {
	class stack {
	public:
		stack() {
			cout << "Finance" << endl;
		}
	};
}
using namespace Square;
int main() {
	Employee::stack s;
	finance::stack s1;
	double a = ::area(10);
	cout << a << endl;
	return 0;
}