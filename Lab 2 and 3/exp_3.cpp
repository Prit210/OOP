//Q12 3
#include <iostream>
using namespace std;

class Data {
    int day, month, year;

public:
    Data() : day(12), month(3), year(1993) {}
    Data(int d, int m, int y) : day(d), month(m), year(y) {} 
    Data(const Data& other) : day(other.day), month(other.month), year(other.year) {} 

    void display() const {
        cout << "Date: " << day << "-" << month << "-" << year << endl;
    }
};

int main() {
    Data defaultDate;
    Data paramDate(15, 8, 2023);
    Data copyDate(paramDate);

    defaultDate.display();
    paramDate.display();
    copyDate.display();

    return 0;
}
