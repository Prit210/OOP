//Q12 4
#include <iostream>
#include <cstring>
using namespace std;

class Student {
    int admno;
    char name[20];
    float marksEng, marksMaths, marksSci, total;

    void compute() { total = marksEng + marksMaths + marksSci; }

public:
    void readData(int adm, const char* n, float eng, float maths, float sci) {
        admno = adm;
        strcpy(name, n);
        marksEng = eng;
        marksMaths = maths;
        marksSci = sci;
        compute();
    }

    void showData() const {
        cout << "Admission No: " << admno << "\nName: " << name
             << "\nEnglish: " << marksEng << "\nMaths: " << marksMaths
             << "\nScience: " << marksSci << "\nTotal: " << total << endl;
    }
};

int main() {
    Student s;
    s.readData(1, "John Doe", 85, 90, 88);
    s.showData();
    return 0;
}
