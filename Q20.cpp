#include <iostream>
#include <memory>
using namespace std;

class Student
{
private:
    int rollNo;

public:
    Student(int rollNo)
    {
        this->rollNo = rollNo;
        cout << "Student " << rollNo << " created" << endl;
    }

    ~Student()
    {
        cout << "Student " << rollNo << " destroyed" << endl;
    }

    void display()
    {
        cout << "Roll No: " << rollNo << endl;
    }
};

int main()
{
    // 1. UNIQUE_PTR
    cout << "\n--- unique_ptr ---" << endl;

    unique_ptr<Student> p1(new Student(101));

    p1->display();

    // Ownership transfer
    unique_ptr<Student> p2 = move(p1);

    if (p1.get() == NULL)
        cout << "p1 no longer owns the object" << endl;

    p2->display();


    // 2. SHARED_PTR
    cout << "\n--- shared_ptr ---" << endl;

    shared_ptr<Student> s1(new Student(102));

    cout << "Reference count: " << s1.use_count() << endl;

    {
        shared_ptr<Student> s2 = s1;

        cout << "Reference count after sharing: "
             << s1.use_count() << endl;

        s2->display();
    }

    cout << "Reference count after s2 destroyed: "
         << s1.use_count() << endl;


    // 3. WEAK_PTR
    cout << "\n--- weak_ptr ---" << endl;

    weak_ptr<Student> w1 = s1;

    cout << "shared_ptr count: " << s1.use_count() << endl;

    if (!w1.expired())
    {
        shared_ptr<Student> temp = w1.lock();

        if (temp)
        {
            cout << "weak_ptr accessed Student:" << endl;
            temp->display();
        }
    }

    return 0;
}