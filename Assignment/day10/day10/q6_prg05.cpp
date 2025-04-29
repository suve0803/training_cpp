#include<iostream>
using namespace std;
void convert(int hrs) {
	int mins = hrs * 60;
	int secs = hrs * 3600;

	cout << hrs << " hours =  " ;
	cout << mins << " minutes , " ;
	cout << secs << "seconds" << endl;
}

int main() {
	int hrs;
	cout << "Enter number of hours: ";
	cin >> hrs;

	if (hrs < 0) {
		cout << "Enter a positive number" << endl;
	}
	else {
		convert(hrs);
	}
	return 0;
}

