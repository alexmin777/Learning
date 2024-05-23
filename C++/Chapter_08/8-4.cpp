#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char * str;
	int ct;
};

void set(stringy &stry, const char * str);
void show(const stringy &stry, int count = 1);
void show(const char *str, int count = 1);

int main()
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

	delete [] beany.str;

	return 0;
}

void set(stringy &stry, const char * str)
{
	stry.str = new char[strlen(str) + 1];

	strcpy(stry.str, str);
	stry.ct = strlen(stry.str) + 1;
}

void show(const stringy &stry, int count)
{
	for (int i = 0; i < count; i++)
		cout << stry.str << endl;
}

void show(const char *str, int count)
{
	for (int i = 0; i < count; i++)
		cout << str << endl;
}