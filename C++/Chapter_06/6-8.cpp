#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

	ifstream file;
	char ch;
	int count = 0;
	string filename;

	cout << "Please enter name of data file: ";
	getline(cin, filename);
	file.open(filename);
	if (!file.is_open())
	{
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);		
	}

	while(file >> ch && file.good())
	{
		count++;
		cout.put(ch);
	}
	cout << endl;

    if (count > 0)
    {
        cout << count << " characters in the file " << filename << endl;
    }
    else
    {
        cout << "No data processed." << endl;
    }

	file.close();

	return 0;
}