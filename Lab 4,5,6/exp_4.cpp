//Q4
#include <iostream>
using namespace std;
class Bank_user
{
private:
    string name;
    string account_no;
    string password;
    int balance = 0;

public:
    Bank_user()
    {
        cout << "Enter Your Account Number: " << endl;
        cin >> account_no;
        cout << "set your password: ";
        cin >> password;
        cout << "Enter The Amount You Want To Deposit\n";
        cin >> balance;
    }

    void deposit()
    {
        string pass;
        int deposit_amount;
        cout << "Enter Password\n";
        cin >> pass;
        if (pass == password)
        {
            cout << "Enter Amount You want to deposit\n";
            cin >> deposit_amount;
            balance += deposit_amount;
            cout << "Amount Deposited Succesfully.\n"
                 << "Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid Password\n";
        }
    }

    void Withdraw()
    {
        string pass;
        int Withdraw_amount;
        cout << "Enter Your Password\n";
        cin >> pass;
        if (pass == password)
        {
            cout << "Enter Amount You want to Withdraw\n";
            cin >> Withdraw_amount;
            if (balance - Withdraw_amount >= 0)
            {
                balance -= Withdraw_amount;
                cout << "Amount sent Succesfully.\n";
            }
            else
            {
                cout << "Not Enough Balance.\n";
            }
            cout << "\nBalance: " << balance << endl;
        }
        else
        {
            cout << "Invalid Password\n";
        }
    }

    void ask_task()
    {
        int task = 0;
        while (task != 3)
        {
            cout << "What Would You Like to Do?\n1. Deposit\n2. Withdraw\n3. Exit\n";
            cin >> task;
            switch (task)
            {
            case 1:
                deposit();
                break;
            case 2:
                Withdraw();
                break;
            case 3:
                break;
            default:
                cout << "Invalid Input\n";
                break;
            }
        }

        cout << "Thank You for Using Our Service.\n";
    }
};

int main()
{
    Bank_user user;
    user.deposit();
    user.Withdraw();
    return 0;
}