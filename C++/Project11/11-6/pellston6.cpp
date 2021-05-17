#include<iostream>
#include "pellston6.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + pds_left;
}

Stonewt::Stonewt()
{
	stone = 0;
	pds_left = pounds = 0.0;
}

Stonewt::~Stonewt()
{

}

void Stonewt::show_lbs() const
{
	std::cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
	std::cout << stone << " stone, " << pds_left << " pounds\n";
}