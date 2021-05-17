#include <iostream>

using namespace std;

void show1(void);
void show2(void);

int main(void)
{
	show1();
	show1();
	show2();
	show2();

	return 0;
}

void show1(void)
{
	cout << "Three blind mice" << endl;
}

void show2(void)
{
	cout << "See how they run" << endl;
}