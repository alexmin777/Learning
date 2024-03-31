#include <iostream>

int main()
{
	using namespace std;

	int num;
	double sum = 0;

	cout << "Please enetr the num(0 to stop): ";
	cin >> num;
	while (num != 0) 
	{
		sum += num;
		cin >> num;
	}

	cout << "Sum: " << sum << endl;

	return 0;
}