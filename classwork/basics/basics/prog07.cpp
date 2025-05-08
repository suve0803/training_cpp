#include<iostream>
//#define MAX 100
using namespace std;
int main() {
	/*char str[MAX];
	memset(str, 0, sizeof(str));
	cout << "Enter a string: " << endl;
	cin >> str;*/
	char str[] = "Hello World";
	int count = 0;
	while (str[count++] != '\0');
	cout << "String Length: " << count-1 << endl;
	return 0;
}