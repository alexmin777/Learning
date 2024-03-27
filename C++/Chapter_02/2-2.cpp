#include <iostream>

int main()
{
	using namespace std;

	cout << "Please enter a distance(long):";
	int distance;
	cin >> distance;

	distance *= 220;
	cout << "It's equal to a distance of " << distance << " yards" << endl;

	return 0;
}