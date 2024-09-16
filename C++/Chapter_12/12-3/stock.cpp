#include <iostream>
#include "stock.h"

Stock::Stock()
{
    company = new char[1];
    company[0] = '\0';
    shares = 0;
    share_val = 0.0;
    set_tot();
}

Stock::Stock(const char * co, long n, double per)
{
    company = new char[strlen(co) + 1];
    strcpy(company, co);
    if (n < 0) {
        std::cout << "Number of shares can't be negative; "
                    << company << " shares set to 0.\n";
        shares = 0; 
    } else {
        shares = n;
    }
    share_val = per;
    set_tot();
}

Stock::~Stock()
{
    delete [] company;
}

void Stock::buy(long num, double price)
{
    if (num < 0 ) {
        std::cout << "Number of shares purchased can't be negative. "
                    << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0 ) {
        std::cout << "Number of shares purchased can't be negative. "
                    << "Transaction is aborted.\n";
    } else if (num > shares) {
        std::cout << "You can't sell more shares than you have! "
                    << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    os << "Company: " << s.company
        << " Shares: " << s.shares << '\n';
    os << " Share Price: $" << s.share_val;

    //set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << s.total_val;

    //restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);

    return os;
}