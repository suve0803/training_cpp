#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cout << "enter n value:" << endl;
	cin >> n;
	i = 1;
	while (i<=n) {
		//cout << n << endl;
		cout << (i*i)-1<<"," << endl;
		i++;
		
	}
	cout << (i * i) - 1;
	return 0;
}