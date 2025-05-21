#include<iostream>
using namespace std;
class student {
private:
	int Sid;
	char Sname[20];
	int Syear;
	char Sdepartment[5];
	int Scgpa;
	float Smarks[5];
	int Scontact;
	//char stud_mailid[20];
public:
	/*void setSid(int r);
	int getSid();
	void setSName(char* s);
	char* getSname();
	void setSDept(char* d);
	char* getSdept();
	void setScgpa(int p);
	float getScgpa();
	void setSmarks(float m[]);
	void display();*/



	void setSid(int r)
	{
		Sid = r;
	}
	int getSid() {
		return Sid;
	}

	void setSName(char* s)
	{
		strcpy(Sname, s);
	}
	char* getSname() {
		return Sname;
	}
	void setSYear(int y) {
		Syear = y;
	}
	int getSYear() {
		return Syear;
	}
	void setSDept(char* d)
	{
		strcpy(Sdepartment, d);
	}
	char* getSdept() {
		return Sdepartment;
	}
	void setScgpa(int p) {
		Scgpa = p;
	}
	float getScgpa() {
		return Scgpa;
	}
	void setSmarks(float m[])
	{
		for (int i = 0;i < 5;i++)
			Smarks[i] = m[i];
	}


	void setScontact(float c) {
		Scontact = c;
	}
	int getScontact() {
		return Scontact;
	}

	void display()
	{

		cout << "ID: " << Sid << endl;
		cout << "name: " << Sname << endl;
		cout << "year: " << Sname << endl;
		cout << "department: " << Sdepartment << endl;
		cout << "cgpa: " << Scgpa << endl;
		cout << "Avg: " << calcAvg() << endl;
		//cout << "contact: " << Scontact() << endl;

	}
private:
	float calcAvg() {
		float avg = 0.0;
		for (int i = 0;i < 5;i++) {
			cout << Smarks[i] << "\t";
			avg += Smarks[i];
		}
		return avg / 5.0;
	}

};

int main() {
	char n[] = "Suvetha";
	char d[] = "ECE";
	int r = 1011;
	int y = 2;
	float g = 8.14;
	float m[5] = { 90,43,66,78,86 };
	student s1;
	//s1.display();
	s1.setSid(r);
	s1.setSName(n);
	s1.setSDept(d);
	s1.setSYear(y);
	s1.setScgpa(g);
	s1.setSmarks(m);
	s1.display();
	cout << s1.getSname() << endl;
	cout << s1.getSid() << endl;
	cout << s1.getSdept() << endl;
	cout << s1.getSYear() << endl;

	return 0;
}














