#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string words;
	int count = 0;

	cout << "Enter words: (to stop, type the word done): " << endl;

	while (cin >> words, words != "done")
	{
		count++;
	}

	cout << "You entered a total of " << count << " words." << endl;

	return 0;
}