#include <iostream>
#include <string>

#define MONTHS 12
void display(const int num[], const int total);

using namespace std;
string months[MONTHS] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
int main(void)
{
	int num[MONTHS] = { 0 };
	int total = 0;

	for (int i = 0; i < MONTHS; i++)
	{
		cout << "Please enter " << months[i] << " number: ";
		cin >> num[i];
		total += num[i];
	}

	display(num, total);
	
	return 0;
}

void display(const int num[], const int total)
{
	for (int i = 0; i < MONTHS; i++)
	{
		cout << months[i] << " sell: " << num[i] << endl;
	}
	cout << "Total sell: " << total << endl;
}