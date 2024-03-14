#include <iostream>
const int foot_to_inch = 12;
int main()
{
	using namespace std;
	
	cout << "Please enter your height in inches:___\b\b\b ";
	int heigh;
	cin >> heigh;
	int heigh_inch = heigh / foot_to_inch;
	int last_foot = heigh % foot_to_inch;
	cout << "Your heigh is " << heigh_inch << " inch " << last_foot << " foot " << endl;

	return 0;
}