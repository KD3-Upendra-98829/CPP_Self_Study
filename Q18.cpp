#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *ptr;
    int size;

public:

    // Default constructor
    Array()
    {
        ptr = NULL;
        size = 0;
    }

    // Parameterized constructor
    Array(int size)
    {
        this->size = size;
        ptr = new T[size];
    }

    // Copy constructor - Deep Copy
    Array(const Array<T> &obj)
    {
        this->size = obj.size;

        if (size > 0)
        {
            ptr = new T[size];

            for (int i = 0; i < size; i++)
            {
                ptr[i] = obj.ptr[i];
            }
        }
        else
        {
            ptr = NULL;
        }
    }

    // Assignment operator - Deep Copy
    Array<T>& operator=(const Array<T> &obj)
    {
        if (this != &obj)
        {
            delete [] ptr;

            this->size = obj.size;

            if (size > 0)
            {
                ptr = new T[size];

                for (int i = 0; i < size; i++)
                {
                    ptr[i] = obj.ptr[i];
                }
            }
            else
            {
                ptr = NULL;
            }
        }

        return *this;
    }

    // [] operator
    T& operator[](int index)
    {
        return ptr[index];
    }

    // Destructor
    ~Array()
    {
        delete [] ptr;
        ptr = NULL;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    // Array of int
    Array<int> a(5);

    for (int i = 0; i < a.getSize(); i++)
    {
        a[i] = (i + 1) * 10;
    }

    cout << "Integer Array:" << endl;

    for (int i = 0; i < a.getSize(); i++)
    {
        cout << a[i] << " ";
    }

    // Copy constructor
    Array<int> b(a);

    cout << "\n\nCopied Array:" << endl;

    for (int i = 0; i < b.getSize(); i++)
    {
        cout << b[i] << " ";
    }

    // Assignment operator
    Array<int> c(5);
    c = a;

    cout << "\n\nAssigned Array:" << endl;

    for (int i = 0; i < c.getSize(); i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}