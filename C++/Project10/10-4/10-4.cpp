#include <iostream>
#include "sales.h"

int main(void)
{
	using SALES::Sales;

	double vals[3] = { 2000, 3000, 5000 };
	Sales forFiji(vals, 3);
	forFiji.showSales();

	Sales red;
	red.showSales();
	red.setSales();
	red.showSales();

	return 0;
}