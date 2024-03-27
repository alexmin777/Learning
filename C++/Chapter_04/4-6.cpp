#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calorie;
};

void show(CandyBar candy);

int main()
{
	CandyBar candy[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Mooncake", 3.5, 369},
        {"Birthdaycake", 6.8, 460},
	};

	show(candy[0]);
	show(candy[1]);
	show(candy[2]);

	return 0;
}

void show(CandyBar candy)
{
	cout << "Brand: " << candy.brand << endl;
	cout << "Weight: " << candy.weight << endl;
	cout << "Calorie: " << candy.calorie << endl;
	cout << endl;
}