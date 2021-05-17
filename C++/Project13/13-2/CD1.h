#ifndef CD1_H_
#define CD1_H_
#include <iostream>

class Cd{
private:
	char * performers;
	char * label;
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
	char * primarywork;

public:
	Classic(const char * pw, const char * s1, const char * s2, int n, double x);
	Classic(const Classic & c1);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	Classic & operator=(const Classic & d);
};
#endif
