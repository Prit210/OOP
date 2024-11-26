//Q 12 11
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class ClassPeriod {
    string subjects[5] = {"Math", "English", "Science", "History", "Computer Science"};
    string teachers[5] = {"A", "B", "C", "D", "E"};

public:
    void displayRandomClass() {
        srand(time(0)); 
        int subjectIndex = rand() % 5;
        int teacherIndex = rand() % 5;

        cout << "Subject: " << subjects[subjectIndex] << "\nTeacher: " << teachers[teacherIndex] << endl;
    }
};

int main() {
    ClassPeriod classPeriod;
    classPeriod.displayRandomClass();
    return 0;
}
