#include<iostream>
using namespace std;
int findgcd(int a, int b);
int findlcm(int a, int b);
int findgcd(int a, int b) {
	while (b != 0) {
		int rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}
int findlcm(int a, int b) {
	return (a * b) / findgcd(a,b);

}
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int lcm= findlcm(n1, n2);
	cout << "The lcm is " << lcm;
	return 0;
}
