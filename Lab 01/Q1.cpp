#include <iostream>
using namespace std;

class BankAccount {

    double balance;

    public:
        BankAccount() {
            balance = 0.0;
            cout << "** Default Constructor **" << endl;
        }

        BankAccount(double initialBalance) {
            balance = initialBalance;
            cout << "** Parameterized Constructor **" << endl;
        }

        BankAccount(const BankAccount &newAcc) {
            balance = newAcc.balance;
            cout << "** Copy Constructor **" << endl;
        }

        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
            }else {
                cout << "Balance not enough!" << endl;
            }
               
        }

        void printBalance() const {
            cout << "Balance: $" << balance << endl;
        }
};

int main() {
    cout << "\n*** Bank Account Management Demo ***\n";

    BankAccount account1;
    cout << "Account1 created with default constructor.\n";
    account1.printBalance();

    BankAccount account2(1000.0);
    cout << "Account2 initialized with $1000.\n";
    account2.printBalance();

    BankAccount account3 = account2; 
    cout << "Account3 created as a copy of Account2.\n";
    account3.withdraw(200);
    cout << "After withdrawing $200 from Account3:\n";
    cout << "Account3 balance: $";
    account3.printBalance();

    cout << "Verifying Account2 is unaffected:\n";
    cout << "Account2 balance: $";
    account2.printBalance();

    return 0;
}