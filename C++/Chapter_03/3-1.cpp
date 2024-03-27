#include <iostream>

int main(int argc, char* argv[])
{
	using namespace std;

	const int inch2feet = 12;
	int inch = 0;

	cout << "Please enter your height(inch):____\b\b\b\b";
	cin >> inch;
	cout << "Hey your height is " << inch % inch2feet 
	<< " inches " << inch / inch2feet << " feet" << endl;

	return 0;
}