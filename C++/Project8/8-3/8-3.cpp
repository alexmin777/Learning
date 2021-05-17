#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void upper_str(string & str);

int main(void)
{
	string original;
	
	cout << "Enter a string (q to quit): ";
	while (getline(cin, original) && original != "q")
	{
		upper_str(original);
		cout << original << endl;
		cout << "Next string (q to quit): ";
	}
	cout << "Bye.\n";

	return 0;
}

void upper_str(string& str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
}