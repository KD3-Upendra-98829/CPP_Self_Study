#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNo;
    double balance;

public:
    BankAccount(int accountNo, double balance)
    {
        this->accountNo = accountNo;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        if (amount < 0)
        {
            throw amount;       // throw double
        }

        balance = balance + amount;

        cout << "Deposit successful." << endl;
    }

    void withdraw(double amount)
    {
        if (amount < 0)
        {
            throw amount;       // throw double
        }

        if (amount > balance)
        {
            throw string("Insufficient balance");
        }

        balance = balance - amount;

        cout << "Withdrawal successful." << endl;
    }

    void display()
    {
        cout << "Account No : " << accountNo << endl;
        cout << "Balance    : " << balance << endl;
    }
};

int main()
{
    BankAccount b(101, 5000);

    try
    {
        b.deposit(-500);
    }
    catch (double amount)
    {
        cout << "Exception: Negative amount = "
             << amount << endl;
    }
    catch (string msg)
    {
        cout << "Exception: " << msg << endl;
    }

    try
    {
        b.withdraw(6000);
    }
    catch (double amount)
    {
        cout << "Exception: Negative amount = "
             << amount << endl;
    }
    catch (string msg)
    {
        cout << "Exception: " << msg << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    b.display();

    return 0;
}