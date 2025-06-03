#include<iostream>

using namespace std;
constexpr int func(int a, int b)
{
	return a + b;
}
int main() {
	int sum = func(10, 20);
	cout << sum << endl;
}