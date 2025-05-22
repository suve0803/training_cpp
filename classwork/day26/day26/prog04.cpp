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
	//int Scontact;
	//char stud_mailid[20];
public:
	void setSid(int r);
	int getSid();
	void setSName(char* s);
	char* getSname();
	void setSDept(char* d);
	char* getSdept();
	void setSYear(int y);
	int getSYear();
	void setScgpa(int p);
	float getScgpa();
	void setSmarks(float m[]);
	void display();

private:
	float calcAvg();
	char getSgrade();
};

void student:: setSid(int r)
{
	Sid = r;
}
int student:: getSid() {
	return Sid;
}

void student::setSName(char* s)
{
	strcpy(Sname, s);
}
char* student:: getSname() {
	return Sname;
}
void student:: setSYear(int y) {
	Syear = y;
}
int student:: getSYear() {
	return Syear;
}
void student:: setSDept(char* d)
{
	strcpy(Sdepartment, d);
}
char* student:: getSdept() {
	return Sdepartment;
}
void student:: setScgpa(int p) {
	Scgpa = p;
}
float student:: getScgpa() {
	return Scgpa;
}
void student:: setSmarks(float m[])
{
	for (int i = 0;i < 5;i++)
		Smarks[i] = m[i];
}



//void student:: setScontact(float c) {
//	Scontact = c;
//}
//int student:: getScontact() {
//	return Scontact;
//}

void student:: display()
{

	cout << "ID: " << Sid << endl;
	cout << "name: " << Sname << endl;
	cout << "year: " << Sname << endl;
	cout << "department: " << Sdepartment << endl;
	cout << "cgpa: " << Scgpa << endl;
	cout << "Avg: " << calcAvg() << endl;
	cout << "Grade: " << getSgrade() << endl;
	//cout << "contact: " << Scontact() << endl;

}
float student::calcAvg() {
	float avg = 0.0;
	for (int i = 0;i < 4;i++) {
		cout << Smarks[i] << "\t";
		avg += Smarks[i];
	}
	return avg / 4.0;
}
char student::getSgrade() {
	float avg = calcAvg();
	if ((avg >= 80)&&(avg<=100)) {
		return 'A';
	}
	else if ((avg >= 65) && (avg <= 79)) {
		return 'B';
	}
	else if ((avg >= 45) && (avg <= 64)) {
		return 'C';
	}
	else {
		return 'F';
	}
}



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
	//cout << s1.getSmarks() << endl;

	return 0;
}



