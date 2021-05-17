#include <stdio.h>

void sort(double* x, double* y, double* z);

int main(void)
{
	double x, y, z;

	printf("Enter three number(q to quit):\n");
	while ((scanf_s("%lf %lf %lf", &x, &y, &z)) == 3)
	{
		sort(&x, &y, &z);
		printf("Ranking from small to large %lf %lf %lf", x, y, z);
		printf("Enter three number(q to quit):\n");
	}
	printf("Bye!\n");
	return 0;
}

void sort(double* x, double* y, double* z)
{
	double temp1, temp2;

	if (*x > *y && *x > *z)
	{
		if (*y > *z)
		{
			temp1 = *x;
			*x = *z;
			*z = temp1;
		}
		else
		{
			temp1 = *x;
			temp2 = *z;
			*x = *y;
			*y = temp2;
			*z = temp1;
		}
	}
	else if(*x < *y && *x < *z)
	{
		if (*y < *z)
		{
			return;
		}
		else
		{
			temp1 = *y;
			*y = *z;
			*z = temp1;
		}
	}
	else if (*x < *y && *x > *z)
	{
		temp1 = *y;
		*y = *x;
		*x = *z;
		*z = temp1;
	}
	else
	{
		temp1 = *y;
		*y = *x;
		*x = temp1;
	}
}