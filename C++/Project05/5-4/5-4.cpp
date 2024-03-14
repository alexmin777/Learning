#include <iostream>

#define CAPITAL 100
#define RATE_A 0.1
#define RATE_B 0.05

int main(void)
{
	using namespace std;
	
	double Cleo = 100, Daphne = 100;
	unsigned int count = 0;

	while (Cleo <= Daphne)
	{
		Cleo = (Cleo * RATE_B) + Cleo;
		Daphne += (CAPITAL * RATE_A);
		count++;
	}

	cout << "When " << count << " years later Cleo more than Daphne.\n";
	cout << "Cleo: " << Cleo << endl;
	cout << "Daphne: " << Daphne << endl;

	return 0;
}