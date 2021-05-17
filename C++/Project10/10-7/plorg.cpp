#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char* n)
{
	strncpy(name, n, SIZE - 1);
	name[SIZE - 1] = '\0';
	cl = 50;
}

Plorg::~Plorg()
{

}

void Plorg::alterCI(int c)
{
	cl = c;
}

void Plorg::reprot(void) const
{
	using std::cout;
	cout << "I am a Plorg! My name is " << name 
		<< " and my CI is " << cl << ".\n";
}