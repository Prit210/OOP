#include <iostream>
using namespace std;

class Complex
{
private:
    int r;
    int i;

public:
    Complex(int real, int img)
    {
        this->r = real;
        this->i = img;
    }
    inline void display();

    friend Complex Multiply(Complex &c1, Complex &c2);
};
void Complex::display()
{
    cout << r << "+"
         << i << "i" << endl;
}
Complex Multiply(Complex &c1, Complex &c2)
{
    Complex res(0, 0);
    res.r = c1.r * c2.r - c1.i * c2.i;
    res.i = c1.r * c2.i + c1.i * c2.r;
    return res;
}

int main()
{
    Complex c1(2, 3), c2(2, 3);
    Complex c3 = Multiply(c1, c2);
    c3.display();

    return 0;
}