#include<iostream>
bool isprime(int);//declaration
using namespace std;

int main() {
	int num;
	cout << "num: ";
	cin >> num;
	bool ret = isprime(num);//function calling
	if (ret == true)
		cout << "Given number: " << num <<" is a prime number" << endl;
	else
		cout << "Given number:" << num << " is not a prime number" << endl;
	return 0;
}

bool isprime(int num)//definition
{
	bool flag = false;
	if (num <= 1)
		return false;
	for (int i = 2;i <= num / 2;i++) {
		if (num % i == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
		return true;
	else
		return false;
}