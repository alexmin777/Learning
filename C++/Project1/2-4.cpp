#include <iostream>

int year_to_month(int n);

int main(void)
{
	using namespace std;

	cout << "Enter your age:";
	int ages;
	cin >> ages;
	int months = year_to_month(ages);
	cout << "You have alived " << months << " months";

	return 0;
}

int year_to_month(int n)
{
	return n * 12;
}