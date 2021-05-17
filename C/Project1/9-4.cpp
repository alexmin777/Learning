#include <stdio.h>

double harmean(double x, double y);

int main(void)
{
	double x, y, result;

	printf("Please to enter two num to Calculate(q to quit):\n");
	while (scanf_s("%lf %lf", &x, &y) == 2)
	{
		result = harmean(x, y);
		printf("result: %lf\n", result);
		printf("Please to enter two num to Calculate(q to quit):\n");
	}
	printf("Bye!\n");
	return 0;
}

double harmean(double x, double y)
{
	double average, reciprocal;

	average = (1 / x + 1 / y) / 2;
	reciprocal = 1 / average;
	return reciprocal;
}