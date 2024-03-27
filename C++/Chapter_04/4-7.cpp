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
	pizza domino;

	cout << "Pizza company: ";
	getline(cin, domino.company);
	cout << "Pizza diameter: ";
	cin >> domino.diameter;
	cout << "Pizza weight: ";
	cin >> domino.weight;

	cout << domino.company << "'s pizza";
	cout << ", diameter is " << domino.diameter;
	cout << ", weight is " << domino.weight << endl;

	return 0;
}