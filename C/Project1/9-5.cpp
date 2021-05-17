#include <stdio.h>

void larger(double* x, double* y);

int main(void)
{
	double x, y;

	printf("Enter two num(q to quit):\n");
	while (scanf_s("%lf %lf", &x, &y) == 2)
	{
		larger(&x, &y);
		printf("Now there are %lf %lf\n", x, y);
		printf("Enter two num(q to quit):\n");
	}
	printf("Bye\n");
	return 0;
}

void larger(double* x, double* y)
{
	if (*x > *y)
	{
		*y = *x;
	}
	else
	{
		*x = *y;
	}
}