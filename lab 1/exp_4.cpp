//Q 4
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    int numberOfCalls;
    double billAmount;

public:
    void inputData() {
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter number of calls made: ";
        cin >> numberOfCalls;
    }

    void computeBill() {
        if (numberOfCalls <= 100) {
            billAmount = 200; 
        } else if (numberOfCalls <= 150) {
            billAmount = 200 + (numberOfCalls - 100) * 0.60; 
        } else if (numberOfCalls <= 200) {
            billAmount = 200 + (50 * 0.60) + (numberOfCalls - 150) * 0.50; 
        } else {
            billAmount = 200 + (50 * 0.60) + (50 * 0.50) + (numberOfCalls - 200) * 0.40; 
        }
    }

    void outputData() const {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Number of Calls: " << numberOfCalls << endl;
        cout << "Bill Amount: Rs. " << billAmount << endl;
    }
};

int main() {
    Customer customer;
    
    customer.inputData();
    customer.computeBill();
    customer.outputData();

    return 0;
}
