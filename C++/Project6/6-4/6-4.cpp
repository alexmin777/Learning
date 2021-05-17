#include <iostream>
#define strsize 40
#define bopsize 5

using namespace std;

struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

void showmenu(void);
void showa(bop ar[], int size);
void showb(bop ar[], int size);
void showc(bop ar[], int size);
void showd(bop ar[], int size);

int main(void)
{
	bop team[bopsize] = { 
		{"Wimp Macho", "Senior Programmer", "UNIXMAN", 0},
		{"Raki Rhodes", "Junior Programmer", "ESATA", 1},
		{"Celia Laiter",  "Junior Analyst", "MIPS", 2},
		{"Hoppy Hipman", "Analyst Trainee", "THUNDERBOLT", 1},
		{"Pat Hand", "Junior Programmer", "LOOPY" ,2 } 
	};

	showmenu();

	cout << "Enter your choice: ";
	char choice;

	while ((cin >> choice) && (choice != 'q'))
	{
		switch (choice)
		{
		case 'a': showa(team, bopsize);
			break;
		case 'b': showb(team, bopsize);
			break;
		case 'c': showc(team, bopsize);
			break;
		case 'd': showd(team, bopsize);
			break;
		default: cout << "Enter only a, b, c, d, or q.\n";
		}
		cout << "Next choice: ";
	}

	cout << "Bye!\n";
	
	return 0;
}

void showmenu(void)
{
	cout << "Benevolent Order of Programmers Report\n";
	cout << "a. display by name     b. display by title\n" 
		<< "c. display by bopname  d. display by preference\n" 
		<< "q. quit\n";
}

void showa(bop ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i].fullname << endl;
}

void showb(bop ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i].title << endl;
}

void showc(bop ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i].bopname << endl;
}

void showd(bop ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i].preference == 0)
			cout << ar[i].fullname << endl;
		else if (ar[i].preference == 1)
			cout << ar[i].title << endl;
		else if (ar[i].preference == 2)
			cout << ar[i].bopname << endl;
		else
			cout << "oops.\n";
	}
}