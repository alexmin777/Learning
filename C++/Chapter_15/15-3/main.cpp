#include <iostream>
#include <cmath>
#include "exc_mean.h"

//function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >>y)
    {
        try {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }   //end of try block
        catch (mean & m)
        {
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }   //end of catch block
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        bad_hmean temp("hmean", a, b);
        temp.mesg();
        throw temp;
    }

    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
    {
        bad_gmean temp("gmean", a, b);
        temp.mesg();
        throw temp;
    }

    return std::sqrt(a * b);
}