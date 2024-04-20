#include <iostream>
#include <cctype>

int main()
{
	using namespace std;

	char ch;

	cout << "Type, and I shall repeat(@ to quit)." << endl;
	while ((ch = cin.get()) != '@')
	{
		ch = islower(ch) ? toupper(ch) : tolower(ch);
		if (!isdigit(ch))
			cout.put(ch);
	}

	return 0;
}