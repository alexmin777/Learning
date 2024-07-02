#include "sales.h"
#include <iostream>

SALES::Sales::Sales(const double ar[], int n)
{
    if (n > QUARTERS) {
        std::cerr << "Warning: too many elements, set to " << QUARTERS << std::endl;
        n = QUARTERS;
    } else if (n <= 0) {
        std::cerr << "Warning: the number of elements must be greater than 0, pls enetr sales." << std::endl;
        *this = Sales();

        return;
    }

    double total =  ar[0];
    double tmp_max = ar[0];
    double tmp_min = ar[0];
    sales[0] = ar[0];
    for (int i = 1; i < n; i++) {
        sales[i] = ar[i];
        total += ar[i];
        tmp_max = tmp_max >  ar[i] ? tmp_max : ar[i];
        tmp_min = tmp_min <  ar[i] ? tmp_min : ar[i];
    }
    average = total / n;
    max = tmp_max;
    min = tmp_min;
}

SALES::Sales::Sales()
{
    using std::cin;
    using std::cout;

    int i;
    double total = 0, maxv = 0, minv = 0;
    double tmp_sales[QUARTERS];

    cout << "Enter sales(empty line to quit): \n";
    for (i = 0; i < QUARTERS; i++) {
        while (!(cin >> tmp_sales[i])) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Enter double type number(empty line to quit): ";
        }

        cout << "Enter the next sales(empty line to quit): \n";
    }

    *this = Sales(tmp_sales, i);
}

void SALES::Sales::showSales(void) const
{
    using std::cout;
    using std::endl;

    cout << "Sales average: " << average << endl;
    cout << "Sales max: " << max << endl;
    cout << "Sales min: " << min << endl;
}