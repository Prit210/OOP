//Q 3
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
    string name;
    int code;
    string designation;
    int experience;
    int age;

public:
    Employee()  {
        this->code=0;
        this->age=0;
        this->experience=0;
    }

    Employee(string name, int code, string designation, int experience, int age){
        this->name=name;
        this->code=code;
        this->designation=designation;
        this->age=age;
    }

    Employee(const Employee &other)
        : name(other.name), code(other.code), designation(other.designation),
          experience(other.experience), age(other.age) {}

    ~Employee() {
        cout << "Destructor called for employee: " << name << endl;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Designation: " << designation << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Age: " << age << " years" << endl;
    }

    static void showCount() {
        static int count = 0;
        count++;
        cout << "Employee count: " << count << endl;
    }

    friend void updateExperience(Employee &emp, int newExp);
};

void updateExperience(Employee &emp, int newExp) {
    emp.experience = newExp;
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee *> employees;

    for (int i = 0; i < n; ++i) {
        string name, designation;
        int code, experience, age;

        cout << "Enter details for employee " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Code: ";
        cin >> code;
        cout << "Designation: ";
        cin >> designation;
        cout << "Experience (years): ";
        cin >> experience;
        cout << "Age: ";
        cin >> age;

        employees.push_back(new Employee(name, code, designation, experience, age));
        Employee::showCount();
    }

    cout << "\nEmployee Details:\n";
    for (const auto &emp : employees) {
        emp->display();
    }

    for (auto &emp : employees) {
        delete emp;
    }

    return 0;
}
