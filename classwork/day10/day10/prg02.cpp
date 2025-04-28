#include<iostream>
using namespace std;
int count0 = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;
int count6 = 0;
int count7 = 0;
int count8 = 0;
int count9 = 0;

int getdigit(long int);


int main() {
	long long int num;
	long long int temp,r;
	cin >> num;
	temp = num;
	while (temp)
	{
		r = temp % 10;
		switch (r) {
		case 0:
			count0++;
			break;
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		case 3:
			count3++;
			break;
		case 4:
			count4++;
		case 5:
			count5++;
			break;
		case 6:
			count6++;
			break;
		case 7:
			count7++;
			break;
		case 8:
			count8++;
			break;
		case 9:
			count9++;
			break;
		default:
			cout << "Not a number";
		}
		temp /= 10;
	}
	cout << "count0 :" << count0 << endl;
	cout << "count1 :" << count1 << endl;
	cout << "count2 :" << count2 << endl;
	cout << "count3 :" << count3 << endl;
	cout << "count4 :" << count4 << endl;
	cout << "count5 :" << count5 << endl;
	cout << "count6 :" << count6 << endl;
	cout << "count7 :" << count7 << endl;
	cout << "count8 :" << count8 << endl;
	cout << "count9 :" << count9 << endl;
}