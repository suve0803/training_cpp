#include <iostream>
using namespace std;

class BankAccount {
private:
    int accNo;
    static int accountCount;  // Static member variable

public:
    BankAccount() {
        accountCount++;       // Increment count when object is created
        accNo = accountCount;
    }

    static int getAccountCount() { // Static function
       // int i = 10;
        return accountCount;       // Accesses static member
    }
    void disp() {
        cout << "Acc no: " << accNo << endl;
    }
};

// Definition of static member outside the class
int BankAccount::accountCount = 1000;

int main() {
    BankAccount* acc=new BankAccount[5];
    for (int i = 0;i < 5;i++) {
        cout << "Customer[" << (i + 1) << "]" ;
        acc[i].disp();
    }

    cout << acc->getAccountCount() << endl;
   /* BankAccount acc2;
    BankAccount acc3;*/
    /*acc1.disp();
    acc2.disp();
    acc3.disp();*/

    // Static function called using class name
    //cout << "Total number of accounts: " << BankAccount::getAccountCount() << endl;

    return 0;
}