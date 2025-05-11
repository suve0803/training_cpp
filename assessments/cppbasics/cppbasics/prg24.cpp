/*Write a Program to Calculate the Sum of Elements in an Array*/
#include<iostream>
using namespace std;
int main() {
	int n1[] = { 4,6,1,8,9 };
	int n = sizeof(n1) / sizeof(n1[0]);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += n1[i];
	}cout << sum;

}