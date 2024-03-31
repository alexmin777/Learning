#include <iostream>

int main()
{
	using namespace std;

	int min, max;
	long sum = 0;

	cout << "Please enter minimum value: ";
	cin >> min;
	cout << "Please enter maximum value: ";
	cin >> max;

	for (; min < max + 1; min++)
		sum += min;
	
	cout << "The sum is " << sum << endl;

	return 0;
}