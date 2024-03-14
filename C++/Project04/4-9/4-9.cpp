#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
	string Brand;
	float weight;
	unsigned long calorie;
};

int main(void)
{
	using namespace std;

	CandyBar * snack = new CandyBar[3];
	snack[0].Brand = "Mocha Munch";
	snack[0].calorie = 350;
	snack[0].weight = 2.3;
	snack[1].Brand = "XuFuJi";
	snack[1].calorie = 300;
	snack[1].weight = 1.1;
	snack[2].Brand = "Alps";
	snack[2].calorie = 100;
	snack[2].weight = 0.4;


	for (int i = 0; i < 3; i++)
	{
		cout << "snack Brand: " << snack[i].Brand << endl;
		cout << "snack weight: " << snack[i].weight << endl;
		cout << "snack calorie: " << snack[i].calorie << endl;
	}

	delete [] snack;
	return 0;
}