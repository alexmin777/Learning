#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter the world's population:";
	long long world_population;
	cin >> world_population;
	cout << "Enter the population of the US:";
	long long US_population;
	cin >> US_population;
	cout << "The population of the US is " << (double)US_population / world_population * 100
		<< "% of the world population.\n";

	return 0;
}
