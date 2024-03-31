#include <iostream>

const int Principal = 100;
const double interest_A = 0.1;
const double interest_B = 0.05;

int main()
{
	using namespace std;

	int year = 0;
	double daphne = Principal;
	double cleo = Principal;

	do {
		year++;
		daphne += (Principal * interest_A);
		cleo += (cleo * interest_B);
	} while(daphne > cleo);

	cout << "In the " << year << " year, Cleo beyond Daphe." << endl;
	cout << "Daphe has " << daphne << "$, Cleo has " << cleo << "$." << endl;

	return 0;
}