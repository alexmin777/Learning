#include <cstring>
#include <iostream>
#include "golf.h"

Golf::Golf(const char * name, int hc)
{
    strncpy(fullname, name, Len);
    handicap = hc;
}

Golf::Golf()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char name[Len];
    int hc;

    cout << "Enter a name: ";
    if (!(cin.getline(name, Len)))
    {
        cin.clear();
        cout << "Invalid input, using default parameter.\n";
        *this = Golf("default", 0);
        return;
    }

    cout << "Enter a handicap: ";
    while (!(cin >> hc))
    {
        while (cin.get() != '\n');
        cout << "Please enter number:" << endl;
    }
    while (cin.get() != '\n');

    *this = Golf(name, hc);
}

void Golf::set_handicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf(void) const
{
    using std::cout;
    using std::endl;

    cout << "Name: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
}