#include <iostream>
#include <string>

using namespace std;
struct Contributors {
	string name;
	double amoint;
};

int main(void)
{
	int contributors;
	cout << "Enter the number of contributors: ";
	cin >> contributors;
	
	while (cin.get() != '\n')
		continue;
	
	Contributors* pc = new Contributors[contributors];
	for (int i = 0; i < contributors; i++)
	{
		cout << "Enter contributor's name: ";
		if (!getline(cin, pc[i].name))
			break;
		cout << "Enter amount of contribution: $";
		if (!(cin >> pc[i].amoint))
			break;
		while (cin.get() != '\n')
			continue;
	}
	
	cout << "Grand Patrons:\n";
	int ct = 0;
	for (int i = 0; i < contributors; i++)
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
	for (int i = 0; i < contributors; i++)
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
	cout << "Done!\n";

	if (!cin)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cin.get();

	return 0;
}