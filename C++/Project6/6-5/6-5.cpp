#include <iostream>
#define TAX1 0.1
#define TAX2 0.15
#define TAX3 0.2
#define INCOME1 5000
#define INCOME2 15000
#define INCOME3 35000

int main(void)
{
	using namespace std;
	double income;
	double tax;

	cout << "Enter an annual income in tvarps: ";
	while ((cin >> income) && (income >= 0))
	{
		if (income <= INCOME1)
			tax = 0;
		else if (income <= INCOME2)
			tax = (income - INCOME1) * TAX1;
		else if (income <= INCOME3)
			tax = (INCOME2 - INCOME1) * TAX1 + (income - INCOME2) * TAX2;
		else
			tax = (INCOME2 - INCOME1) * TAX1 + (INCOME3 - INCOME2) * TAX2 + (income - INCOME3) * TAX3;
		cout << "Neutronia is owed " << tax << " tvarps in taxes.\n";
		cout << "Enter an annual income in tvarps: ";
	}
	cout << "Done!\n";
	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	else
		cin.get();

	return 0;
}