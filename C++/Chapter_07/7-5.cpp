#include <iostream>

long long factorial(int n);

int main()
{
	using namespace std;

	int n;

	cout << "Enter the number, and clac it's factor(q to quit):";

	while (cin >> n)
	{
		cout << "The " << n << "'s factor is " << factorial(n) << endl;
		cout << "Next number(q to quit):";
	}

	return 0;
}

long long factorial(int n)
{
	if (0 == n)
		return 1;
	
	if (n > 0)
	{
		n *= factorial(n - 1 );
	}

	return n;
}