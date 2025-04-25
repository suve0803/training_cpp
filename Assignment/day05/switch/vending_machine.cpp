#include<iostream>
using namespace std;
enum choice {
	water = 1, MilkShake, Chips, Chocolate, Soda
};
int main()
{
	int choice;
	float cost, money;
	cout << "Welcome" << endl;
	cout << "1.Water - Rs.20" << endl;
	cout << "2.Milkshake - Rs.25" << endl;
	cout << "3.Chips - Rs.20" << endl;
	cout << "4.Chocolate - Rs.10" << endl;
	cout << "5.Soda - Rs.20" << endl;
	cout << "Please select the items from(1-5):" << endl;
	cin >> choice;
	switch (choice)
	{
	case water:
		cost = 20;
		cout << "You have selected Water of price Rs. " << cost << endl;
		break;
	case MilkShake:
		cost = 25;
		cout << "You have selected MilkShake of price Rs. " << cost << endl;
		break;
	case Chips:
		cost = 20;
		cout << "You have selected chips of price Rs. " << cost << endl;
		break;
	case Chocolate:
		cost = 20;
		cout << "You have selected chocolate of price Rs. " << cost << endl;
		break;
	case Soda:
		cost = 20;
		cout << "You have selected Soda of price Rs. " << cost << endl;
		break;
	default:
		cout << "Invalid selection,Please Try again later" << endl;
		break;
	}
	cout << "Please enter the money Rs.  " << endl;
	cin >> money;
	if (money == cost) {
		cout << "Dispensing your item,Please Wait" << endl;
		if (money > cost) {
			cout << "Returning the change,please Wait" <<money-cost<< endl;
		}
		cout << "Thank You for your Purchase." << endl;

	}
	else {
		cout << "Insufficient money,Returning your money." << money << endl;
		cout << "Please Try again Later" << endl;
	}
	return 0;
}