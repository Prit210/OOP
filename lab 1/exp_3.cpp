//Q 3
#include <iostream>
#include <string>
using namespace std;

struct Publication {
    string title;
    double price;
    string author;

    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter price: ";
        cin >> price;
    }

    void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

struct Book : public Publication {
    int pageCount;

    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void displayData() const {
        Publication::displayData();
        cout << "Page count: " << pageCount << endl;
    }
};

struct Ebook : public Publication {
    double playingTime;

    void getData() {
        Publication::getData();
        cout << "Enter playing time (in hours): ";
        cin >> playingTime;
    }

    void displayData() const {
        Publication::displayData();
        cout << "Playing time: " << playingTime << " hours" << endl;
    }
};

int main() {
    Book book;
    Ebook ebook;

    cout << "Enter details for Book:" << endl;
    book.getData();

    cout << "\nEnter details for Ebook:" << endl;
    ebook.getData();

    cout << "\nDetails of Book:" << endl;
    book.displayData();

    cout << "\nDetails of Ebook:" << endl;
    ebook.displayData();

    return 0;
}
