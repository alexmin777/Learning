#include <iostream>
#include <string>

struct Car {
	std::string product;
	int years;
};

int main()
{
	using namespace std;

	int nums;
	
	cout << "How many cars do you wish to catalog? ";
	(cin >> nums).get();

	Car *cars = new Car[nums];
	
	for (int i = 0; i < nums; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Please enter the make: ";
		getline(cin, cars[i].product);
		cout << "Please enter the year made: ";
		(cin >> cars[i].years).get();
	}
	cout << "Here is your collection:" << endl;
	
	for (int i = 0; i < nums; i++)
	{
		cout << cars[i].years << " " << cars[i].product << endl;
	}

	delete[] cars;

	return 0;
}