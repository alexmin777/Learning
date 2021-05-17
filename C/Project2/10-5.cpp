#include <stdio.h>
#define LEN 10

void show_ar(double ar[], int len);
double disparity(double ar[], int len);

int main(void)
{
	double  orig[LEN] = { 1.1,2,3,4,12,61.3,7,8,9,10 };
	double gap = 0;

	show_ar(orig, LEN);
	gap = disparity(orig, LEN);
	printf("The max - min = %lf\r\n", gap);
	return 0;
}

void show_ar(double ar[], int len)
{
	int i;

	printf("array:");
	for (i = 0; i < len; i++)
	{
		printf("%lf	", ar[i]);
	}
	printf("\r\n");
}

double disparity(double ar[], int len)
{
	double diff = 0;
	int i;
	double max, min;
	max = min = ar[0];
	for (i = 0; i < len; i++)
	{
		if (ar[i] > max)
			max = ar[i];
		else if(ar[i] < min)
			min = ar[i];
	}
	return (max - min);

}