#include <iostream>
#include "classic.h"

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
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
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const
{
    using std::cout;
    using std::endl;

    cout << endl;
    cout << "Performers : " << performers << endl;
    cout << "label : " << label << endl;
    cout << "selections : " << selections << endl;
    cout << "playtime : " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
        return *this;

    delete [] performers;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);

    delete [] label;
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Classic::Classic(const char * key, const char * s1, const char * s2, int n, double x) 
       : Cd(s1, s2, n, x)
{
    keyword = new char[strlen(key) + 1];
    strcpy(keyword, key);
}

Classic::Classic(const Cd & d, const char * key) : Cd(d)
{
    keyword = new char[strlen(key) + 1];
    strcpy(keyword, key);
}

Classic::Classic(const Classic & c)
{
    keyword = new char[strlen(c.keyword) + 1];
    strcpy(keyword, c.keyword);
}

Classic::Classic()
{
    keyword = nullptr;
}

Classic::~Classic()
{
    delete[] keyword;
}

void Classic::Report() const
{
    using std::cout;
    using std::endl;

    Cd::Report();
    cout << "keyword : " << keyword << endl << endl;
}

Classic & Classic::operator=(const Classic & d)
{
    if (this == &d)
        return *this;

    delete [] keyword;
    keyword = new char[strlen(d.keyword) + 1];
    strcpy(keyword, d.keyword);
    Cd::operator=(d);

    return *this;
}