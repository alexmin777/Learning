#include "complex0.h"

Complex0::Complex0(double r, double i)
{
    real = r;
    imaginary = i;
}

Complex0::~Complex0()
{

}

Complex0 Complex0::operator+(const Complex0 & a) const
{
    return Complex0(real + a.real, imaginary + a.imaginary);
}

Complex0 Complex0::operator-(const Complex0 & a) const
{
    return Complex0(real - a.real, imaginary - a.imaginary);
}

Complex0 Complex0::operator*(const Complex0 & a) const
{
    return Complex0(real * a.real - imaginary * a.imaginary, real * a.imaginary + imaginary * a.real);
}

Complex0 Complex0::operator*(double n) const
{
    return Complex0(n * real, n * imaginary);
}

Complex0 Complex0::operator~() const
{
    return Complex0(real, -imaginary);
}

Complex0 operator*(double n, const Complex0 & a)
{
    return a * n;
}

std::ostream & operator<<(std::ostream & os, const Complex0 & a)
{
    os << "(" << a.real << "," << a.imaginary << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, Complex0 & a)
{
    std::cout << "real: ";
    if (is >> a.real)
    {
        std::cout << "imaginary: ";
        is >> a.imaginary;
    }
    return is;
}