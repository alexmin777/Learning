#include <iostream>
#define MAX 10

void display(const int*, int);
int get_result(int[], int);
double get_average(const int[], int);

int main(void)
{
	using namespace std;
	int result[MAX] = { 0 };

	int times = get_result(result, MAX);
	display(result, times);
	if (times > 0)
		cout << get_average(result, times) << " = average\n";
	else
		cout << "No scores!\n";

	return 0;
}

int get_result(int ar[], int n)
{
	using namespace std;
	cout << "Enter up to " << n << " scores <q to quit>:\n";
	int i;
	for (i = 0; i < n; i++)
	{
		if (!(cin >> ar[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			break;
		}
	}

	return i;
}

void display(const int * ar, int n)
{
	using namespace std;
	
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

double get_average(const int ar[], int n)
{
	double total = 0;
	for (int i = 0; i < n; i++)
		total += ar[i];

	return (double)(total / n);
}