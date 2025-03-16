#include <iostream>
#include "tv.h"

using std::cout;
using std::endl;

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
    channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::setting() const
{
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = ";
        cout << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = ";
        cout << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Tv::set_status(Remote & r)
{
    if (ison())
    {
        r.status = (Remote::Common == r.status ? Remote::Interaction : Remote::Common);
    }
}

void Remote::show_status() const
{
    cout << "Status = " << (status == Common ? "Common" : "Intercation") << endl;
}
