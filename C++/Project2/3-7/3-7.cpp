#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter the automoblie gasoline consumption figure in\n"
		<< "European style(liters per 100 kilometers):";
	double Eurp_style;
	cin >> Eurp_style;
	cout << "Converts to U.S. style(miles per gallon):" << endl;
	cout << Eurp_style << " L/100Km = " << 62.14 * 3.875 / Eurp_style << " mpg\n";

	return 0;
}