//Q 12 8
#include <iostream>
using namespace std;

class BankAccount {
    int accNumber;
    double balance;

public:
    BankAccount(int acc, double bal) : accNumber(acc), balance(bal) {}

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!" << endl;
        else
            balance -= amount;
    }

    void display() const {
        cout << "Account Number: " << accNumber << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount account(12345, 1000.0);

    account.deposit(500.0);
    account.display();

    account.withdraw(300.0);
    account.display();

    account.withdraw(1500.0);
    return 0;
}
