#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define HIGH_MONEY		10000

using namespace std;

typedef struct {
	string name;
	double money;
} patrons_t;

int main()
{
	ifstream file;
	string filename;
	int num;
	int count = 0;

	cout << "Enter what file you want to open:";
	getline(cin, filename);
	file.open(filename);
	if (!file.is_open())
	{
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
	}

	(file >> num).get();

	vector<patrons_t> patrons(num);

	for (int i = 0; i < num && file.good(); i++)
	{
		getline(file, patrons[i].name);

		file >> patrons[i].money;
		if (patrons[i].money > HIGH_MONEY)
			count++;
		file.get();
	}

	cout << "Grand Patrons" << endl;
	if (count > 0)
	{
		for (int i = 0; i < num; i++)
		{
			if (patrons[i].money > HIGH_MONEY)
			{
				cout << "Name:" << patrons[i].name << endl;
				cout << "Money:" << patrons[i].money << endl;
			}
		}
	}
	else
		cout << "None" << endl;

	cout << "Patrons" << endl;
	if (num - count > 0)
	{
		for (int i = 0; i < num; i++)
		{
			if (patrons[i].money <= HIGH_MONEY)
			{
				cout << "Name:" << patrons[i].name << endl;
				cout << "Money:" << patrons[i].money << endl;
			}
		}
	}
	else
		cout << "None" << endl;

	cout << num << endl;
}
