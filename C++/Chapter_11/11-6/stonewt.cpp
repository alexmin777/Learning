#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    pounds = lbs;
    stone = (int)lbs / Lbs_per_stn;
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stone * Lbs_per_stn + pds_left;
}

Stonewt::Stonewt()
{
    stone = 0;
    pounds = pds_left = 0.0;
}

Stonewt::~Stonewt()
{

}

bool Stonewt::operator<(const Stonewt &st) const
{
    return pounds < st.pounds ? true : false;
}

bool Stonewt::operator>(const Stonewt &st) const
{
    return pounds > st.pounds ? true : false;
}

bool Stonewt::operator<=(const Stonewt &st) const
{
    return pounds <= st.pounds ? true : false;
}

bool Stonewt::operator>=(const Stonewt &st) const
{
    return pounds >= st.pounds ? true : false;
}

bool Stonewt::operator==(const Stonewt &st) const
{
    return pounds == st.pounds ? true : false;
}

bool Stonewt::operator!=(const Stonewt &st) const
{
    return pounds != st.pounds ? true : false;
}

std::ostream &operator<<(std::ostream &os, const Stonewt &st)
{
    os << st.pounds << " pounds.\n";
    return os;
}