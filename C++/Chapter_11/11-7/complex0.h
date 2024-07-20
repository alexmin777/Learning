#ifndef __COMPLEX0_H__
#define __COMPLEX0_H__

#include <iostream>

class Complex0 {
private:
    double real;
    double imaginary;

public:
    Complex0(double r = 0.0, double i = 0.0);
    ~Complex0();
    Complex0 operator+(const Complex0 & a) const;
    Complex0 operator-(const Complex0 & a) const;
    Complex0 operator*(const Complex0 & a) const;
    Complex0 operator*(double n) const;
    Complex0 operator~() const;

//friend:
    friend Complex0 operator*(double n, const Complex0 & a);
    friend std::ostream & operator<<(std::ostream & os, const Complex0 & a);
    friend std::istream & operator>>(std::istream & is, Complex0 & a);
};

#endif // __COMPLEX0_H__