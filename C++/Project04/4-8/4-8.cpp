#include <iostream>
#define SIZE 50

struct Pizza
{
	char company[SIZE];
	double diameter;
	double weight;
};

int main(void)
{
	using namespace std;

	Pizza *pie = new Pizza;
	cout << "What's is the Pizza company name: ";
	cin.getline(pie->company, SIZE);
	cout << "What's is the Pizza diameter: ";
	cin >> pie->diameter;
	cout << "What's is the Pizza weight: ";
	cin >> pie->weight;

	cout << "Pizza made in " << pie->company << endl;
	cout << "Diamater is " << pie->diameter << endl;
	cout << "Weight is " << pie->weight << endl;

	delete pie;
	return 0;
}