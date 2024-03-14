#include <iostream>
#include "Sales.h"

namespace SALES
{
	using std::cin;
	using std::cout;
	using std::endl;

	void setSales(Sales& s, const double ar[], int n)
	{
		if (n < 0)
			n = 0;
		int limit = n < QUARTERS ? n : QUARTERS;
		double total = 0;
		s.min = 0;
		s.max = 0;
		s.average = 0;
		if (limit > 0)
			s.min = s.max = ar[0];
		int i;
		for (i = 0; i < limit; i++)
		{
			s.sales[i] = ar[i];
			total += ar[i];
			if (ar[i] > s.max)
				s.max = ar[i];
			else if (ar[i] < s.min)
				s.min = ar[i];
		}
		for (i = limit; i < QUARTERS; i++)
			s.sales[i] = 0;
		if (limit > 0)
			s.average = total / limit;
	}

	void setSales(Sales& s)
	{
		int i;
		for (i = 0; i < QUARTERS; i++) 
		{ 
			cout << "Enter sales for quarter " << i + 1 << ": ";
			cin >> s.sales[i]; 
		}
		double total = 0;
		s.min = s.max = s.sales[0];
		
		for (i = 0; i < QUARTERS; i++) 
		{ 
			total += s.sales[i];
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			else if (s.sales[i] < s.min)
				s.min = s.sales[i]; 
		}
		s.average = total / QUARTERS;
	}

	void showSales(const Sales& s)
	{
		cout << "Sales:\n";
		for (int i = 0; i < QUARTERS; i++)
			cout << "Quarter " << i + 1 << ": $" << s.sales[i] << endl;
		cout << "Average: $" << s.average << endl;
		cout << "Minimum: $" << s.min << endl;
		cout << "Maximum: $" << s.max << endl;
	}
}