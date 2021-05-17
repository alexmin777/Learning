#ifndef BANK_H_
#define BANK_H_

class BankAccount {
private:
	char name[40];
	char acctnum[25];
	double balance;
public:
	BankAccount(const char* client = "no one", const char* num = "0", double bal = 0.0);
	~BankAccount() { };
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};

#endif // !BANK_H_
