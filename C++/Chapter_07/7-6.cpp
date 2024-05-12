#include <iostream>

using namespace std;

int fill_array(double * p, int size);
void show_array(const double * p, int size);
void reverse_array(double * p, int size);

const int MAX_Size = 10;

int main()
{
	double * pdata = new double[MAX_Size];
	int real_size;

	real_size = fill_array(pdata, MAX_Size);
	show_array(pdata, real_size);
	reverse_array(pdata, real_size);
	show_array(pdata, real_size);

	delete [] pdata;

	return 0;
}

int fill_array(double * p, int size)
{
	int real_size = 0;

	cout << "Enter type of double data(not digit to quit):";

	while (real_size < size && cin >> p[real_size])
	{
		cout << "The Next(not digit to quit):";
		real_size++;
	}

	return real_size;
}

void show_array(const double * p, int size)
{
	cout << "Data:";

	for (int i = 0; i < size; i++)
		cout << p[i] << " ";

	cout << endl;
}

void reverse_array(double * p, int size)
{
	double temp;

	for (int i = 0; i <= (size / 2); i++)
	{
		temp = p[i];
		p[i] = p[size - i - 1];
		p[size - i - 1] = temp;
	}
}