#include<iostream>
using namespace std;
int main() {
	int n, i1 = 0,i2,count;
	cout << "Enter the input n:" << endl;
	cin >> n;
	count = 1;
	while (i1 < n)
	{
		i2 = 0;
		while(i2<n){
		if (count % n == 0)
			cout << count;
		else
			cout << count << "*";
		count++;
		i2++;

	}
	cout << endl;
	i1++;
}
return 0;
}