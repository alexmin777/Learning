#include <iostream>

int main()
{
	using namespace std;

	double kilometers, gasoline;

	cout << "Enter the number of kilometers you traveled: ";
	cin >> kilometers;
	cout << "Enter the consumed gasoline: ";
	cin >> gasoline;

	cout << "Fuel consumption of 100 km is: " << gasoline / kilometers * 100 << endl;

	return 0;
}