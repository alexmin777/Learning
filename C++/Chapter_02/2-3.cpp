#include <iostream>

using namespace std;

void mice(void);
void show(void);

int main()
{
	mice();
	mice();
	show();
	show();

	return 0;
}

void mice(void)
{
	cout << "Three blind mice" << endl;
}

void show(void)
{
	cout << "See how they run" << endl;
}