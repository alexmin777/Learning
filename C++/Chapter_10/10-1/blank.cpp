#include "blank.h"

BankAccount::BankAccount(std::string name, std::string account, double deposit)
{
    m_name = name;
    m_account = account;
    m_deposit = deposit;
}

BankAccount::BankAccount()
{
    m_name = "null";
    m_account = "null";
    m_deposit = 0;
}

BankAccount::~BankAccount()
{

}

void BankAccount::show() const
{
    using std::cout;

    cout << m_name << " your account: " << m_account;
    cout << " has " << m_deposit << "money\n";
}

int BankAccount::set_deposit(double value)
{
    if (value <= 0)
    {
        std::cout << "You must deposit a limit greater than 0.\n";
        return -1;
    }

    m_deposit += value;

    return 0;
}

int BankAccount::get_deposit(double value)
{
    if (value <= 0 || value > m_deposit)
    {
        std::cout << "You have to withdraw more than 0 or less than what you deposited.\n";
        return -1;
    }

    m_deposit -= value;

    return 0;
}