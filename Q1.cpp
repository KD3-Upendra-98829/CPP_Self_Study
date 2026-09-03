#include <iostream>
using namespace std;

void swapByValue(int x, int y)
{

    int temp = x;
    x = y;
    y = temp;
    cout << "After the swapbyvalue..  " << endl;
    cout << " value of x =  " << x << endl
         << "value of y = " << y;
}

void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "After the swapByReference ...  " << endl;
    cout << " value of x =  " << a << endl;
       cout<< "value of y = " << b;
}

int main()
{
    int x = 10;
    int y = 20;
    int a =30;
    int b =40;
    cout << "Before the swap value  " << endl;
    cout << " value of X -> " << x << endl;
    cout << " value of y -> " << y << endl;

    swapByValue(x, y);
     cout<<endl;
    cout << "Before the swap value  " << endl;
    cout << " value of X -> " << a << endl;
    cout << " value of y -> " << b << endl;
    swapByReference(a,b);
}