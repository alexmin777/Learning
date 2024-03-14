#include <iostream>

int main(void)
{
	using namespace std;

	cout << "Enter number of rows: ";
	unsigned int rows;
	cin >> rows;

	for (int i = 0; i < rows; i++)
	{
		for (int k = rows - i; k > 1; k--)
		{
			cout << ".";
		}
		for (int j = 0; j < (i + 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}