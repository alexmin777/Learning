#include "blank.h"

int main()
{
    BankAccount account("mjl", "alex", 100);

    account.show();
    account.set_deposit(50);
    account.get_deposit(10);
    account.show();

    BankAccount account_default;
    account_default.show();
    account_default.set_deposit(50);
    account_default.get_deposit(10);
    account_default.show();

    return 0;
}