//Q 8
#include <iostream>
#include <string>
using namespace std;

class Personnel {
private:
    string name, dob, bloodGroup, contactAddress, telephone, licenseNumber;
    double height, weight;
    int insurancePolicy;

public:
    Personnel() : name(""), dob(""), bloodGroup(""), contactAddress(""), telephone(""), licenseNumber(""),
                  height(0), weight(0), insurancePolicy(0) {}

    Personnel(string n, string d, string b, string c, string t, string l, double h, double w, int i){
            this->name=n;
            this->dob=d;
            this->bloodGroup=b;
            this->contactAddress=c;
            this->telephone=t;
            this->licenseNumber=l;
            this->height=h;
            this->weight=w;
            this->insurancePolicy=i;
          }

    Personnel(const Personnel &p){
            this->name=p.name;
            this->dob=p.dob;
            this->bloodGroup=p.bloodGroup;
            this->contactAddress=p.contactAddress;
            this->telephone=p.telephone;
            this->licenseNumber=p.licenseNumber;
            this->height=p.height;
            this->weight=p.weight;
            this->insurancePolicy=p.insurancePolicy;
          }

    ~Personnel() {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "DOB: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "License Number: " << licenseNumber << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Insurance Policy Number: " << insurancePolicy << endl;
    }
};

int main() {
    Personnel p1("Prit", "02-10-2005", "B+", "Surat", "8320154993", "12345", 5.9, 70, 123456);
    p1.display();
    return 0;
}
