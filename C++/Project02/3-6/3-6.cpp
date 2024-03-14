#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter the mile of distance you have driven:";
	double distance;
	cin >> distance;
	cout << "Enter the gallon of gasoline you have used:";
	double gasoline;
	cin >> gasoline;
	cout << "Your car can run " << distance / gasoline << " miles per gallon\n;";

	return 0;
}