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
	while(cin >> words && words != "q")
	{
		if (isalpha(words[0]))
		{
			switch (tolower(words[0]))
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowels++;
					break;
				default:
					consonants++;
			}
			cin.get();
		}
		else
			others++;
	}

	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words ending with consonants" << endl;
	cout << others << " others" << endl;

	return 0;
}