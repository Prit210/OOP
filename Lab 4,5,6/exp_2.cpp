//Q2
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    int numCalls;
    double bill;

    void inputData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number of calls: ";
        cin >> numCalls;
    }

    double calculate()
    {
        if (numCalls <= 100)
        {
            bill = 200;
        }
        else if (numCalls <= 150)
        {
            bill = 200 + (numCalls - 100) * 0.60;
        }
        else if (numCalls <= 200)
        {
            bill = 200 + 50 * 0.60 + (numCalls - 150) * 0.50;
        }
        else
        {
            bill = 200 + 50 * 0.60 + 50 * 0.50 + (numCalls - 200) * 0.40;
        }
        return bill;
    }

    void outputInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Bill: " << bill << endl;
    }
};

int main()
{
    Employee emp1;

    emp1.inputData();
    emp1.calculate();
    emp1.outputInfo();

    return 0;
}