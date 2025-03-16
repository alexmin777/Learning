#ifndef EXC_MEAN_H
#define EXC_MEAN_H

#include <iostream>
#include <string>
#include <stdexcept>

class mean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    mean(const std::string &s = "none", double a = 0.0, double b = 0.0) : logic_error(s), v1(a), v2(b) {}
    const double &val1() const { return v1; }
    const double &val2() const { return v2; }
};

class bad_hmean : public mean
{
public:
    bad_hmean(const std::string &s = "none", double a = 0.0, double b = 0.0) : mean(s, a, b) {}
    void mesg() const;
};

inline void bad_hmean::mesg() const
{
    std::cout << "hmean(" << val1() << ", " << val2() << "):" << std::endl;
    std::cout << "hmean() arguments should be a != b" << std::endl;
}

class bad_gmean : public mean
{
public:
    bad_gmean(const std::string &s = "none", double a = 0.0, double b = 0.0) : mean(s, a, b) {}
    void mesg() const;
};

inline void bad_gmean::mesg() const
{
    std::cout << "gmean(" << val1() << ", " << val2() << "):" << std::endl;
    std::cout << "gmean() arguments should be >= 0" << std::endl;
}

#endif