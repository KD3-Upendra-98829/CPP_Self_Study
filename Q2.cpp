#include <iostream>
using namespace std;

inline int factorial(int a)
{
    int res;
    for (int i = 1; i <= a; i++)
    {

        res = i * a;
    }
    cout << "Factorial of number " << a << " = " << res << endl;
}
inline int power(int base, int power)
{
    int reslt = 1;
    for (int i = 1; i <= power; i++)
    {
        reslt *= base;
    }
    cout << "Power of the number =  " << reslt;
}

int main()
{
    factorial(5);
    power(6, 3);
}