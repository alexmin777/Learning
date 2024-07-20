#ifndef __STONEWT_H__
#define __STONEWT_H__

#include <iostream>

class Stonewt {
public:
    enum Mode {FORMATE_STONE, FORMATE_POUND_INTEGER, FORMATE_POUND_FRACTIONAL};
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    Mode mode;
public:
    Stonewt(double lbs, Mode form);
    Stonewt(int stn, double lbs, Mode form);
    Stonewt();
    ~Stonewt();
    void setmode(Mode from) { mode = from; }
    Stonewt operator+(const Stonewt & stn) const;
    Stonewt operator-(const Stonewt & stn) const;
    Stonewt operator*(double n) const;
//friend:
    friend Stonewt operator*(double n, const Stonewt & stn);
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & stn);
};

#endif  // __STONEWT_H__