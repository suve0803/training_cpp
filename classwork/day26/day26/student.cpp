#include<iostream>
#include<cstring>
#include"student.h"
using namespace std;
void student::setSid(int r)
{
	Sid = r;
}
int student::getSid() {
	return Sid;
}

void student::setSName(const char* s)
{
	strcpy(Sname, s);
}
char* student::getSname() {
	return Sname;
}
void student::setSYear(int y) {
	Syear = y;
}
int student::getSYear() {
	return Syear;
}
void student::setSDept(const char* d)
{
	strcpy(Sdepartment, d);
}
char* student::getSdept() {
	return Sdepartment;
}
void student::setScgpa(float p) {
	Scgpa = p;
}
float student::getScgpa() {
	return Scgpa;
}
void student::setSmarks(float m[])
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

void student::display()
{

	cout << "ID: " << Sid << endl;
	cout << "name: " << Sname << endl;
	cout << "year: " << Syear << endl;
	cout << "department: " << Sdepartment << endl;
	cout << "cgpa: " << Scgpa << endl;
	cout << "Avg: " << calcAvg() << endl;
	//cout << "contact: " << Scontact() << endl;

}
float student::calcAvg() {
	float avg = 0.0;
	for (int i = 0;i < 4;i++) {
		cout <<"Marks: " << Smarks[i] << "\t";
		avg += Smarks[i];
	}
	return avg / 4.0;
}

