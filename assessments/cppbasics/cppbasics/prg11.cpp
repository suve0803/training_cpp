/*Write a Program to Remove All Characters From a String Except Alphabets*/
#include<iostream>
using namespace std;
int main() {
	char str[100];
	char result[100];
	int j = 0;
	cin.getline(str, 100);
	for (int i = 0; str[i]!='\0';i++) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') )
		{
			result[j++]=str[i];
		}
	}result[j]='\0';
		cout<<result;

}