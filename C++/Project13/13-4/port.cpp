#include <iostream>
#include <cstring>
#include "port.h"

using namespace std;

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	delete [] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	if (bottles < b)
		std::cout << "Inventory too low. Removal failed.\n\n";
	else
		bottles -= b;
	return *this;
}

void Port::Show() const
{
	using std::cout;
	using std::endl;
	cout << "Brand: " << brand << endl;
	cout << "Style: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort()
	: Port()
{
	nikename = new char[5];
	strcpy(nikename, "none");
	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "Vintage", b)
{
	nikename = new char[strlen(nn) + 1];
	strcpy(nikename, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
	: Port(vp)
{
	nikename = new char[strlen(vp.nikename) + 1];
	strcpy(nikename, vp.nikename);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete [] nikename;

	nikename = new char[strlen(vp.nikename) + 1];
	strcpy(nikename, vp.nikename);
	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{
	using std::cout;
	using std::endl;
	Port::Show();
	cout << "Nickname: " << nikename << endl;
	cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << (const Port &)vp;
	os << ", " << vp.nikename << ", " << vp.year;
	return os;
}