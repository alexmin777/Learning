#include <iostream>

double lightyear_to_AU(double);

int main(void)
{
	using namespace std;

	double lightyears;

	cout << "Enter the number of light years:";
	cin >> lightyears;

	double astronomical_units = lightyear_to_AU(lightyears);
	cout << lightyears << " light years = " << 
			astronomical_units << " astronomical units." << endl;
	
	return 0;
}

double lightyear_to_AU(double lightyears)
{
	return lightyears * 63240;
}