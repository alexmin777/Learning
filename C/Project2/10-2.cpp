#include <stdio.h>

void copy_arr(double*, double*, int);
void copy_ptr(double*, double*, int);
void copy_ptrs(double*, double*, double *);
int main(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	int i;

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);
	printf("target1		target2		target3\r\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5lf %5lf %5lf\r\n", target1[i], target2[i], target3[i]);
	}
	printf("End!\r\n");
	return 0;
}

void copy_arr(double target1[], double source[], int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		target1[i] = source[i];
	}
}

void copy_ptr(double target2[], double source[], int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		*(target2 + i) = *(source + i);
	}
}

void copy_ptrs(double target3[], double source[], double count[])
{
	int i;

	for (i = 0; i < count - source; i++)
	{
		*(target3 + i) = *(source + i);
	}
}