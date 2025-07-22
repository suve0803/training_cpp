#include<iostream>

using namespace std;

class Rect
{
	int length;
	int breadth;
public:
	Rect(int l, int b)
	{
		length = l;
		breadth = b;
	}
	int area()
	{
		return length * breadth;
	}

};

int main()
{
	unique_ptr<int>p(new int(10));
	cout << *p << endl;
	shared_ptr<Rect>p2
}