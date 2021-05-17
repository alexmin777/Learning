#include <iostream>
#define MAX 10

using namespace std;
int Fill_array(double ar[], int n);
void Show_array(const double ar[], int n);
void Reverse_array(double ar[], int n);

int main(void)
{
	double value[MAX];
	int num = Fill_array(value, MAX);
	if (num == 0)
	{
		cout << "No data\n";
		return 0;
	}
	else
	{
		cout << "Array values:\n";
		Show_array(value, num);
		cout << "Array reversed:\n";
		Reverse_array(value, num);
		Show_array(value, num);
		cout << "All but end values reversed:\n";
		Reverse_array(value + 1, num - 2);
		Show_array(value, num);
	}
	
	return 0;
}

int Fill_array(double ar[], int n)
{
	cout << "Please enter the data(q to quit): ";
	int i;

	for (i = 0; i < n; i++)
	{
		cin >> ar[i];
		if (!cin)
			break;
	}
	return i;
}

void Show_array(const double ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ar[i];
		if (i % 8 == 7)
			cout << endl;
		else
			cout << " ";
	}
	if (n % 8 != 0)
		cout << endl;
}

void Reverse_array(double ar[], int n)
{
	double temp;
	for (int i = 0; i < (n / 2); i++)
	{
		temp = ar[i];
		ar[i] = ar[n - 1 - i];
		ar[n - 1 - i] = temp;
	}
}