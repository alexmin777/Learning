#include <iostream>
#include <cstring>

const int Size = 50;
int main()
{
	using namespace std;

	char *words = new char[Size];
	int count = 0;

	cout << "Enter words: (to stop, type the word done): " << endl;

	while (cin >> words, strcmp("done", words))
	{
		count++;
	}

	cout << "You entered a total of " << count << " words." << endl;

	return 0;
}