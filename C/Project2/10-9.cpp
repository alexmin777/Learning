#include <stdio.h>
#define LEN1 3
#define LEN2 5

void copy_2darray(const double source[][LEN2], double target[][LEN2], int length);
void show_2darray(const double source[][LEN2], int length);

int main(void)
{
	const double origin[LEN1][LEN2] = {
		{12.3, 32.1, 31.2, 677.6, 325.6},
		{23.1, 568.2, 23.5, 32.4, 88.67},
		{235.8, 64.5, 645.23, 2.3, 23.5}
	};
	double target[LEN1][LEN2];
	int i;

	for (i = 0; i < LEN1; i++)
		copy_2darray(origin, target, i);

	printf("origin:");
	for (i = 0; i < LEN1; i++)
		show_2darray(origin, i);
	printf("\r\n");

	printf("target:");
	for (i = 0; i < LEN1; i++)
		show_2darray(target, i);
	printf("\r\n");

	return 0;
}

void copy_2darray(const double source[][LEN2], double target[][LEN2], int length)
{
	int i;

	for (i = 0; i < LEN2; i++)
		target[length][i] = source[length][i];
}

void show_2darray(const double source[][LEN2], int length)
{
	int i;
	for (i = 0; i < LEN2; i++)
		printf("%lf	", source[length][i]);
}
