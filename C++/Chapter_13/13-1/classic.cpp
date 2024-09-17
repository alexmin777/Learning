#include <iostream>
#include "classic.h"

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    memcpy(performers, s1, strlen(s1) + 1);
    memcpy(label, s2, strlen(s2) + 1);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    memcpy(performers, d.performers, strlen(d.performers) + 1);
    memcpy(label, d.label, strlen(d.label) + 1);
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
    memcpy(performers, d.performers, strlen(d.performers) + 1);
    memcpy(label, d.label, strlen(d.label) + 1);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

Classic::Classic(const char * key, const char * s1, const char * s2, int n, double x) 
       : Cd(s1, s2, n, x)
{
    memcpy(keyword, key, strlen(key) + 1);
}

Classic::Classic(const Cd & d, const char * key) : Cd(d)
{
    memcpy(keyword, key, strlen(key) + 1);
}

Classic::Classic(const Classic & c)
{
    memcpy(keyword, c.keyword, strlen(c.keyword) + 1);
}

Classic::Classic()
{
    keyword[0] = '\0';
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
    memcpy(keyword, d.keyword, sizeof(d.keyword) + 1);

    return *this;
}