#include<cstdio>
int main() {
	int sno, id, m1, m2, m3, m4;
	char name[20];
	float avg;
	printf("Enter the student id: ",id);
	scanf("%d", &id);
	printf("Enter the student name:", name);
	scanf("%c", name);
	printf("Enter the mark1: ",m1);
	scanf("%d", &m1);
	printf("Enter the mark2: ",m2);
	scanf("%d", &m2);
	printf("Enter the mark3: ",m3);
	scanf("%d", &m3);
	printf("Enter the mark4: ");
	scanf("%d", &m4);
	avg = (m1 + m2 + m3 + m4)/5;
	printf("Average: ", avg);

}