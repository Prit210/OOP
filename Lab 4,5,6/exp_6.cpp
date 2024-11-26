//Q 6
#include <iostream>
using namespace std;

class Number2;
class Number1;

class Number1
{
private:
    int n;

public:
    Number1()
    {
        n = 0;
    }
    Number1(int number)
    {
        n = number;
    }

    //friend function
    friend float mean(Number1 n1, Number2 n2);
};

class Number2
{
private:
    int n;

public:
    Number2()
    {
        n = 0;
    }
    Number2(int number)
    {
        n = number;
    }

    //friend function 
    friend float mean(Number1 n1, Number2 n2);
};
float mean(Number1 n1, Number2 n2)
{
    return (n1.n + n2.n) / 2;
}
int main()
{
    Number1 n1(10);
    Number2 n2(20);
    cout << mean(n1, n2) << endl;
    return 0;
}