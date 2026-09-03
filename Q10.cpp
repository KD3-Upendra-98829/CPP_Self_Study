#include <iostream>
using namespace std;

class Matrix
{
private:
    int a[2][2];

public:
    void accept()
    {
        int i, j;

        cout << "Enter matrix elements:" << endl;

        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void display()
    {
        int i, j;

        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matrix operator+(Matrix m)
    {
        Matrix temp;

        int i, j;

        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator-(Matrix m)
    {
        Matrix temp;

        int i, j;

        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] - m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator*(Matrix m)
    {
        Matrix temp;

        int i, j, k;

        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                temp.a[i][j] = 0;

                for(k = 0; k < 2; k++)
                {
                    temp.a[i][j] =
                        temp.a[i][j] + a[i][k] * m.a[k][j];
                }
            }
        }

        return temp;
    }
};

int main()
{
    Matrix m1, m2, m3;

    cout << "Enter first matrix:" << endl;
    m1.accept();

    cout << "Enter second matrix:" << endl;
    m2.accept();

    cout << endl << "Addition:" << endl;
    m3 = m1 + m2;
    m3.display();

    cout << endl << "Subtraction:" << endl;
    m3 = m1 - m2;
    m3.display();

    cout << endl << "Multiplication:" << endl;
    m3 = m1 * m2;
    m3.display();

    return 0;
}