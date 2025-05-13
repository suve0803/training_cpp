#include<iostream>
using namespace std;
void swap1(int, int);
void swap2(int*, int*);
void swap3(int&, int&);




int main() {
	int a = 10, b = 20;
	cout << "In Main(before swap)\n" << a << '\t' << b << endl;
	swap1(a, b);
	cout << "In Main(after swap)\n" << a << '\t' << b << endl;
	swap3(a, b);
	cout << "In Main(after swap)\n" << a << '\t' << b << endl;

	return EXIT_SUCCESS;
}
void swap1(int a, int b) {
	int t;
	t = a;
	a = b;
	b = t;
	cout << "In swap1 functio\n" << a << "\t" << b << endl;
}
void swap2(int *a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
	cout << "In swap1 functio\n" << *a << "\t" << *b << endl;
}
void swap3(int &a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
	cout << "In swap1 functio\n" << a << "\t" << b << endl;
}


