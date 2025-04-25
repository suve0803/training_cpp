#include<cstdio>
int main() {
	int a = 10;
	float b = 13.12;
	char c = 'A';
	double d = 104.424335;
	char s[20];
	printf("\n%c\n%d\n%f\n%lf\n%s\n", a, b, c, d,"suve");
	scanf("%d%f%lf%s",&a, &b, &c, &d, s);
	//fflush(stdin);
	scanf(" ");
	scanf("%c", &c);
	printf("\n%c\n%d\n%f\n%lf\n%s\n", a, b, c, d,s);
	return 0;
}