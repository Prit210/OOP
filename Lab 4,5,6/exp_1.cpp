//q1

#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int earning;
    int bonus;

    int compute_bonus()
    {
        if (earning >= 2000)
            return 0.1 * earning;
        else
            return 0;
    }

public:
    void input_data()
    {
        cout << "Enter Name:" << endl;
        cin >> name;
        cout << "\nEnter Earning: " << endl;
        cin >> earning;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Bonus: " << compute_bonus() << endl;
    }
};

int main()
{

    Employee emp;
    emp.input_data();
    emp.display();
    return 0;
}