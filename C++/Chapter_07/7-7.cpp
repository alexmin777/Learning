#include <iostream>

const int MAX = 5;

double * fill_array(double * start, int limit);
void show_array(double * start, double * end);
void revalue(double r, double * start, double * end);

int main()
{
	using namespace std;
	double *properties = new double[MAX];

	double * end = fill_array(properties, MAX);
	show_array(properties, end);

	if (end - properties > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, end);
		show_array(properties, end);
	}
	
	cout << "Done.\n";

	delete [] properties;

	return 0;
}

double * fill_array(double * start, int limit)
{
	using namespace std;

	double temp;
	int i;

	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Bad input; input process terminated." << endl;
			break;
		}
		else if (temp < 0)
			break;
		start[i] = temp;
	}

	return start + i;
}

void show_array(double * start, double * end)
{
	using namespace std;
	for (int i = 0; i < end - start; i++)
	{
		cout << "Property #" << i + 1 << ": $";
		cout << start[i] << endl;
	}
}

void revalue(double r, double * start, double * end)
{
	for (int i = 0; i < end - start; i++)
		start[i] *= r;
}