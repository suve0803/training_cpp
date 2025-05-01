#include<iostream>
using namespace std;
int main() {
	char name[20] = { 's','u','v','e' };
	for (int i = 0;i < 20;i++)
		printf("%c=%d\n", name[i], name[i]);
	for (int i = 39, count = 0;i < 60;i++)
		name[count++] = i;
	cout << "=====================" << endl;
	for(int i=0;i<20;i++)
}