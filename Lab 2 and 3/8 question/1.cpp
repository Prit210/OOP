//Q 1
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

    void searchString(const string &search) {
        int count = 0;
        for (const auto &line : lines) {
            if (line == search)
                count++;
        }
        if (count > 0)
            cout << "String \"" << search << "\" found " << count << " times in the array." << endl;
        else
            cout << "String \"" << search << "\" not found in the array." << endl;
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

    string search;
    cout << "Enter the string to search: ";
    getline(cin, search);

    ls.searchString(search);

    return 0;
}
