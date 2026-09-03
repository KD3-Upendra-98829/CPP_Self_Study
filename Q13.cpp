#include <iostream>
#include <cstring>
using namespace std;

class Payment
{
public:
    virtual void makePayment(double amount) = 0;

    virtual ~Payment()
    {
    }
};

class CreditCard : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Payment of Rs. " << amount
             << " made using Credit Card." << endl;
    }
};

class UPI : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Payment of Rs. " << amount
             << " made using UPI." << endl;
    }
};

class Cash : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Payment of Rs. " << amount
             << " made using Cash." << endl;
    }
};

class PaymentFactory
{
public:
    static Payment* create(char *mode)
    {
        if(strcmp(mode, "credit") == 0)
        {
            return new CreditCard;
        }

        if(strcmp(mode, "upi") == 0)
        {
            return new UPI;
        }

        if(strcmp(mode, "cash") == 0)
        {
            return new Cash;
        }

        return NULL;
    }
};

int main()
{
    char mode[20];
    double amount;

    cout << "Enter payment mode (credit/upi/cash): ";
    cin >> mode;

    cout << "Enter amount: ";
    cin >> amount;

    Payment *p = PaymentFactory::create(mode);

    if(p != NULL)
    {
        p->makePayment(amount);
        delete p;
    }
    else
    {
        cout << "Invalid payment mode." << endl;
    }

    return 0;
}