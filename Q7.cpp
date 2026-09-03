#include <iostream>
#include <string>
using namespace std;

namespace college
{
    class Student
    {
    private:
        int id;
        string name;

    public:
        Student(int id, string name)
        {
            this->id = id;
            this->name = name;
        }

        void setId(int id)
        {
            this->id = id;
        }

        void setName(string name)
        {
            this->name = name;
        }

        int getId()
        {
            return id;
        }

        string getName()
        {
            return name;
        }

        void display()
        {
            cout << "Student ID : " << id << endl;
            cout << "Student Name : " << name << endl;
        }
    };


    class Teacher
    {
    private:
        int id;
        string name;

    public:
        Teacher(int id, string name)
        {
            this->id = id;
            this->name = name;
        }

        void setId(int id)
        {
            this->id = id;
        }

        void setName(string name)
        {
            this->name = name;
        }

        int getId()
        {
            return id;
        }

        string getName()
        {
            return name;
        }

        void display()
        {
            cout << "Teacher ID : " << id << endl;
            cout << "Teacher Name : " << name << endl;
        }
    };
}

int main()
{
    college::Student s1(101, "Rahul");

    college::Teacher t1(201, "Amit");

    s1.display();

    cout << endl;

    t1.display();

    return 0;
}