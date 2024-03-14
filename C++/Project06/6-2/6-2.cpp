#include <iostream>
#include <array>
#define SIZE 10

int main(void)
{
	using namespace std;

	array<double, SIZE> ar = {0};
	//double ar[SIZE] = { 0 };
	double total = 0;
	unsigned int count = 0;
	cout << "Please enter num(q to quit):";
	
	cout << "donation #1: ";
	while ((count < SIZE) && (cin >> ar[count]))
	{
		if (++count < SIZE)
			cout << "donation #" << count + 1 << ": ";
	}
	
	for (int i = 0; i < count; i++)
		total += ar[i];

	if (count == 0)
		cout << "No donations\n";
	else
	{
		double average = total / count;
		unsigned int above = 0;
		cout << "average = " << average << endl;
		
		for (int i = 0; i < count; i++)
		{
			if (ar[i] < average)
				above++;
		}
		cout << above << " contributions above average!\n";
	}

	return 0;
}