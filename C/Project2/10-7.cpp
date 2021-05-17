#include <stdio.h>

void copy_ptr(double source[][3], double target[][3], int index);
void show_array(double target[][3], int index);

int main(void)
{
	double source[2][3] = { {1.1, 2.2, 3.3}, {4.4, 5.5, 6.6} };
	double target[2][3];
	
	copy_ptr(source, target, 2);
	show_array(target, 2);
	return 0;
}

void copy_ptr(double source[][3], double target[][3], int index)
{
	int x, y;

	for (x = 0; x < index; x++)
	{
		for (y = 0; y < 3; y++)
		{
			target[x][y] = source[x][y];
		}
	}
}

void show_array(double target[][3], int index)
{
	int x, y;

	printf("target:");
	for (x = 0; x < index; x++)
	{
		for (y = 0; y < 3; y++)
		{
			printf("%lf	", target[x][y]);
		}
	}
	printf("\r\n");
}