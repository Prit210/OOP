//Q 12 2
#include <iostream>
using namespace std;

class Library {
public:
    static void calculateDueDate(int day, int month, int year, int dueDays) {
        day += dueDays;
        while (day > 30) {
            day -= 30;
            month++;
            if (month > 12) {
                month -= 12;
                year++;
            }
        }
        cout << "Due Date: " << day << "-" << month << "-" << year << endl;
    }
};

int main() {
    int day, month, year, dueDays;
    cout << "Enter current date (DD MM YYYY): ";
    cin >> day >> month >> year;
    cout << "Enter no. of due days: ";
    cin >> dueDays;
    Library::calculateDueDate(day, month, year, dueDays);
    return 0;
}
