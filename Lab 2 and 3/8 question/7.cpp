//Q 7
#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    string accessionNumber, author, title, publisher;
    int year;
    double cost;

public:
    Library() : accessionNumber(""), author(""), title(""), publisher(""), year(0), cost(0) {}

    Library(string a, string au, string t, string p, int y, double c) {
            this->accessionNumber=a;
            this->author=au;
            this->title=t;
            this->publisher=p;
            this->year=y;
            this->cost=c;
        }

    Library(const Library &l)
        : accessionNumber(l.accessionNumber), author(l.author), title(l.title), publisher(l.publisher),
          year(l.year), cost(l.cost) {}

    ~Library() {}

    void display() {
        cout << "Accession Number: " << accessionNumber << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year of Publication: " << year << endl;
        cout << "Cost: " << cost << endl;
    }
};

int main() {
    Library l1("A001", "JK Rowling", "Harry Potter", "Bloomsbury", 2000, 499.99);
    l1.display();
    return 0;
}
