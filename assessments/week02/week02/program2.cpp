#include<iostream>
using namespace std;
int main() {
	long long int n;
	cout << "Enter a integer: ";
	cin >> n;
	long long int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0;
	long long int n1 = n;
	while (n1 > 0) {
		int num = n1 % 10;
		switch (num) {
		case 0:
			i0++;
			break;
		case 1:
			i1++;
			break;
		case 2:
			i2++;
			break;
		case 3:
			i3++;
		case 4:
			i4++;
			break;
		case 5:
			i5++;
		break;case 6:
			i6++;
		break;case 7:
			i7++;
		break;case 8:
			i8++;
		break;case 9:
			i9++;
			break;
		}
		n1 /= 10;
	}
	cout << "Digit frequency:" << endl;
	cout << "0" << ":" << i0 << endl;
	cout << "1" << ":" << i1 << endl;
	cout << "2" << ":" << i2 << endl;
	cout << "3" << ":" << i3 << endl;
	cout << "4" << ":" << i4 << endl;
	cout << "5" << ":" << i5 << endl;
	cout << "6" << ":" << i6 << endl;
	cout << "7" << ":" << i7 << endl;
	cout << "8" << ":" << i8 << endl;
	cout << "9" << ":" << i9 << endl;
	return 0;
}