#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }

    virtual void work() = 0;
};


class Student : public Person
{
private:
    int marks;

public:
    Student(string name, int age, int marks)
        : Person(name, age)
    {
        this->marks = marks;
    }

    void study()
    {
        cout << "Student is studying" << endl;
    }

    void work()
    {
        cout << "Student is doing study work" << endl;
    }

    void display()
    {
        Person::display();
        cout << "Marks : " << marks << endl;
    }
};


class Teacher : public Person
{
private:
    double salary;

public:
    Teacher(string name, int age, double salary)
        : Person(name, age)
    {
        this->salary = salary;
    }

    void teach()
    {
        cout << "Teacher is teaching" << endl;
    }

    void work()
    {
        cout << "Teacher is doing teaching work" << endl;
    }

    void display()
    {
        Person::display();
        cout << "Salary : " << salary << endl;
    }
};


int main()
{
    Student s1("Rahul", 20, 85);
    Teacher t1("Amit", 40, 50000);

    cout << "Student Details" << endl;
    s1.display();
    s1.study();

    cout << endl;

    cout << "Teacher Details" << endl;
    t1.display();
    t1.teach();

    cout << endl;

    // Runtime polymorphism
    Person *ptr;

    ptr = &s1;
    ptr->work();

    ptr = &t1;
    ptr->work();

    return 0;
}