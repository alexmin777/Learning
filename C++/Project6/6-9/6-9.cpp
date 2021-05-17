#include <iostream>
#include <fstream>
#include <cstdlib>
#define SIZE 80

using namespace std;

struct Contributors {
	char name[SIZE];
	double amoint;
};

int main(void)
{
	char filename[SIZE];
	ifstream inFile;
	char ch;

	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	
	int contributors;
	if (!(inFile >> contributors))
	{
		cout << "Data mismatch for contributor count.\n";
		exit(EXIT_FAILURE);
	}
	while (inFile.get(ch) && ch != '\n')
		continue;
	
	if (!inFile)
	{
		cout << "Problems reading file.\n";
		exit(EXIT_FAILURE);
	}

	Contributors* pc = new Contributors[contributors];
	int k = 0;
	while (inFile && k < contributors)
	{
		if (!inFile.getline(pc[k].name, 80))
			break;
		if (!(inFile >> pc[k].amoint))
			break;
		k++;
		while (inFile.get(ch) && ch != '\n')
			continue;
	}

	int total = k;
	cout << "Grand Patrons:\n";
	int ct = 0;
	for (int i = 0; i < total; i++)
	{
		if (pc[i].amoint > 10000)
		{
			ct++;
			cout << pc[i].name << ": $" << pc[i].amoint << endl;
		}
	}
	if (ct == 0)
		cout << "None!\n";
	ct = 0;
	cout << "Patrons:\n";
	for (int i = 0; i < total; i++)
	{
		if (pc[i].amoint <= 10000)
		{
			ct++;
			cout << pc[i].name << ": $" << pc[i].amoint << endl;
		}
	}
	if (ct == 0)
		cout << "None!\n";
	delete[] pc;
	inFile.close();
	cout << "Done!\n";

	return 0;
}