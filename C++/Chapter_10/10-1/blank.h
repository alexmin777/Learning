#ifndef __BLANK_H_
#define __BLANK_H_

#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string m_name;
    std::string m_account;
    double m_deposit;
public:
    BankAccount(std::string name, std::string account, double deposit);
    BankAccount();
    ~BankAccount();
    void show() const;
    int set_deposit(double value);
    int get_deposit(double value);
};

#endif // __BLANK_H_