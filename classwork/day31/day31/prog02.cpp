#include<iostream>
using namespace std;
class Test {
	int x;
	int y;
	public:
		Test(int x, int y) {
			this->x = x;
			this->y = y;
		}
		//Test& setx
		//void set
};

int main() {
	Test objT(5, 6);
	objT.display();
	Test& obj2=TobjT.x(101);
	/*objT.y(102);*/
	obj2.display();
	return 0;

}