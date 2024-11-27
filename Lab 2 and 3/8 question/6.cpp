//Q 6
#include <iostream>
#include <string>
using namespace std;

class Marksheet {
private:
    string name, rollNumber, subjectCode, subjectName;
    int internalMarks, externalMarks;

public:
    Marksheet() : name(""), rollNumber(""), subjectCode(""), subjectName(""), internalMarks(0), externalMarks(0) {}

    Marksheet(string n, string r, string sc, string sn, int im, int em){
            this->name=n;
            this->rollNumber=r;
            this->subjectCode=sc;
            this->subjectName=sn;
            this->internalMarks=im;
            this->externalMarks=em;
        }

    Marksheet(const Marksheet &m)
        : name(m.name), rollNumber(m.rollNumber), subjectCode(m.subjectCode), subjectName(m.subjectName),
          internalMarks(m.internalMarks), externalMarks(m.externalMarks) {}

    ~Marksheet() {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subject Code: " << subjectCode << endl;
        cout << "Subject Name: " << subjectName << endl;
        cout << "Internal Marks: " << internalMarks << endl;
        cout << "External Marks: " << externalMarks << endl;
    }
};

int main() {
    Marksheet m1("Prit", "79", "CS101", "Data Structures", 40, 45);
    m1.display();
    return 0;
}
