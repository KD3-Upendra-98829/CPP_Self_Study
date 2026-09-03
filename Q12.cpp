#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    string title;
    double price;

public:
    virtual void accept() = 0;
    virtual void display() = 0;

    virtual ~Product()
    {
    }
};


class Book : public Product
{
private:
    int pages;

public:
    void accept()
    {
        cout << "Enter Book Title : ";
        cin >> title;

        cout << "Enter Book Price : ";
        cin >> price;

        cout << "Enter Pages : ";
        cin >> pages;
    }

    void display()
    {
        cout << "Book Pages : " << pages << endl;
    }
};


class Tape : public Product
{
private:
    double playtime;

public:
    void accept()
    {
        cout << "Enter Tape Title : ";
        cin >> title;

        cout << "Enter Tape Price : ";
        cin >> price;

        cout << "Enter Playtime : ";
        cin >> playtime;
    }

    void display()
    {
        cout << "Tape Playtime : " << playtime << endl;
    }
};


int main()
{
    Product **arr = new Product*[5];

    int choice;
    int i;

    for(i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "1. Book" << endl;
        cout << "2. Tape" << endl;
        cout << "Enter choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            arr[i] = new Book;
            arr[i]->accept();
            break;

        case 2:
            arr[i] = new Tape;
            arr[i]->accept();
            break;

        default:
            cout << "Invalid choice" << endl;
            i--;
            break;
        }
    }

    cout << endl;
    cout << "Product Details" << endl;

    for(i = 0; i < 5; i++)
    {
        arr[i]->display();
    }

    for(i = 0; i < 5; i++)
    {
        delete arr[i];
    }

    delete [] arr;

    return 0;
}