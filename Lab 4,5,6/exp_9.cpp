//Q 9
#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    int emp_id;
    string emp_name;
    int age;

public:
    void get_data()
    {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Employee Name: ";
        cin >> emp_name;
        cout << "Enter Employee Age: ";
        cin >> age;
    }
    void show_Details()
    {
        cout << "ID:" << emp_id << endl
             << "Name:" << emp_name << endl
             << "Age:" << age;
    }
    friend bool Search(int id, Employee e)
    {
        if (e.emp_id == id)
            return true;
        return false;
    }
};

int main()
{
    Employee e[2];
    int id;
    for (int i = 0; i < 2; i++)
    {
        e[i].get_data();
    }
    cout << "Enter ID of Employee to be searched: " << endl;
    cin >> id;
    bool isFound=false;
    for (int i = 0; i < 2; i++)
    {
        if (Search(id, e[i]))
        {
            e[i].show_Details();
            isFound=true;
            break;
        }
    }
    if(!isFound)
        cout<<"ID not Found"<<endl;
    return 0;
}