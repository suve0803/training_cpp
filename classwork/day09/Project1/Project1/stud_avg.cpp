#include<cstdio>
int main() {
	int sno;
		int id_01, id_02, id_03, id_04;
	float m1_01, m1_02, m1_03, m1_04, m2_01, m2_02, m2_03, m2_04, m3_01, m3_02, m3_03, m3_04, m4_01, m4_02, m4_03, m4_04;
	char name_01[20], name_02[20], name_03[20], name_04[20];
	float avg_01,avg_02,avg_03,avg_04;

	scanf("%d%f%f%f%", &id_01, &m1_01, &m2_01, &m3_01, &m4_01);
	avg_01 = (m1_01 + m2_01 + m3_01 + m4_01) / 4.0;

	sno = 1;
	for (int i = 0;i <= 30;i++) {
		printf("=");
		printf("\n");
		printf("sno|id|name");
		for (int i = 0;i <= 30;i++) 
			printf("=");
	}
	printf("\n%03d|%03d\t",sno++)





	printf("sno", sno++);
	printf("Enter the student id: ",id_01);
	scanf("%d", &id_01);
	printf("Enter the student name:", name_01);
	scanf("%c", name_01);
	printf("Enter the mark1: ",m1_01);
	scanf("%d", &m1_01);
	printf("Enter the mark2: ",m2_02);
	scanf("%d", &m2_02);
	printf("Enter the mark3: ",m3_03);
	scanf("%d", &m3_03);
	printf("Enter the mark4: ");
	scanf("%d", &m4_04);
	avg = (m1_01 + m2_02 + m3_03 + m4_04)/5;
	printf("Average: ", avg);

}