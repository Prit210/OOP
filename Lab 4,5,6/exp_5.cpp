//Q5    
#include <iostream>
#include <string>
using namespace std;

class Publication
{
public:
    string title;
    double price;
    string author;
};

class Book : public Publication
{
public:
    int pcount;


    void getData()
    {
        cout << "Enter title: " << endl;
        cin >> title;
        cout << "Enter price: " << endl;
        cin >> price;
        cout << "Enter author: " << endl;
        cin >> author;
        cout << "Enter Page count: " << endl;
        cin >> pcount;
    }

    
    void displayData() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Author: " << author << endl;
        cout << "Page Count: " << pcount << endl;
    }
};

struct Ebook : public Publication
{
    double playingTime;


    void getData()
    {
        cout << "Enter title: " << endl;
        cin >> title;
        cout << "Enter price: " << endl;
        cin >> price;
        cout << "Enter author: " << endl;
        cin >> author;
        cout << "Enter Playing Time: " << endl;
        cin >> playingTime;
    }

    void displayData()
    {

        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Author: " << author << endl;
        cout << "Ebook Playing Time: " << playingTime << " hours" << endl;
    }
};

int main()
{
    
    Book book;
    cout << "Enter details for the book:\n";
    book.getData();
    cout << "\nBook details:\n";
    book.displayData();

    Ebook ebook;
    cout << "\nEnter details for the ebook:\n";
    ebook.getData();
    cout << "\nEbook details:\n";
    ebook.displayData();
    return 0;
}