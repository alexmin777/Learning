#include <iostream>
#include <cctype>
#include <string>

int main(void)
{
	using namespace std;
	string word;
	char ch;
	int vowel = 0;
	int consonant = 0;
	int other = 0;
	cout << "Enter words (q to quit):\n";
	
	while ((cin >> word) && (word != "q"))
	{
		ch = tolower(word[0]);
		if (isalpha(ch))
		{
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
				vowel++;
			else
				consonant++;
		}
		else
			other++;
	}
	cout << vowel << " words beginning with vowels\n";
	cout << consonant << " words beginning with consonants\n";
	cout << other << " others\n";

	return 0;
}