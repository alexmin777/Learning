#include <cstring>
#include <iostream>
#include "CD.h"

//class Cd
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	strncpy(performers, s1, 49);
	performers[49] = '\0';
	strncpy(label, s2, 19);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	strncpy(performers, d.performers, 49);
	performers[49] = '\0';
	strncpy(label, d.label, 19);
	label[19] = '\0';
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{

}
void Cd::Report() const
{
	using std::cout;
	using std::endl;
	cout << "Performer(s): " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Number of selections: " << selections << endl;
	cout << "Play time: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

//class Classic
Classic::Classic(const char * pw, const char * s1, const char * s2, int n, double x)
: Cd(s1, s2, n, x)
{
	strncpy(primarywork, pw, 49);
	primarywork[49] = '\0';
}

Classic::Classic() : Cd()
{
	primarywork[0] = '\0';
}

void Classic::Report() const
{
	std::cout << "Primary work: " << primarywork << std::endl;
	Cd::Report();
}
