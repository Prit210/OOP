//Q 2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LineStorage {
    vector<string> lines;

public:
    LineStorage() {}

    LineStorage(vector<string> inputLines) : lines(inputLines) {}

    LineStorage(const LineStorage &other) : lines(other.lines) {}

    ~LineStorage() {
        cout << "Destructor called. Object destroyed." << endl;
    }

    void addLine(const string &line) {
        lines.push_back(line);
    }

    void replaceString(const string &search, const string &replace) {
        for (auto &line : lines) {
            size_t pos = line.find(search);
            while (pos != string::npos) {
                line.replace(pos, search.length(), replace);
                pos = line.find(search, pos + replace.length());
            }
        }
        cout << "Updated array:\n";
        for (const auto &line : lines) {
            cout << line << endl;
        }
    }
};

int main() {
    LineStorage ls;

    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    cin.ignore();

    cout << "Enter the lines:\n";
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        ls.addLine(line);
    }

    string s1, s2;
    cout << "Enter the string to find: ";
    getline(cin, s1);
    cout << "Enter the string to replace it with: ";
    getline(cin, s2);

    ls.replaceString(s1, s2);

    return 0;
}
