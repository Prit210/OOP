//Q 12
#include <iostream>
#include <string>
using namespace std;

class Integer {
    int value;

public:
    Integer(int v = 0) : value(v) {}

    bool operator==(const string& str) const {
        return to_string(value) == str;
    }

    bool operator!=(const string& str) const {
        return to_string(value) != str;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    Integer obj(123);
    string str1 = "123";
    string str2 = "456";

    if (obj == str1) {
        cout << obj.getValue() << " is equal to " << str1 << endl;
    } else {
        cout << obj.getValue() << " is not equal to " << str1 << endl;
    }

    if (obj != str2) {
        cout << obj.getValue() << " is not equal to " << str2 << endl;
    } else {
        cout << obj.getValue() << " is equal to " << str2 << endl;
    }

    return 0;
}
