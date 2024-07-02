#include "sales.h"
#include <iostream>

int main()
{
    double test_ar[] = {1, 2, 3, 4};
    SALES::Sales alex;
    SALES::Sales min(test_ar, 4);

    alex.showSales();
    min.showSales();

    std::cout << "use default constructor" << std::endl;
    double test;
    SALES::Sales mjl(&test, 0);
    mjl.showSales();

    return 0;
}