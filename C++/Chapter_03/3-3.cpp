#include <iostream>

const double degree2minute = 60.0;
const double minute2second = 60.0;

int main()
{
	using namespace std;

	int degree, minute, second;

	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ";
	cin >> degree;
	cout << "Second, enter the minutes of arc: ";
	cin >> minute;
	cout<< "Finally, enter the seconds of arc: ";
	cin >> second;

	cout << degree << " degree, "
		<< minute << " minutes, "
		<< second << " seconds "
		<< "= " << degree + ((minute + second / minute2second) / degree2minute)
		<< " degrees" << endl;

	return 0;
}