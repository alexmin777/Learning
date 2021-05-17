#include <iostream>
#define SIZE	50

struct CandyBar {
	char Brand[SIZE];
	float weight;
	unsigned long calorie;
};

int main(void)
{
	using namespace std;

	CandyBar snack[3] = { 
		{ "Mocha Munch", 2.3, 350 },
		{"XuFuji", 1.1, 300},
		{"Alps", 0.4, 100}
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "snack Brand: " << snack[i].Brand << endl;
		cout << "snack weight: " << snack[i].weight << endl;
		cout << "snack calorie: " << snack[i].calorie << endl;
	}

	return 0;
}