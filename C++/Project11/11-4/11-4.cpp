#include <iostream>
#include "mytime.h"

int main(void)
{
	using namespace std;
	Time A;
	Time B(5, 40);
	Time C(2, 55);

	cout << "A, B, and C:\n";
	cout << A << "; " << B << ": " << C << endl;
	A = B + C;
	cout << "B + C: " << A << endl;
	A = B * 2.75; // member operator*()
	cout << "B * 2.75: " << A << endl;
	cout << "10 * B: " << 10 * B << endl;

	return 0;
}