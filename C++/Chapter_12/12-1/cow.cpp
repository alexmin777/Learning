#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
    name[0] = '\0'; 
    hobby = nullptr;
    weigth = 0;
}

Cow::Cow(const char * nm, const char * bo, double wt)
{
    std::strncpy(name, nm, sizeof(name));
    hobby = new char[std::strlen(bo) + 1];
    std::strcpy(hobby, bo);
    weigth = wt;
}

Cow::Cow(const Cow & c)
{
    memcpy(name, c.name, sizeof(name));
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weigth = c.weigth;
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    memcpy(name, c.name, sizeof(name));
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weigth = c.weigth;

    return *this;
}

void Cow::ShowCow() const
{
    using std::cout;
    using std::endl;

    cout << "name: " << name << endl;
    cout << "hobby: " << hobby << endl;;
    cout << "weigth: " << weigth << endl;
}