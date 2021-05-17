#include <iostream>

double long_to_code(double n);

int main(void)
{
	using namespace std;

	cout << "Please enter how many long:" << endl;
	double distance;
	cin >> distance;
	double code = long_to_code(distance);
	cout << distance << " long is equal to " << code << " code." << endl;

	return 0;
}

double long_to_code(double n)
{
	return n * 220;
}