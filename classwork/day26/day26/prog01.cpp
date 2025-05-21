//classes
#include<iostream>
using namespace std;

class student {
protected:
	int rollno;
	string name;
public:
	void display()
	{
		//cout << "Hello World, " <<str1<< endl;
		cout << "name: " << name << endl;
	}
	void setName(string s) {
		name = s;
	}
};

int main() {
	student s;
	cout << sizeof(s) << endl;

	/*s.name = "abc";
	s.rollno = 101;
	cout << s.name << "/t" << s.rollno << endl;*/

	s.display();
	s.setName("Manikandan");
	s.display();
	return 0;
}
