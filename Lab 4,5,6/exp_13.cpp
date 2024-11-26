//Q 13
#include <iostream>
using namespace std;

class Integer {
    int value;

public:
    Integer(int v = 0) : value(v) {}

    friend Integer operator+(const Integer& obj1, const Integer& obj2) {
        return Integer(obj1.value + obj2.value);
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Integer obj1(10), obj2(20);
    Integer result = obj1 + obj2;
    result.display();

    return 0;
}
