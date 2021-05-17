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

	CandyBar snack = { "Mocha Munch", 2.3, 350 };

	cout << "snack Brand: " << snack.Brand << endl;
	cout << "snack weight: " << snack.weight << endl;
	cout << "snack calorie: " << snack.calorie << endl;

	return 0;
}