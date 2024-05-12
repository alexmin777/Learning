#include <iostream>

const int Seasons = 4;
const char * Snames[Seasons] = {
	"Spring", "Summer", "Fall", "Winter"
};

typedef struct {
	double data[Seasons];
} payments;

void fill(payments * pa);
void show(const payments * da);

int main()
{
	payments expenses;
	
	fill(&expenses);
	show(&expenses);

	return 0;
}

void fill(payments * pa)
{
	using namespace std;

	for (int i = 0; i < Seasons; i++)
	{
		cout <<"Enter " << Snames[i] << " expenses: ";
		cin >> pa->data[i];
	}
}

void show(const payments * da)
{
	using namespace std;

	double total = 0.0;

	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da->data[i] << endl;
		total += da->data[i];
	}
	cout << "Total Expenses: $" << total << endl;
}