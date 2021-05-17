#include <iostream>
#include "complex0.h"

complex::complex()
{
	r = i = 0;
}

complex::complex(double real)
{
	r = real;
	i = 0;
}

complex::complex(double real, double imag)
{
	r = real;
	i = imag;
}

complex complex::operator+(const complex& z) const
{
	complex sum;
	sum.r = r + z.r;
	sum.i = i + z.i;

	return sum;
}

complex complex::operator-(const complex& z) const
{
	complex sum;
	sum.r = r - z.r;
	sum.i = i - z.i;

	return sum;
}

complex complex::operator~() const
{
	complex sum;
	sum.r = r;
	sum.i = -i;

	return sum;
}

complex complex::operator*(const complex& z) const
{
	complex sum;
	sum.r = r * z.r - i * z.i;
	sum.i = r * z.i + i * z.r;

	return sum;
}

complex operator*(double m, const complex& z)
{
	complex sum;
	sum.r = m * z.r;
	sum.i = m * z.i;

	return sum;
}

std::ostream& operator<<(std::ostream& os, const complex& z)
{
	os << '(' << z.r << ',' << z.i << "i)";
	return os;
}

std::istream& operator>>(std::istream& is, complex& z)
{
	std::cout << "real: ";
	if (is >> z.r)
	{
		std::cout << "imaginary: ";
		is >> z.i;
	}

	return is;
}