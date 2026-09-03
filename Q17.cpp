#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    int rollNo;
    char name[30];
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
    }

    void display()
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << marks << endl;
    }

    void save()
    {
        ofstream fout("student.dat", ios::binary);

        if (!fout)
        {
            cout << "File cannot be opened!" << endl;
            return;
        }

        fout.write((char*)this, sizeof(Student));

        fout.close();

        cout << "Student saved successfully." << endl;
    }

    void load()
    {
        ifstream fin("student.dat", ios::binary);

        if (!fin)
        {
            cout << "File cannot be opened!" << endl;
            return;
        }

        fin.read((char*)this, sizeof(Student));

        fin.close();

        cout << "Student loaded successfully." << endl;
    }
};

int main()
{
    Student s;

    // Save object
    s.accept();
    s.save();

    // Create another object
    Student s2;

    // Load object from file
    s2.load();

    // Display loaded object
    cout << "\nLoaded Student Details:" << endl;
    s2.display();

    return 0;
}