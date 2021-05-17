#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
	char mode;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void set_mode(char m) { mode = m; }
	Stonewt operator+(const Stonewt& sw) const;
	Stonewt operator-(const Stonewt& sw) const;
	Stonewt operator*(double m) const;
	friend Stonewt operator*(double m, const Stonewt& sw)
	{
		return sw * m;
	}
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& sw);
};

#endif // !STONEWT_H_
