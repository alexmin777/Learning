#include <stdio.h>

int max(const int[], int);
int main(void)
{
	int maximum = 0;
	int array[5] = { 1, 1, 2, 5, 5 };

	maximum = max(array, 5);
	printf("maximum is :%d\r\n", maximum);
}

int max(const int array[], int parameter)
{
	int max = array[0];
	int current;
	int i;
	for (i = 0; i < parameter; i++)
	{
		current = array[i];
		if (current > max)
			max = current;
	}
	return max;
}