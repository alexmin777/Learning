#include <iostream>

int main(void)
{
	using namespace std;

	int total = 0;
	int num;

	cout << "Please enter the num: ";
	cin >> num;
	while (num != 0)
	{
		total += num;
		cout << "Please enter the next num(0 to quit): ";
		cin >> num;
	}
	cout << "Total = " << total << endl;

	return 0;
}