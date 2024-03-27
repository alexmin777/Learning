#include <iostream>
#include <string>

using namespace std;

struct pizza {
	string company;
	double diameter;
	double weight;
};

int main()
{
	pizza *domino = new pizza;

	cout << "Pizza diameter: ";
	cin >> domino->diameter;
	cin.get();
	cout << "Pizza company: ";
	getline(cin, domino->company);
	cout << "Pizza weight: ";
	cin >> domino->weight;

	cout << domino->company << "'s pizza";
	cout << ", diameter is " << domino->diameter;
	cout << ", weight is " << domino->weight << endl;

	delete domino;

	return 0;
}