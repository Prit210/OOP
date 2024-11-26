//Q 12 6
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    float marks;

public:
    void readData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    float getMarks() const { return marks; }
    string getName() const { return name; }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].readData();
    }

    Student topper = students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].getMarks() > topper.getMarks())
            topper = students[i];
    }

    cout << "Topper: " << topper.getName() << " with marks: " << topper.getMarks() << endl;
    return 0;
}
