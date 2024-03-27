#include <iostream>

const double km2mile = 0.6214;
const double gallon2litre =  3.785;

int main()
{
	using namespace std;

	double kilometers, gasoline;

	cout << "Enter the number of kilometers you traveled: ";
	cin >> kilometers;
	cout << "Enter the consumed gasoline: ";
	cin >> gasoline;

	cout << "Fuel consumption of 100 km is: " 
		<< (kilometers * km2mile) / (gasoline / gallon2litre) << endl;

	return 0;
}