#include <iostream>

const int degree_to_min = 60;
const int min_to_second = 60;

int main(void)
{
	using namespace std;

	cout << "Enter a latitude in degress, minutes, and second:\n";
	cout << "First, enter the degrees:";
	int degrees;
	cin >> degrees;
	cout << "Next, enter the minutes of arc:";
	int arc;
	cin >> arc;
	cout << "Finally, enter the seconds of arc:";
	int second;
	cin >> second;
	double total_degrees = (double)degrees + (double)arc / degree_to_min + (double)second / min_to_second / degree_to_min;
	cout << degrees << " degrees, " << arc << " minutes, " << second << " seconds = " \
		<< total_degrees << " degrees\n";
	
	return 0;
}