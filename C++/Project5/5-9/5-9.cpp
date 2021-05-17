#include <iostream>
#include <string>

int main(void)
{
	using namespace std;

	cout << "Enter words (to stop, type the word done):\n";
	string words = { 0 };
	unsigned int sum = 0;
	cin >> words;
	while (words != "done")
	{
		sum++;
		cin >> words;
	}

	cout << "You entered a total of " << sum << " words.\n";

	return 0;
}