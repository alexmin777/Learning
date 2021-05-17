#include <iostream>

using namespace std;
void showtime(int, int);

int main(void)
{
	cout << "Enter the number of hours: ";
	int hour;
	cin >> hour;
	cout << "Enter the number of minutes: ";
	int minutes;
	cin >> minutes;
	showtime(hour, minutes);
	
	return 0;
}

void showtime(int hour, int minutes)
{
	cout << "Time: " << hour << ":" << minutes << endl;
}