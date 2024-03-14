#include <iostream>
#include <cstring>
#define SIZE 50

int main(void)
{
	using namespace std;
	
	cout << "Enter words (to stop, type the word done):\n";
	char words[SIZE] = {0};
	unsigned int sum = 0;
	cin >> words;
	while (strcmp(words, "done"))
	{
		sum++;
		cin >> words;
	}

	cout << "You entered a total of " << sum << " words.\n";

	return 0;
}