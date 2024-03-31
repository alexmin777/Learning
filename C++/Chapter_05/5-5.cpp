#include <iostream>
#include <string>

const int Year2mounth = 12;

int main()
{
	using namespace std;

	string mounth[Year2mounth] = { "Jan", "Feb", "Mar", "Apr", "May", 
			"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	long sales[Year2mounth] = {0};
	long total = 0;

	for (int i = 0; i < Year2mounth; i++)
	{
		cout << mounth[i] << " sale :";
		cin >> sales[i];
		total += sales[i];
	}
	cout << "Total: " << total << endl;

	return 0;
}