//Q 11
#include <iostream>
using namespace std;

class Integer {
    int value;

public:
    Integer(int v = 0) : value(v) {}

    friend istream& operator>>(istream& in, Integer& obj) {
        cout << "Enter an integer: ";
        in >> obj.value;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Integer& obj) {
        out << "Integer value: " << obj.value;
        return out;
    }
};

int main() {
    Integer obj;
    cin >> obj; 
    cout << obj;
    return 0;
}
