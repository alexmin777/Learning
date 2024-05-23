#include <iostream>
#include <cstring>

struct CandyBar {
	char brand[20];
	double weight;
	int heat;
};

void setCandyBar(CandyBar &bar, const char *name = "Millennium Munch", double weight = 2.85, int heat = 350);
void show(const CandyBar &bar);

int main()
{
	CandyBar bar;

	setCandyBar(bar);
	show(bar);

	return 0;
}

void setCandyBar(CandyBar &bar, const char *name, double weight, int heat)
{
	strcpy(bar.brand, name);
	bar.weight = weight;
	bar.heat = heat;
}

void show(const CandyBar &bar)
{
	using namespace std;

	cout << bar.brand << " weight:" << bar.weight
		 << " heat:" << bar.heat << endl;
}