#include <iostream>
using namespace std;

int mystrlen(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        i++;
    }

    return i;
}

void mystrcpy(char dest[], char src[])
{
    int i = 0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int main()
{
    char str1[50] = "Hello";
    char str2[50];

    cout << "Length = " << mystrlen(str1) << endl;

    mystrcpy(str2, str1);

    cout << "Copied String = " << str2 << endl;

    return 0;
}