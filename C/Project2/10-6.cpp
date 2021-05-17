#include <stdio.h>
#define LEN 10

void show_ar(double ar[], int len);
void sort_ar(double ar[], int len);

int main(void)
{
	double array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	show_ar(array, LEN);
	sort_ar(array, LEN);
	show_ar(array, LEN);
	printf("Done!\r\n");
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

void sort_ar(double ar[], int len)
{
	int i;
	double sort;

	for (i = 0; i < len / 2; i++)
	{
		sort = ar[i];
		ar[i] = ar[len - 1 - i];
		ar[len - 1 - i] = sort;
	}

}