#include <iostream>

using namespace std;

const int NUM = 5;
const int strsize = 50;

typedef struct {
	char fullname[strsize];			//real name
	char title[strsize];			//job title
	char bopname[strsize];			//secret BOP name
	int preference;					//0 = fullname, 1 = title, 2 = bopname
} bop;

void show_menu(void);

int main()
{
	char ch;
    bop people[NUM] = {
        {"Wimp Macho", "Teacher", "WMA", 0},
        {"Raki Rhodes", "Junior Programmer", "RHES", 1},
        {"Celia Laiter", "Professor", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "HPAN", 1},
        {"Pat Hand", "Animal Keeper", "LOOPY", 2},
    };

	cout << "Benevolent Order of Programs Report" << endl;
	show_menu();

	cout << "Enter your choice:" << endl;
	while (cin >> ch && ch != 'q')
	{
		switch (ch)
		{
			case 'a':
				for (int i = 0; i < NUM; i++)
					cout << people[i].fullname << endl;
				break;
			case 'b':
				for (int i = 0; i < NUM; i++)
					cout << people[i].title << endl;
				break;
			case 'c':
				for (int i = 0; i < NUM; i++)
					cout << people[i].bopname << endl;
				break;
			case 'd':
				for (int i = 0; i < NUM; i++)
				{
					switch (people[i].preference)
					{
						case 0:
							cout << people[i].fullname << endl;
							break;
						case 1:
							cout << people[i].title << endl;
							break;
						case 2:
							cout << people[i].bopname << endl;
							break;
						default:
							break;
					}
				}
				break;
			default:
				cout << "Illegal input!" << endl;
				break;

		}

		cout << "Next choice:" << endl;
	}

	cout << "Bye!" << endl;

	return 0;
}

void show_menu(void)
{
	cout << "a.display by name		b.display by title" << endl;
	cout << "c.display by bopname		d.display by preference" << endl;
	cout << "q.quit" << endl;
}