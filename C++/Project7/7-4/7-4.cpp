#include <iostream>

long double probability(unsigned number, unsigned picks);

int main(void)
{
	using namespace std;
	double total, choices;
	double mtotal;
	double probability1, probability2;
	cout << "Enter the total number of choice on the game card and\n"
		"the number of picks allowed:";
	while ((cin >> total >> choices) && (choices <= total))
	{
		cout << "Enter total number of game card choices "
			"for the mega number:\n";
		if (!(cin >> mtotal))
			break;
		cout << "The chances of getting all " << choices << " picks is one in "
			<< (probability1 = probability(total, choices)) << ".\n";
		cout << "The chances of getting the megaspot is one in " 
			<< (probability2 = probability(mtotal, 1)) << ".\n";
		cout << "You have one chance in ";
		cout << probability1 * probability2;      // compute the probability
		cout << " of winning.\n";         
		cout << "Next set of numbers (q to quit): ";
	}
	cout << "bye\n";

	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	else
		cin.get();
	cin.get();

	return 0;
}

long double probability(unsigned number, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = number, p = picks; p > 0; n--, p--)
		result = result * n / p;

	return result;
}