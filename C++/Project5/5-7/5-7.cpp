#include <iostream>
#include <string>

using namespace std;
struct car {
	string production;
	unsigned int year;
};

int main(void)
{
	unsigned int num;
	
	cout << "How many cars do you wish to catalog? ";
	(cin >> num).get();
	car* pcar = new car[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Car #" << i + 1 << ":\n";
		cout << "Please enter the make: ";
		getline(cin, pcar[i].production);
		cout << "Please enter the year made: ";
		(cin >> pcar[i].year).get();
	}

	cout << "Here is your collection:";
	for (int i = 0; i < num; i++)
		cout << pcar[i].year << " " << pcar[i].production << endl;

	delete [] pcar;
	
	return 0;
}