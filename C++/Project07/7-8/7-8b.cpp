#include <iostream>
#define Seasons 4

const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

struct hold_ar{
	double cost[Seasons];
};

void fill(hold_ar* pa, int n);
void show(const hold_ar* da, int n);

int main(void)
{
	hold_ar expenses = {0};
	fill(&expenses, Seasons);
	show(&expenses, Seasons);

	return 0;
}

void fill(hold_ar* pa, int n)
{
	using namespace std;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->cost[i];
	}
}

void show(const hold_ar* da, int n)
{
	using namespace std;
	double total = 0;
	cout << "\n EXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da->cost[i] << endl;
		total += da->cost[i];
	}
	cout << "Total Expense: $" << total << endl;
}