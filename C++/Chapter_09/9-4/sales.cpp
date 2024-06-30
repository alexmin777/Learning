#include "sales.h"
#include <iostream>

namespace SALES
{
    using std::cin;
    using std::cout;
    using std::endl;

    void setSales(Sales & s, const double ar[], int n)
    {
        if (n > QUARTERS || n < 0)
        {
            cout << "ERROR:too many sales" << endl;
        }

        double total = ar[0], maxv = ar[0], minv = ar[0];
        s.sales[0] = ar[0];
        for (int i = 1; i < n; i++)
        {
            s.sales[i] = ar[i];
            total += ar[i];
            maxv = maxv > ar[i] ? maxv : ar[i];
            minv = minv < ar[i] ? minv : ar[i];
        }
        s.max = maxv;
        s.min = minv;
        s.average = total / n;
    }

    void setSales(Sales & s)
    {
        int i;
        double total = 0, maxv = 0, minv = 0;

        cout << "Enter sales(empty line to quit): " << endl;
        for (i = 0; i < QUARTERS; i++)
        {
            while (!(cin >> s.sales[i]))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Enter double type number(empty line to quit): ";
            }
            total += s.sales[i];
            if (i == 0)
            {
                minv = maxv = s.sales[i];
            }
            else
            {
                maxv = maxv > s.sales[i] ? maxv : s.sales[i];
                minv = minv < s.sales[i] ? minv : s.sales[i];             
            }
            cout << "Enter the next sales(empty line to quit): " << endl;
        }
        s.max = maxv;
        s.min = minv;
        s.average = total / i;
    }

    void showSales(const Sales &s)
    {
        cout << "Sales average: " << s.average << endl;
        cout << "Sales max: " << s.max << endl;
        cout << "Sales min: " << s.min << endl;
    }
}