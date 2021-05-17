#include <stdio.h>
#include <math.h>
#define MAX	 100
#define NUM 4

double twice(double x);
double half(double x);
void transform(const double source[], double target[], int count, double (*sin)(double x));
void check(double datas[], int count);

int main(void)
{
	double source[MAX];
	double target[MAX];
	int count = 0;
	int choose;
	double (*fp[NUM])(double x) = {twice, half, sqrt, cbrt};

	printf("Please enter the data to calc(q to quit):\r\n");
	while ((scanf("%lf", &source[count]) == 1) && count < MAX)
	{
		printf("Next data(q to quit):\r\n");
		count++;
	}
	check(source, count);

	for (int i = 0; i < NUM; i++)
	{
		transform(source, target, count, fp[i]);
		check(target, count);
	}

	puts("Bye");
	return 0;
}

void check(double datas[], int count)
{
	printf("Check datas: ");
	for (int i = 0; i < count; i++)
		printf("%lf ", datas[i]);
	printf("\r\n");
}

double twice(double x)
{
	return 2.0 * x;
}

double half(double x)
{
	return x / 2.0;
}

void transform(const double source[], double target[], int count, double (*sin)(double x))
{
	for (int i = 0; i < count; i++)
		target[i] = sin(source[i]);
}