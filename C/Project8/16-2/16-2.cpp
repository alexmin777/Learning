#include <stdio.h>

#define AVERAGE(X ,Y) (1 / (((1/X) + (1/Y)) / 2))

int main(void)
{
	double x, y;
	
	printf("Please enter two value(q to quit):\n");
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The %lf and %lf average value is %lf\n", x, y, AVERAGE(x, y));
		printf("Please enter two value(q to quit):\n");
	}

	puts("Bye");
	return 0;
}