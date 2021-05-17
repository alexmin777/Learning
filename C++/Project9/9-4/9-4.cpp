#include <iostream>
#include "Sales.h"

int main(void)
{
	using SALES::Sales;
	using SALES::setSales;
	using SALES::showSales;

	Sales s1 = {0};
	double vals[3] = { 2000, 3000, 5000 };
	setSales(s1, vals, 3);
	showSales(s1);

	Sales s2 = { 0 };
	setSales(s2);
	showSales(s2);

	return 0;
}