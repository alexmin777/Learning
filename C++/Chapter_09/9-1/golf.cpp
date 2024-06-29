#include <cstring>
#include <iostream>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strncpy(g.fullname, name, Len);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using std::cin;
    using std::cout;
    using std::endl;

    char name[Len];
    int hc;

    cout << "Enter a name: ";
    if(!cin.getline(name, Len)) {
        cout << "Invalid input.\n";
        cin.clear();
        return -1;
    };

    cout << "Enter a handicap: ";
    while (!(cin >> hc))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Please enter number:" << endl;
    }
    while (cin.get() != '\n');

    setgolf(g, name, hc);

    return 0;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using std::cout;
    using std::endl;

    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}