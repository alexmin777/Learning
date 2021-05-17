#include <iostream>
#include <string>
#include <cstring>

class Person {
private:
	static const int LIMIT = 25;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; };
	Person(const std::string& ln, const char* fn = "Heyyou");
	void Show() const;
	void FormalShow() const;
};

Person::Person(const std::string& ln, const char* fn)
{
	lname = ln;
	std::strncpy(fname, fn, LIMIT - 1);
	fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
	std::cout << fname << ' ' << lname;
}

void Person::FormalShow() const
{
	std::cout << lname << ", " << fname;
}

int main(void)
{
	using std::cout;
	using std::endl;
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;
	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;
	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;

	return 0;
}