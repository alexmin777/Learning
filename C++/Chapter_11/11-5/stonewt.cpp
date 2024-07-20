#include "stonewt.h"

using std::cout;
using std::endl;

Stonewt::Stonewt(double lbs, Mode form)
{
    mode = form;

    if (mode > FORMATE_POUND_FRACTIONAL && mode < FORMATE_STONE)
    {
        cout << "Incorrect mode!" << endl;
        cout << "Stonewt set to 0" << endl;
        stone = pounds = pds_left = 0.0;
        mode = FORMATE_STONE;
    }
    else
    {
        stone = int(lbs) / Lbs_per_stn;
        pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
        pounds = lbs;
    }
}

Stonewt::Stonewt(int stn, double lbs, Mode form)
{
    mode = form;

    if (mode > FORMATE_POUND_FRACTIONAL && mode < FORMATE_STONE)
    {
        cout << "Incorrect mode!" << endl;
        cout << "Stonewt set to 0" << endl;
        stone = pounds = pds_left = 0.0;
        mode = FORMATE_STONE;
    }
    else
    {
        stone = stn;
        pds_left = lbs;
        pounds = stone * Lbs_per_stn + pds_left;
    }
}

Stonewt::Stonewt()
{
    mode = FORMATE_STONE;
    stone = 0;
    pds_left = pounds = 0.0;
}

Stonewt::~Stonewt()
{
    
}

Stonewt Stonewt::operator+(const Stonewt & stn) const
{
    return Stonewt(pounds + stn.pounds, stn.mode);
}

Stonewt Stonewt::operator-(const Stonewt & stn) const
{
    return Stonewt(pounds - stn.pounds, stn.mode);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n, mode);
}

Stonewt operator*(double n, const Stonewt & stn)
{
    return stn * n;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
    if (st.mode == Stonewt::FORMATE_STONE)
    {
        os << st.stone << " stone, " << st.pds_left << " pounds" << endl;
    }
    else if (st.mode == Stonewt::FORMATE_POUND_INTEGER)
    {
        os << (int)st.pounds << " pounds(int)" << endl;
    }
    else if (st.mode == Stonewt::FORMATE_POUND_FRACTIONAL)
    {
        os << st.pounds << " pounds(double)" << endl;
    }
    else
    {
        os << "Incorrect mode!" << endl;
    }
    return os;
}