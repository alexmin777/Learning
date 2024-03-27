#include <iostream>

int main(void)
{
	using namespace std;

	cout << "Enter your age:";
	int ages; 
	cin >> ages;

	int months = ages * 12;

	cout << "You went through " << months << " months" << endl;

	return 0;
}