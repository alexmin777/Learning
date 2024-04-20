#include <iostream>
#include <string>
#include <cctype>

int main()
{
	using namespace std;

	char ch;
	int vowels = 0;
	int consonants = 0;
	int others = 0;
	string words;

	cout << "Enter words (q to quit):" << endl;
	while(cin.get(ch) && ch != 'q')
	{
		if (isalpha(ch))
		{
			switch (ch)
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowels++;
					while (!isalpha(ch))
						cin.get();
					break;
				default:
					consonants++;
					while (!isalpha(ch))
						cin.get();
					break;
			}
		}
		else
			others++;
	}

	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words ending with consonants" << endl;
	cout << others << " others" << endl;

	return 0;
}