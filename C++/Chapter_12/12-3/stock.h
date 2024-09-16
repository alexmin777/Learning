#ifndef __STOCK_H__
#define __STOCK_H__

#include <iostream>

class Stock {
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();
    Stock(const char * co, long n = 0, double per = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;
//friend
    friend std::ostream & operator<<(std::ostream & os, const Stock & s);
};

#endif  /* __STOCK_H__ */
