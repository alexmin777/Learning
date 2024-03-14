#include <iostream>
#include <ctype.h>

int main(void)
{
	using namespace std;
	char ch;
	cout << "Please enter someting (@ to quit):";

	while ((ch = cin.get()) != '@')
	{
		cout << ch;
		if (!isdigit(ch))
		{
			if (islower(ch))
				ch = toupper(ch);
			else if (isupper(ch))
				ch = tolower(ch);
			cout << ch;
		}
	}
	while (cin.get() != '\n')
		continue;

	return 0;
}