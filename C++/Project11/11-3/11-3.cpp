#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../11-1/vect.h"

int main(void)
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	unsigned long average, max, min;
	unsigned long trials;

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		cout << "Enter number of trials: ";
		if (!(cin >> trials))
			break;
		average = 0;
		for (int i = 0; i < trials; i++)
		{	
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			if (i == 0)
				min = max = steps;
			else
			{
				if (steps > max) max = steps;
				if (steps < min) min = steps;
			}
			average += steps;
			steps = 0;
			result.reset(0.0, 0.0);
		}
		if (trials < 1)
		{
			cout << "No trials\n";
			continue;
		}
		average /= trials;

		cout << "Trials: " << trials << '\n';
		cout << "Average number of steps: " << average << '\n';
		cout << "Minimum number of steps: " << min << '\n';
		cout << "Maximum number of steps: " << max << '\n';
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";

	}
	cout << "Bye!\n";

	return 0;
}