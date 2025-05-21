#include<iostream>
#include"student.h"


using namespace std;
int main() {

	student S;
	float marks[] = { 55,46,74,82 };
	S.setSName("suvetha");
	S.setSid(101);
	S.setSmarks(marks);
	S.setSDept("ECE");
	S.setSYear(2);
	S.setScgpa(8.14);
	S.display();

	return 0;
}