#include <iostream>

const int hours_per_day = 24;
const int minutes_per_hour = 60;
const int seconds_per_minute = 60;

int main(void)
{
	using namespace std;
	cout << "Enter the number of seconds:";
	long seconds;
	cin >> seconds;
	int day, hour, minute, second;
	day = seconds / (hours_per_day * minutes_per_hour * seconds_per_minute);
	hour = (seconds / (minutes_per_hour * seconds_per_minute)) % hours_per_day;
	minute = (seconds / seconds_per_minute) % minutes_per_hour;
	second = seconds % seconds_per_minute;
	cout << seconds << " seconds = " << day << " days, " << hour << " hours, " << minute << " minutes, "
		<< second << " seconds\n";

	return 0;
}