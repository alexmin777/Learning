#ifndef CD_H_
#define CD_H_
#include <iostream>

class Cd{
private:
	char performers[50];
	char label[20];
	int selections; //number of selections
	double playtime; //playing time in minuters

public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd &d);
	Cd();
	virtual ~Cd();
	virtual void Report() const; //reports all CD data
	Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char primarywork[50];

public:
	Classic(const char * pw, const char * s1, const char * s2, int n, double x);
	Classic();
	virtual void Report() const;
};
#endif
