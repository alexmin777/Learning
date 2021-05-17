#include <stdio.h>
#define ROWS 3
#define COLS 5

void ride2(int source[][COLS], int row);
void show_ride2(const int source[][COLS], int row);

int main(void)
{
	int stuff[ROWS][COLS] = {
		{1,2,3,4,5},
		{6,7,8,-2,10},
		{11,12,13,14,15}
	};
	int i;
	
	for (i = 0; i < ROWS; i++)
		ride2(stuff, i);
	printf("show_ride2");
	for (i = 0; i < ROWS; i++)
		show_ride2(stuff, i);
	printf("\r\n");

	return 0;
}

void ride2(int source[][COLS], int row)
{
	int i;
	for (i = 0 ; i < COLS; i++)
		source[row][i] *= 2;
}

void show_ride2(const int source[][COLS], int row)
{
	int i;
	for (i = 0; i < COLS; i++)
		printf("%d	", source[row][i]);
}