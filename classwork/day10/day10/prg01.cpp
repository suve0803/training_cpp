#include<iostream>
using namespace std;
int main() {
	int charge, mobilestatus;
	cout << "Mobile Status(0/1): ";
	cin >> mobilestatus;
	
	if (mobilestatus==1){
		cout << "Charge Status(0-100): ";
		cin >> charge;
	if (charge <= 10) {
		cout << "Plug in the charger" << endl;
	}

	cout << "Application is running" << endl;
	cout << "Calling..." << endl;
	cout << "Access browser" << endl;
	cout << "Accessing camera" << endl;
	}
	else {
		cout << "switch on the Mobile" << endl;
		cout << "Mobile Status(0/1): ";
		cin >> mobilestatus;
		if(mobilestatus == 1){
		cout << "Charge Status(0-100): ";
		cin >> charge;
		if (charge <= 10) {
			cout << "Plug in the charger" << endl;
		}

		cout << "Application is running" << endl;
		cout << "Calling..." << endl;
		cout << "Access browser" << endl;
		cout << "Accessing camera" << endl;
		}
		else {
			cout << "mobile is not in a good condition";
		}
	}
}