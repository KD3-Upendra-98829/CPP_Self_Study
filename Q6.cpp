#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        if(amount > 0)
        {
            balance = balance + amount;
            cout << "Amount deposited." << endl;
        }
        else
        {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid amount." << endl;
        }
        else if(amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance = balance - amount;
            cout << "Amount withdrawn." << endl;
        }
    }

    void display()
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance : " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, "Upendra", 10000);

    b1.display();

    b1.deposit(5000);

    b1.withdraw(3000);

    b1.display();

    return 0;
}