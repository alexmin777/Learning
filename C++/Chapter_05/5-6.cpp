#include <iostream>
#include <string>

const int Year2mounth = 12;
const int Count2year = 3;

int main()
{
	using namespace std;

	string years[Count2year] = { "first", "second", "third"};
	string mounth[Year2mounth] = { "Jan", "Feb", "Mar", "Apr", "May", 
			"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	long sales[Count2year][Year2mounth] = {0};
	long total = 0;

	for (int i = 0; i < Count2year; i++)
	{
		for (int j = 0; j < Year2mounth; j++)
		{
			cout << years[i] << " year ";
			cout << mounth[j] << " sale :";
			cin >> sales[i][j];
			total += sales[i][j];
		}
	}
	cout << "Total: " << total << endl;

	return 0;
}