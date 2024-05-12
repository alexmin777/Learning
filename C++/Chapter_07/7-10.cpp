#include <iostream>

typedef double (*func)(double x, double y);

double calculate(double x, double y, func * pf);
double add(double x, double y) {return x + y;}
double sub(double x, double y) {return x - y;}
double multiply(double x, double y) {return x * y;}

const int SIZE = 3;
int main()
{
	using namespace std;

	double x, y, result;
	func pf[SIZE] = {add, sub, multiply};

	cout << "Enter two numbers(q to quit): ";
	while (cin >> x >> y)
	{
		for (int i = 0; i < SIZE; i++)
		{
			result = calculate(x, y, &(pf[i]));
			cout << "Function " << i + 1 << " result: " << result << endl;
			cout << "Next two numbers(q to quit): ";
		}
	}
}

double calculate(double x, double y, func * pf)
{
	return (*pf)(x, y);
}