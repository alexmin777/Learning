#include <iostream>
//#include <array>
#include <vector>

int main(void)
{
	using namespace std;

	//array<double, 3> result;
	vector<double> result(3);

	cout << "Please enter your result, ";
	cout << "The first result: ";
	cin >> result[0];
	cout << "The second result: ";
	cin >> result[1];
	cout << "The third result: ";
	cin >> result[2];

	cout << "Your result average is " << (result[0] + result[1] + result[2]) / 3 << endl;

	return 0;
}