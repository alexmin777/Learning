#include <iostream>
#include"golf.h"
#include <cstring>

golf::golf(const char* name, int hc)
{
	std::strcpy(fullname, name);
	handicap_ = hc;
}

int golf::setgolf()
{
	char fname[Len];
	std::cout << "Please enter golfer's full name: ";
	std::cin.getline(fname, Len);
	std::cin.getline(fname, Len);
	if (fname[0] == '\0')
		return 0;
	std::cout << "Please enter handicap for " << fname << ": ";
	int hc;
	while (!(std::cin >> hc)) 
	{ 
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Please enter an integer: "; 
	}
	while (std::cin.get() != '\n')
		continue;
	*this = golf(fname, hc);
	return 1;
}

void golf::handicap(int hc)
{
	handicap_ = hc;
}

void golf::showgolf() const
{
	std::cout << "Golfer:   " << fullname << "\n";
	std::cout << "Handicap: " << handicap_ << "\n\n";
}