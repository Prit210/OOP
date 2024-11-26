#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StringChecker {
    vector<string> lines;

public:

    StringChecker(const vector<string>& inputLines) : lines(inputLines) {}
    
    StringChecker() {}

    StringChecker(const StringChecker& other) : lines(other.lines) {}

    ~StringChecker() {
        lines.clear();
        cout << "Destructor called: Memory cleared." << endl;
    }

    void checkString(const string& s) {
        int count = 0;
        for (const auto& line : lines) {
            if (line.find(s) != string::npos) count++;
        }
        if (count > 0) {
            cout << "String found " << count << " times in the array." << endl;
        } else {
            cout << "String not found in the array." << endl;
        }
    }
};

int main() {
    vector<string> inputLines = {"hello world", "world peace", "hello there"};
    StringChecker obj(inputLines);

    string s;
    cout << "Enter the string to check: ";
    getline(cin, s);

    obj.checkString(s);

    return 0;
}
