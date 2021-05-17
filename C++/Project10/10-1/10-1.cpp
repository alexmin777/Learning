#include <iostream>
#include "bank.h"

int main(void)
{
	BankAccount bird;
	BankAccount frog("Kermit", "croak322", 123.00);

	bird.show();
	frog.show();
	bird = BankAccount("Chipper", "peep8282", 214.00);
	bird.show();
	frog.deposit(20);
	frog.show();
	frog.withdraw(4000);
	frog.show();
	frog.withdraw(50);
	frog.show();

	return 0;
}