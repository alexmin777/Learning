#include "mytime.h"

Time::Time()
{
    hours = minutes =0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time & a, const Time & b)
{
    Time result;

    result.AddHr(a.hours + b.hours);
    result.AddMin(a.minutes + b.minutes);

    return result;
}

Time operator-(const Time & a, const Time & b)
{
    Time result;
    int total1, total2;

    total1 = a.hours * 60 + a.minutes;
    total2 = b.hours * 60 + b.minutes;
    result.hours = (total1 - total2) / 60;
    result.minutes = (total1 - total2) % 60;

    return result;
}

Time operator*(const Time & t, double m)
{
    Time result;
    long total = t.hours * 60 + t.minutes;

    total *= m;
    result.hours = total / 60;
    result.minutes = total % 60;

    return result;
}

Time operator*(double m, const Time & t)
{
    Time result = t * m;

    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}