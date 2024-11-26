//Q 12 5
#include <iostream>
using namespace std;

class Fraction {
    int numerator, denominator;

public:
    Fraction(int num = 1, int denom = 1) : numerator(num), denominator(denom) {}

    void add(Fraction f) {
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator *= f.denominator;
    }

    void subtract(const Fraction& f) {
        numerator = numerator * f.denominator - f.numerator * denominator;
        denominator *= f.denominator;
    }

    void multiply(Fraction* f) {
        numerator *= f->numerator;
        denominator *= f->denominator;
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2), f2(1, 3);
    cout << "Original Fractions: ";
    f1.display();
    f2.display();

    Fraction f3 = f1;
    f3.add(f2);
    cout << "After Addition: ";
    f3.display();

    f3 = f1;
    f3.subtract(f2);
    cout << "After Subtraction: ";
    f3.display();

    f3 = f1;
    f3.multiply(&f2);
    cout << "After Multiplication: ";
    f3.display();

    return 0;
}
