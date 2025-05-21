#ifndef __STUDENT__
#define __STUDENT__

class student {
private:
	int Sid;
	char Sname[20];
	int Syear;
	char Sdepartment[5];
	int Scgpa;
	float Smarks[5];
	char Sgrade;
	//int Scontact;
	//char stud_mailid[20];
public:
	void setSid(int r);
	int getSid();
	void setSName(const char* s);
	char* getSname();
	void setSDept(const char* d);
	char* getSdept();
	void setSYear(int y);
	int getSYear();
	void setScgpa(float p);
	float getScgpa();
	void setSmarks(float m[]);
	void setSgrade();
	void getSgrade();
	void display();

private:
	float calcAvg();

};




#endif
