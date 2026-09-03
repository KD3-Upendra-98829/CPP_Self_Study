
#include <iostream>
#include <string>

using namespace std;

// Custom Exception Class
class InvalidMarksException
{
private:
    string message;

public:
    InvalidMarksException(string message)
    {
        this->message = message;
    }

    string getMessage()
    {
        return message;
    }
};


// Student Class
class Student
{
private:
    int rollNo;
    string name;
    double marks;

public:

    void accept()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        if(marks < 0)
        {
            throw InvalidMarksException(
                "Marks cannot be negative."
            );
        }
    }

    void display()
    {
        cout << "\nStudent Details" << endl;
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << marks << endl;
    }
};


int main()
{
    Student s;

    try
    {
        s.accept();
        s.display();
    }
    catch(InvalidMarksException &ex)
    {
        cout << "Exception: "
             << ex.getMessage()
             << endl;
    }

    return 0;
}




