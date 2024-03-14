#include <iostream>
#include <fstream>
#include <cstdlib>
#define SIZE	60
int main(void)
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile;
	char ch;
	
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	int count = 0;

	while (inFile >> ch)
	{
		cout << ch;
		count++;
	}
	cout << count << " characters in " << filename << endl;

	inFile.close();

	return 0;
}