#include <iostream>

double L_to_A(double n);

int main(void)
{
	using namespace std;
	cout << "Enter the number of light years:";
	double light_year;
	cin >> light_year;
	double astro_units = L_to_A(light_year);
	cout << light_year << " light_years = " << astro_units << " astronomical units." << endl;

	return 0;
}

double L_to_A(double n)
{
	return n * 63240;
}