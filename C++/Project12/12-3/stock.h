#ifndef STOCK_H_
#define STOCK_H_
#include <iostream>

class Stock {
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
	const int m_default = 10;
public:
	Stock();
	Stock(const char* co, long n = 0, double pr = 0.0);
	Stock(const Stock& s);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void updata(double price);
	const Stock& topval(const Stock& s)const;
	Stock& operator=(const Stock& s);
	//friendly
	friend std::ostream& operator<<(std::ostream &os, const Stock& s);
};
#endif // !STOCK_H_
