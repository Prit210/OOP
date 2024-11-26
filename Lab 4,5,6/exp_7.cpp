//Q 7
#include <iostream>
#include <math.h>
using namespace std;

class Cuboid
{
private:
    int length;
    int breadth;
    int height;

public:
    friend class Convert_to_cube;
    void get_values()
    {
        cout << "Enter Length:" << endl;
        cin >> length;
        cout << "Enter Breadth:" << endl;
        cin >> breadth;
        cout << "Enter Height:" << endl;
        cin >> height;
    }

    int calculate_area()
    {
        return 2 * (length * breadth + length * height + breadth * height);
    }
};

class Convert_to_cube
{
public:
    int calculate_side(int l, int b, int h)
    {
        return cbrt(l * b * h);
    }

    Cuboid convert_to_cube(Cuboid &c)
    {
        int side = calculate_side(c.length, c.breadth, c.height);
        c.length = side;
        c.breadth = side;
        c.height = side;
        return c;
    }
};

int main()
{
    Cuboid c1;
    c1.get_values();
    cout << "Area: " << c1.calculate_area() << endl;
    Convert_to_cube c2;
    c1 = c2.convert_to_cube(c1);
    cout << c1.calculate_area() << endl;
    return 0;
}