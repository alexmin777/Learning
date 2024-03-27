#include <iostream>

const int day2hour = 24;
const int hour2min = 60;
const int min2sec = 60;

int main()
{
	using namespace std;

	long seconds;
	int days, hours, minutes, reset;

	cout << "Enter the number of seconds: ";
	cin >> seconds;

	days = seconds / (day2hour * hour2min * hour2min);
	reset = seconds % (day2hour * hour2min * hour2min);
	hours = reset / (hour2min * min2sec);
	reset = reset % (hour2min * min2sec);
	minutes = reset / min2sec;
	reset = reset % min2sec;

	cout << seconds << " seconds = "
		<< days << " days, "
		<< hours << " hours, "
		<< minutes << " minutes, "
		<< reset << " seconds" << endl;

	return 0;
}