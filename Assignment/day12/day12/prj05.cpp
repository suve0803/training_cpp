#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char dest[5], src[20] = "123456789012345678";
	char dest2[5];
	strcpy(dest, src);
	printf("\nDest: %s\n", dest);
	strncpy(dest2, src, 4);
	dest2[4] = '\0';
	printf("\ndest2: %s\n", dest2);
	dest2[4] = '\0';

	char s1[30] = "Hello";
	char s2[20] = "World";
	strcat(s1, s2);
	cout << "==================" << endl;
	printf("\ns1:%s\ts2:%s\n", s1, s2);

	char s3[50] = { '\0', };
	strcat(s3, "Suvetha Manikandan");
	printf("\ns3:%s\n,s3");
	strcpy(s3, "amol");
	printf("\ns3:%s\n", s3);
	for (int i = 0;i < 20;i++)
		printf("\n%c=%d", s3[i], s3[i]);
	char str1[20], str2[20], str3[30];

	strcat(strcat(strcpy(str1, "Suvetha"), "Manikandan"), "Saranya");
	printf("\nstr1:%s\n", str1);




	return 0;
}