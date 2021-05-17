#include <iostream>
#include <cstring>
#include "stock.h"
using std::cout;

Stock::Stock()
{
	company = new char[m_default];
	strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
{
	company = new char[strlen(co) + 1];
	strcpy(company, co);

	if (n < 0)
	{
		cout << "Number of shares can'y be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock(const Stock& s)
{
	company = new char[strlen(s.company) + 1];
	strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	set_tot();
}

Stock::~Stock()
{
	delete[] company;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative."
			<< "Transcaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative."
			<< "Transcaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transcaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::updata(double price)
{
	share_val = price;
	set_tot();
}

const Stock& Stock::topval(const Stock& s)const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

Stock& Stock::operator=(const Stock& s)
{
	if (this == &s)
		return *this;
	delete[] company;
	company = new char[strlen(s.company) + 1];
	strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	set_tot();
}

std::ostream& operator<<(std::ostream &os, const Stock& s)
{
	os << "Company: " << s.company
		<< " Shares: " << s.shares << '\n'
		<< " Share Price: $" << s.share_val
		<< " Total Worth: $" << s.total_val << '\n';
	return os;

}