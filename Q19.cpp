#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> numbers;

    // Store 10 numbers
    numbers.push_back(40);
    numbers.push_back(10);
    numbers.push_back(70);
    numbers.push_back(20);
    numbers.push_back(90);
    numbers.push_back(30);
    numbers.push_back(60);
    numbers.push_back(50);
    numbers.push_back(80);
    numbers.push_back(100);

    // 1. Display list in reverse order using iterator
    cout << "List in reverse order:" << endl;

    list<int>::reverse_iterator rit;

    for (rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
    {
        cout << *rit << " ";
    }

    // 2. Increment each number by 5 using iterator
    list<int>::iterator it;

    for (it = numbers.begin(); it != numbers.end(); ++it)
    {
        *it = *it + 5;
    }

    // 3. Display list using const iterator
    cout << "\n\nList after incrementing by 5:" << endl;

    list<int>::const_iterator cit;

    for (cit = numbers.begin(); cit != numbers.end(); ++cit)
    {
        cout << *cit << " ";
    }

    // 4. Sort the list
    numbers.sort();

    // 5. Display modified list using default iterator
    cout << "\n\nSorted modified list:" << endl;

    for (it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}