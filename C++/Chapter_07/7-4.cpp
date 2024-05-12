#include <iostream>

long double probability(unsigned number, unsigned picks);

int main()
{
	using namespace std;

    unsigned total, choices, temp;
    cout << "Enter the total number of choices on the game card and\n";
    cout << "the number of picks allowed and the second section(<= total number):" << endl;
	
	while ((cin >> total >> choices >> temp) && choices <= total && temp <= total)
	{
		cout << probability(total, choices) * probability(temp, 1);
		cout << " of winning.\n";
        cout << "Next three numbers (q to quit): ";
	}

	cout << "bye\n";

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