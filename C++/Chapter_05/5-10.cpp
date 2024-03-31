#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;

	int rows;

	cout << "Enter number of rows: ";
	cin >> rows;

	clock_t start = clock();
	char *display = new char[rows];

	memset(display, '.', sizeof(char) * rows);
	for (int i = 0; i < rows; i++)
	{
		display[rows - 1 - i] = '*';
		cout << display << endl;
	}

	delete[] display;

	clock_t end = clock();
	
	cout << "cost: " << end - start << endl;

	return 0;
}
