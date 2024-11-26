//Q 12 10
#include <iostream>
#include <string>
using namespace std;

class Library {
    struct Record {
        string type, title, author;
    } records[100];

    int count = 0;

public:
    void addRecord() {
        if (count < 100) {
            cout << "Enter type (Book/Journal): ";
            cin >> records[count].type;
            cout << "Enter title: ";
            cin >> records[count].title;
            cout << "Enter author: ";
            cin >> records[count].author;
            count++;
        } else
            cout << "Library is full!" << endl;
    }

    void displayRecords() const {
        cout << "Library Records:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << records[i].type << ": " << records[i].title
                 << " by " << records[i].author << endl;
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n1. Add Record\n2. Display Records\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            library.addRecord();
            break;
        case 2:
            library.displayRecords();
            break;
        }
    } while (choice != 3);

    return 0;
}
