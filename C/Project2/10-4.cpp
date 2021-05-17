#include <stdio.h>
#define LENGTH 5

int max(double *, int);
void show_array(double *, int);
int main(void)
{
	int index = 0;
	double array[LENGTH] = { 1.1, 10.1, 3.3, 4.4, 5.5 };

	show_array(array, LENGTH);
	index = max(array, LENGTH);
	printf("The max index = %d\r\n", index);
	return 0;
}

void show_array(double array1[], int length)
{
	int i;

	printf("arrar:");
	for (i = 0; i < length; i++)
	{
		printf("%lf	", array1[i]);
	}
	printf("\r\n");
}

int max(double array2[], int length)
{
	double max = array2[0];
	int i;
	int flag = 0;

	for (i = 0; i < length; i++)
	{
		if (array2[i] > max)
		{
			max = array2[i];
			flag = i;
		}
	}
	return flag;
}