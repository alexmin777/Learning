#include <iostream>
#include <cstdlib>
#include "PersonMI.h"

using std::cin;
using std::cout;
using std::endl;

Person::~Person()
{
}

void Person::Data() const
{
    cout << "First name: " << f_name << endl;
    cout << "Last name: " << l_name << endl;
}

void Person::Get()
{
    cout << "Please enter your first name: ";
    getline(cin, f_name);
    cout << "Please enter your last name: ";
    getline(cin, l_name);
}

void Gunslinger::Data() const
{
    cout << "Gunslinger nicks: " << nicks << endl;
}

void Gunslinger::Get()
{
    cout << "Please enter the nicks for gunslinger: ";
    cin >> nicks;
    while (cin.get() != '\n')
        continue;
}

void Gunslinger::Set()
{
    cout << "Enter Gunslinger name" << endl;
    Person::Get();
    Get();
}

double Gunslinger::Draw() const
{
    return double(rand() % 5 + 1);
}

void Gunslinger::show() const
{
    cout << "Category: Gunslinger" << endl;
    Person::Data();
    Data();
}

void PokerPlayer::Data() const
{
    cout << "The cards: " << Draw() << endl;
}

void PokerPlayer::Set()
{
    cout << "Enter PokerPlayer name" << endl;
    Person::Get();
}

unsigned int PokerPlayer::Draw() const
{
    return (rand() % 52 + 1);
}

void PokerPlayer::show() const
{
    cout << "Category: PokerPlayer" << endl;
    Person::Data();
    Data();
}

void BadDude::Data() const
{
    Gunslinger::Data();
    PokerPlayer::Data();
}

void BadDude::Get()
{
    Gunslinger::Get();
}

void BadDude::Set()
{
    cout << "Enter BadDude name" << endl;
    Person::Get();
    Get();
}

void BadDude::show() const
{
    cout << "Category: PokerPlayer" << endl;
    Person::Data();
    Data();
}

double BadDude::Gdraw() const
{
    return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
    return PokerPlayer::Draw();
}