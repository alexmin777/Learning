#include <iostream>
#include "pellston6.h"

const int STAFF = 6;
int main(void)
{
	using namespace std;
	
	Stonewt sales[STAFF] = {
	 Stonewt(12, 4),
	 Stonewt(10,6),
	 Stonewt(9, 4)
	};
	double pounds;
	cout << "Enter the weight, in pounds, of the next "
		<< "3 staff members:\n";
	int i;
	for (i = 3; i < STAFF; i++)
	{
		cout << "#" << i - 2 << ": ";
		cin >> pounds;
		sales[i] = pounds;
	}
	cout << "Staff weights:\n";
	for (i = 0; i < STAFF; i++)
		sales[i].show_stn();
	Stonewt min = sales[0];
	Stonewt max = sales[0];
	Stonewt ref11(11, 0);
	int ct11 = 0;
	for (i = 0; i < STAFF; i++)
	{
		if (sales[i] < min)
			min = sales[i];
		if (sales[i] > max)
			max = sales[i];
		if (sales[i] > ref11)
			ct11++;
	}
	cout << "Largest and smallest weights:\n";
	max.show_stn();
	min.show_stn();
	cout << "11 stone and over: " << ct11 << endl;

	return 0;
}