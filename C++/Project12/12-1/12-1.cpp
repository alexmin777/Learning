#include "example.h"
#include <iostream>

int main(void)
{
	using namespace std;

	Cow hostest;
	Cow guest("Divine", "chewing cud", 880);
	hostest.ShowCow();
	guest.ShowCow();
	Cow copy(guest);
	guest = hostest;
	guest.ShowCow();
	copy.ShowCow();

	return 0;
}