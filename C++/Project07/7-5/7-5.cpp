#include <iostream>

double rfact(int n);

int main(void)
{
	using namespace std;
	double result = 0;
	int n;

	cout << "Please enter the num to calc(q to quit):";
	while (cin >> n && n >= 0)
	{
		result = rfact(n);
		cout << n << "! = " << result << endl;
		cout << "Next(q to quit): ";
	}
	cout << "Bye!\n";

	return 0;
}

double rfact(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * rfact(n - 1);
}