#include <iostream>
#include <cstring>
#include "port.h"

Port::Port(const char * br, const char * st, int b)
{
    int len;

    brand = new char[std::strlen(br) + 1];
    std::strcpy(brand, br);

    std::strncpy(style, st, 20);
    style[19] = '\0';

    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    memcpy(style, p.style, sizeof(style));
    bottles = p.bottles;
}

Port::~Port()
{
    delete [] brand;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;

    delete [] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    memcpy(style, p.style, sizeof(style));
    bottles = p.bottles;

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;

    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;

    return *this;
}

void Port::Show() const
{
    using std::cout;
    using std::endl;

    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    cout << p.brand << ", " << p.style << ", " << p.bottles;

    return os;
}