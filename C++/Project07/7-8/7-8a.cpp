#include <iostream>
#define Seasons 4

const char * Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double* pa, int n);
void show(const double* da, int n);

int main(void)
{
	double expenses[Seasons];
	fill(expenses, Seasons);
	show(expenses, Seasons);

	return 0;
}

void fill(double* pa, int n)
{
	using namespace std;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}

void show(const double* da, int n)
{
	using namespace std;
	double total = 0;
	cout << "\n EXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expense: $" << total << endl;
}