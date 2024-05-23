#include <iostream>

void show(const char * str, unsigned int times = 0);

int main()
{
	char str[10] = "Hello!";

	show(str);
	show(str, 0);
	show(str, 1);
	show(str, 2);
	show(str, 3);
	show(str, 4);

	return 0;
}

void show(const char * str, unsigned int times)
{
	using namespace std;

	static unsigned int count = 0;

	if (0 != times)
		count++;
	
	cout << "This call print " << count << " times" << endl;
	for (int i = 0; i < count; i++)
		cout << str << endl;
}