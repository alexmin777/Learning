#include <iostream>

double Celsius_to_Fahrenheit(double n);

int main(void)
{
	using namespace std;

	cout << "Please enter a Celsius value: ";
	double celsius;
	cin >> celsius;
	double fahrenheit = Celsius_to_Fahrenheit(celsius);
	cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahreheit." << endl;

	return 0;
}

double Celsius_to_Fahrenheit(double n)
{
	return 1.8 * n + 32.0;
}