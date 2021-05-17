#include <iostream>
#include <string>

#define MONTHS 12
#define YEAR 3
void display(const int num[][MONTHS], const int total, int year);

using namespace std;
string months[MONTHS] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
string year[YEAR] = { "First year", "Second year", "Third year" };
int main(void)
{
	int num[YEAR][MONTHS] = { 0 };
	int total = 0;

	for (int j = 0; j < YEAR; j++)
	{
		cout << "The " << year[j] << " :\n";
		for (int i = 0; i < MONTHS; i++)
		{
			cout << "Please enter " << months[i] << " number: ";
			cin >> num[j][i];
			total += num[j][i];
		}
	}

	for (int j = 0; j < YEAR; j++)
	{
		cout << "The " << year[j] << " :\n";
		display(num, total, YEAR);
	}
	return 0;
}

void display(const int num[][MONTHS], const int total, int years)
{
	for (int j = 0; j < years; j++)
	{
		cout << "The " << year[j] << " :\n";
		for (int i = 0; i < MONTHS; i++)
		{
			cout << months[i] << " sell: " << num[j][i] << endl;
		}
	}
	cout << "Total sell: " << total << endl;
}