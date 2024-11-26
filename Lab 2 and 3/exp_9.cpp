//Q 12 9
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    double price;

public:
    void readData() {
        cout << "Enter book title: ";
        cin >> title;
        cout << "Enter book price: ";
        cin >> price;
    }

    double getPrice() const { return price; }
    string getTitle() const { return title; }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for book " << i + 1 << ":" << endl;
        books[i].readData();
    }

    Book cheapest = books[0];
    for (int i = 1; i < n; i++) {
        if (books[i].getPrice() < cheapest.getPrice())
            cheapest = books[i];
    }

    cout << "Cheapest Book: " << cheapest.getTitle() << " with price: " << cheapest.getPrice() << endl;
    return 0;
}
