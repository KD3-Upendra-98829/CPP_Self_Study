
#include <iostream>
using namespace std;


// Resource class
class Student
{
private:
    int rollNo;

public:
    Student()
    {
        cout << "Student Constructor" << endl;
        rollNo = 101;
    }

    void display()
    {
        cout << "Roll No : " << rollNo << endl;
    }

    ~Student()
    {
        cout << "Student Destructor" << endl;
    }
};


// User-defined Smart Pointer
template <class T>
class SmartPointer
{
private:
    T *ptr;

public:

    // Constructor
    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
    }

    // Overload *
    T& operator*()
    {
        return *ptr;
    }

    // Overload ->
    T* operator->()
    {
        return ptr;
    }

    // Destructor
    ~SmartPointer()
    {
        cout << "SmartPointer Destructor" << endl;

        delete ptr;
        ptr = NULL;
    }
};


// Function where exception occurs
void fun()
{
    SmartPointer<Student> p(new Student());

    p->display();

    cout << "Exception is going to occur..." << endl;

    throw 10;

    // No delete required
}


int main()
{
    try
    {
        fun();
    }
    catch(int ex)
    {
        cout << "Exception caught: " << ex << endl;
    }

    return 0;
}
