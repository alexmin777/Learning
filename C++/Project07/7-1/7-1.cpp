#include <iostream>

double harmonic_average(double n1, double n2);

int main(void)
{
	using namespace std;
	double n1, n2;

	cout << "Please enter two num(0 to quit): ";
	while (cin >> n1 >> n2 && n1* n2 != 0)
	{
		cout << "harmonic mean of " << n1 << " and " << n2 << " = " << harmonic_average(n1, n2) << "\n";
		cout << "Next: \n";
	}
	cout << "Bye!\n";
	
	return 0;
}

double harmonic_average(double n1, double n2)
{
	return 2.0 * n1 * n2 / (n1 + n2);
}