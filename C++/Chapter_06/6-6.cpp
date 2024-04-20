#include <iostream>
#include <string>
#include <vector>

#define HIGH_MONEY		10000

using namespace std;

typedef struct {
	string name;
	double money;
} patrons;

int main()
{
	int number;
	int grand_patrons = 0;
	int grand = 0;

	cout << "Enter how many people to patronize: ";
	(cin >> number).get();

	vector<patrons> people(number);

	for (int i = 0; i < number; i++)
	{
		cout << "Please enter name #" << i + 1 << ": ";
		getline(cin, people[i].name);
		cout << "Please enter the money of donation #" << i + 1 << ": ";
		while (!(cin >> people[i].money))
		{
			cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter a number: ";
		}
		cin.get();
	}

	for (int i = 0; i < number; i++)
		(people[i].money > HIGH_MONEY) ? grand_patrons++ : grand++;

	cout << "Grand Patrons" << endl;
	if (grand_patrons > 0)
	{
		for (int i = 0; i < number; i++)
		{
			if (people[i].money > HIGH_MONEY)
			{
				cout << "Name: " << people[i].name;
				cout << "\nMoney: " << people[i].money << endl;
			}
		}
	}
	else
		cout << "none" << endl;

	cout << "Patrons" << endl;
	if (grand > 0)
	{
		for (int i = 0; i < number; i++)
		{
			if (people[i].money <= HIGH_MONEY)
			{
				cout << "Name: " << people[i].name;
				cout << "\nMoney: " << people[i].money << endl;
			}
		}
	}
	else
		cout << "none" << endl;
}