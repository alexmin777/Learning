#include <iostream>
#include <array>

int main()
{
	using namespace std;

	array<double, 3> report;

	cout << "Enter first report: ";
	cin >> report[0];
	cout << "Enter second report: ";
	cin >> report[1];
	cout << "Enter third report: ";
	cin >> report[2];

    cout << "You ran three times in total." << endl;
    cout << "Your average score is ";
	cout << (report[0] + report[1] + report[2]) /3 << endl;

	return 0;
}