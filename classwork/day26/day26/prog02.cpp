#include<iostream>

using namespace std;
class student {
private:
	int rollno;
	char name[20];
public:
	void setName(char* s)
	{
		strcpy(name, s);
	}
	char* getname() {
		return name;
	}
	
	void setRollno(int r) {
		rollno = r;
	}
	int getRollno() {
		return rollno;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "rollno: " << rollno << endl;
	}

};
int main() {

	char n[] = "abc";
	char str2[1024] = "xyz";
	int r = 1011;
	student s1;
	//s1.display();
	s1.setRollno(r);
	s1.setName(n);
	s1.display();
	cout << s1.getname() << endl;
	cout << s1.getRollno() << endl;
	strcat(str2, s1.getname());
	cout << str2 << endl;
	return 0;
}