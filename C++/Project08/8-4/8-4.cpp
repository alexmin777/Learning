#include <iostream>
#include <cstring>
using namespace std;

struct stringy {
	char* str;
	int ct;
};

void set(stringy& p, const char* s);
void show(const stringy p, int times = 1);
void show(const char* s, int times = 1);

int main(void)
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
}

void set(stringy& p, const char* s)
{
	p.ct = strlen(s);
	p.str = new char[p.ct + 1];
	strncpy(p.str, s, p.ct + 1);
}

void show(const stringy p, int times)
{
	for (int i = 0; i < times; i++)
		cout << p.str << endl;
}

void show(const char* s, int time)
{
	for (int i = 0; i < time; i++)
		cout << s << endl;
}