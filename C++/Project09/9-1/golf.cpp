#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf& g, const char* name, int hc)
{
	std::strncpy(g.fullname, name, Len);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Please enter golfer's full name: ";
	cin.getline(g.fullname, Len);
	if (g.fullname[0] == '\0')
		return 0;
	cout << "Please enter handicap for " << g.fullname << ": ";
	while (!(cin >> g.handicap))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter an integer: ";
	}
	while (cin.get() != '\n')
		continue;

	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "Golfer:   " << g.fullname << "\n";
	std::cout << "Handicap: " << g.handicap << "\n\n";
}