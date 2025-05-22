#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance)   { balance = initialBalance; }

    double getBalance() const {  // Const member function
        return balance;          // Ensures no modification to object
    }
    //const int a[] is to make array read only
    void disp(const int a[], int n)const {
        for (int i = 0;i < n;i++)
            cout << a[i] << endl;
    }
    void deposit(double amount) {
        balance += amount;
    }
};

int main() {
    BankAccount acc(1000.0);
    acc.deposit(500.0);

    // Call to const function
    cout << "Current balance: $" << acc.getBalance() << endl;

    return 0;
}