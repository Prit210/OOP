#include <iostream>
#include <string>
using namespace std;

class Payroll {
private:
    string name, code, designation, accountNumber, dateOfJoining;
    double basicPay, da, hra, cca, ppf, gpf, cpf, lic, nss, nsc;

    static int employeeCount;

public:
    Payroll() : name(""), code(""), designation(""), accountNumber(""), dateOfJoining(""),
                basicPay(0), da(0), hra(0), cca(0), ppf(0), gpf(0), cpf(0), lic(0), nss(0), nsc(0) {
        employeeCount++;
    }

    Payroll(string name, string code, string designation, string accountNumber, string dateOfJoining, double basicPay, double da, double hra, double cca,
            double ppf, double gpf, double cpf, double lic, double nss, double nsc) {
        this->name=name;
        this->code=code;
        this->designation=designation;
        this->accountNumber=accountNumber;
        this->dateOfJoining=dateOfJoining;
        this->basicPay=basicPay;
        this->da=da;
        this->hra=hra;
        this->cca=cca;;
        this->ppf=ppf;
        this->gpf=gpf;
        this->cpf=cpf;
        this->lic=lic;
        this->nss=nss;
        this->nsc=nsc;

        
        employeeCount++;
    }

    Payroll(const Payroll &p)
        : name(p.name), code(p.code), designation(p.designation), accountNumber(p.accountNumber),
          dateOfJoining(p.dateOfJoining), basicPay(p.basicPay), da(p.da), hra(p.hra), cca(p.cca),
          ppf(p.ppf), gpf(p.gpf), cpf(p.cpf), lic(p.lic), nss(p.nss), nsc(p.nsc) {
        employeeCount++;
    }

    ~Payroll() {
        employeeCount--;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Designation: " << designation << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Date of Joining: " << dateOfJoining << endl;
        cout << "Basic Pay: " << basicPay << endl;
        cout << "DA: " << da << endl;
        cout << "HRA: " << hra << endl;
        cout << "CCA: " << cca << endl;
        cout << "PPF: " << ppf << endl;
        cout << "GPF: " << gpf << endl;
        cout << "CPF: " << cpf << endl;
        cout << "LIC: " << lic << endl;
        cout << "NSS: " << nss << endl;
        cout << "NSC: " << nsc << endl;
    }

    static void displayEmployeeCount() {
        cout << "Total Employees: " << employeeCount << endl;
    }

    static Payroll* createPayroll() {
        return new Payroll();
    }

    static void deletePayroll(Payroll* p) {
        delete p;
    }
};

int Payroll::employeeCount = 0;

int main() {
    Payroll* p1 = Payroll::createPayroll();
    *p1 = Payroll("John", "E101", "Manager", "123456", "01-01-2020", 50000, 2000, 3000, 1000, 500, 400, 300, 200, 100, 150);
    p1->display();
    Payroll::displayEmployeeCount();
    Payroll::deletePayroll(p1);
    return 0;
}
