#include <iostream>
#define MAX 5

double* fill_array(double *start, double *end);
void show_array(const double* start, const double* end);
void revalue(double n, double* start, double* end);

int main(void)
{
	using namespace std;
	double properties[MAX];
	double* end;

	end = fill_array(properties, properties + MAX);
	show_array(properties, end);
	
	if (end != properties)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, end);
		show_array(properties, end);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();

	return 0;
}

double* fill_array(double* start, double* end)
{
	using namespace std;
	double temp;
	double * pt = start;
	for (int i = 0; pt != end; pt++, i++)
	{
		cout << "Enter value #" << (i + 1) << " :";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		else
		{
			*pt = temp;
		}
	}
	
	return pt;
}

void show_array(const double* start, const double* end)
{
	using namespace std;
	for (int i = 0; start != end; start++, i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *start << endl;
	}
}

void revalue(double n, double* start, double* end)
{
	for (; start != end; start++)
		*start *= n;
}