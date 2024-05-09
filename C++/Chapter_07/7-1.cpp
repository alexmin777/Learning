#include <iostream>

double calc_average(double x, double y);

int main()
{
	using namespace std;

	double x, y;
	double average;

	cout << "Enter two values to calculate average(0 to quite): ";
	while (cin >> x >> y)
	{
		if (x != 0 && y != 0)
		{
			average = calc_average(x, y);
			cout << "The average of " << x << " " << "and " << y << " is " << average << endl;
			cout << "Next two values to calculate average(0 to quite): ";
		}
		else
			break;
	}
	
}

double calc_average(double x, double y)
{
	return (2.0 * x * y ) / (x + y);
}