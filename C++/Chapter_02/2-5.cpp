#include <iostream>

double celsius_to_fahrenheit(double);

int main()
{
	using namespace std;

	double celsius;

	cout << "Please enter a Celsius value: ";
	cin >> celsius;
	double fahrenheit = celsius_to_fahrenheit(celsius);

	cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit" << endl;

	return 0;
}

double celsius_to_fahrenheit(double celsius)
{
	return 1.8 * celsius + 32.0;
}