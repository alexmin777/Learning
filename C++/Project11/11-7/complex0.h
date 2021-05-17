#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex {
private:
	double r;
	double i;
public:
	complex();
	complex(double real);
	complex(double real, double imag);
	complex operator+(const complex & z) const;
	complex operator-(const complex& z) const;
	complex operator*(const complex& z) const;
	complex operator~() const;

	//friend interface
	friend complex operator*(double m, const complex& z);
	friend std::ostream& operator<<(std::ostream& os, const complex& z);
	friend std::istream& operator>>(std::istream& is, complex& z);

};
#endif // !COMPLEX_H_