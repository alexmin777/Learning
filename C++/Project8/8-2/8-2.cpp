#include <iostream>
#include <cstring>
#define SIZE 40

using namespace std;
struct CandyBar {
	char brand[SIZE];
	double weight;
	int calorie;
};

void fill(CandyBar& candy, const char* name = "Millenium Munch",
	const double wei = 2.85, const int cal = 350);
void display(const CandyBar& candy);

int main(void)
{
	CandyBar one;
	CandyBar two;
	fill(one);
	fill(two, "Chockochunks", 3.5, 400);
	display(one);
	display(two);

	return 0;
}

void fill(CandyBar& candy, const char* name, const double wei, const int cal)
{
	strcpy(candy.brand, name);
	candy.weight = wei;
	candy.calorie = cal;
}

void display(const CandyBar& candy)
{
	cout << "Brand: " << candy.brand << endl;
	cout << "Weight: " << candy.weight << endl;
	cout << "Calories: " << candy.calorie << endl;
}