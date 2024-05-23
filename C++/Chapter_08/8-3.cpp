#include <iostream>
#include <cctype>
#include <string>

void capitalize(std::string &str);

int main()
{
	using namespace std;

	string source;

	cout << "Enter a string (q to quit):";
	while (getline(cin, source) && source != "q")
	{
		capitalize(source);
		cout << source << endl;
		cout << "Next string (q to quit):";
	};

	cout << "Bye.";

	return 0;
}

void capitalize(std::string &str)
{
	int i = 0;

	while (str[i] != '\n')
	{
		str[i] = toupper(str[i]);
		i++;
	}
}