/*Simple Bank ATM Menu*/
#include<iostream>
using namespace std;

class ATMAccount {
private:
	float balance;
	char accountHolder[20];
public:
	void setaccountHolder(char* a) {
		strcpy(accountHolder, a);
	}
	char* getaccountHolder() {
		return accountHolder;
	}
	void setbalance(float b) {
		balance = b;
	}
	float getbalance() {
		return balance;
	}
	void deposit(float amount) {
		if (amount > 0) {
			balance = balance + amount;
			cout << "deposited successfull" << "\t" << "Account balance: " << balance << endl;
		}
		else {
			cout << "Invalid amount" << endl;
		}
	}
	void withdraw(float amount) {
		if ((amount > 100)&&(amount<=balance)) {
			balance = balance - amount;
			cout << "Withdrawal successful" << "\t" << "Account balance: " << balance << endl;
		}
		else {
			cout << "Invalid amount" << endl;
		}
	}
	void checkBalance(float amount) {
		cout << "current Balance: " << balance << endl;
	}
	void display() {
		cout << "AccountHolder: " << accountHolder << endl;
		cout << "Balance: " << balance << endl;

	}
};


int main() {
	ATMAccount acc;
	char a[] = "suvetha";
	float b = 10000.0;
	int choice=0;
	float amount;
	acc.setaccountHolder(a);
	acc.setbalance(b);
	while (choice != 4) {
		cout << "1.deposit" << endl;
		cout << "2.withdrawal" << endl;
		cout << "3.balance" << endl;
		cout << "4.exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter amount : " << endl;
			cin >> amount;
			acc.deposit(amount);
		}
		else if (choice == 2) {
			cout << "Enter amount : " << endl;
			cin >> amount;
			acc.withdraw(amount);
		}
		else if (choice == 3) {
			acc.checkBalance(amount);
		}
		else if (choice == 4) {
			cout << "exit" << endl;
		}
		else {
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
}