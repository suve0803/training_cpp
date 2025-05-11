/*Sum of the string*/
#include<iostream>
//#include<cstring>
using namespace std;
int main() {
	int sum=0;
	char s[1024];
	cin.getline(s, 1024);
	for (int i = 0;i < strlen(s);i++) {
		if (s[i] >= 48 && s[i] <= 59) {
			sum+=s[i]-48;
		}
	}
	cout << sum;
}