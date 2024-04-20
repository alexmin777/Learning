#include <iostream>

#define TAX_LEVEL1			5000
#define TAX_LEVEL2			15000
#define TAX_LEVEL3			35000
#define TAX_RATE1			0
#define TAX_RATE2			0.1
#define TAX_RATE3			0.15
#define TAX_RATE4			0.2

int main()
{
	using namespace std;

	double income;
	double tax;

	cout << "Enter your income(q to quit):" << endl;
	while (cin >> income && income >= 0)
	{
		if (income <= TAX_LEVEL1)
			tax = income * TAX_RATE1;
		else if (income > TAX_LEVEL1 && income <= TAX_LEVEL2)
			tax = TAX_LEVEL1 * TAX_RATE1 + (income - TAX_LEVEL1) * TAX_RATE2;
		else if (income > TAX_LEVEL2 && income <= TAX_LEVEL3)
			tax = TAX_LEVEL1 * TAX_RATE1 + (TAX_LEVEL2 - TAX_LEVEL1) * TAX_RATE2 + (income - TAX_LEVEL2) * TAX_RATE3;
		else
			tax = TAX_LEVEL1 * TAX_RATE1 + (TAX_LEVEL2 - TAX_LEVEL1) * TAX_RATE2 + (TAX_LEVEL3 - TAX_LEVEL2) * TAX_RATE3 + (income - TAX_LEVEL3) * TAX_RATE4;
		
		cout << "You should pay " << tax << " tvarp." << endl;
		cout << "Next wage (q or <0 to quit): ";
	}
	
	cout << "Bye." << endl;

	return 0;
}