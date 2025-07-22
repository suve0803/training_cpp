#include<iostream>
using namespace std;
class smartptr {
	int* ptr;
public:
	explicit smartptr(int* p = NULL) {
		ptr = p;
	}
		int& operator*() { return*ptr; }
	
};
int main() {
	smartptr ptr(new int());
	*ptr = 20;
	cout << *ptr;
	while (true);
}
