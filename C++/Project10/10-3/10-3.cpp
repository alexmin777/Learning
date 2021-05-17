#include <iostream>
#include "golf.h"

const int Mems = 5;

int main(void)
{
	golf team[Mems];
	std::cout << "Enter up to " << Mems << " golf team members:\n";
	int i;     
	for (i = 0; i < Mems; i++)
		if (team[i].setgolf() == 0)
			break;
	for (int j = 0; j < i; j++)
		team[j].showgolf();
	team[0] = golf("Fred Norman", 5);
	team[0].showgolf();
	team[0].handicap(3);
	team[0].showgolf();

	return 0;
}