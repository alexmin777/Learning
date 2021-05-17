#include <iostream>
#include "port.h"

int main(void)
{
	using namespace std;
	Port usual("Mr. Porto", "Ruby", 100);
	VintagePort special("Bainscotts", 14, "The Bold", 1963);

	cout << usual << endl;
	cout << special << endl;
	special -= 2;
	cout << special << endl;
	std::cin.get();
	return 0;
}