#include <cstring>
#include <iostream>
#include "CD1.h"

//class Cd
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strcpy(performers, s1);
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[8];
	strcpy(performers, "Unknown");
	label = new char[8];
	strcpy(label, "Unknown");
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{
	delete[] performers;
	delete[] label;
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
	delete[] performers;
	delete[] label;

	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

//class Classic
Classic::Classic(const char * pw, const char * s1, const char * s2, int n, double x)
: Cd(s1, s2, n, x)
{
	primarywork = new char[strlen(pw) + 1];
	strcpy(primarywork, pw);
}

Classic::Classic(const Classic & c1) : Cd(c1)
{
	primarywork = new char[strlen(c1.primarywork) + 1];
	strcpy(primarywork, c1.primarywork);
}
Classic::Classic() : Cd()
{
	primarywork = new char[5];
	strcpy(primarywork, "None");
}

Classic::~Classic()
{
	delete[] primarywork;
}

void Classic::Report() const
{
	std::cout << "Primary work: " << primarywork << std::endl;
	Cd::Report();
}

Classic & Classic::operator=(const Classic & d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[] primarywork;

	primarywork = new char[strlen(d.primarywork) + 1];
	strcpy(primarywork, d.primarywork);
	return *this;
}
