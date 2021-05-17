#include <stdio.h>
#include <stdbool.h>
#define ROW 3
#define LINE 5

bool enter(double source[][LINE], int row);
double group_average(double source[], int line);
double all_average(double source[][LINE], int row);
double max_data(double source[][LINE], int row);

int main(void)
{
	bool judge;
	double origin[ROW][LINE];
	int i;
	double group, all, max;

	if (enter(origin, ROW))
	{
		printf("enter error!\r\n");
		return 0;
	}

	for (i = 0; i < ROW; i++)
	{
		group = group_average(origin[i], LINE);
		printf("group%d:%lf\r\n",i, group);
	}

	all = all_average(origin, ROW);
	printf("all:%lf\r\n", all);

	max = max_data(origin, ROW);
	printf("max:%lf\r\n", max);

	return 0;
}

bool enter(double source[][LINE], int row)
{
	int x, y;
	printf("Please enter 3*5 datas:\r\n");
	for (x = 0; x < row; x++)
	{
		printf("Data%dx:\r\n", x);
		for (y = 0; y < LINE; y++)
			scanf_s("%lf", &source[x][y]);
	}
	return 0;


}

double group_average(double source[], int line)
{
	int i;
	double total = 0;

	for (i = 0; i < line; i++)
		total += source[i];

	return total / line;
}

 double all_average(double source[][LINE], int row)
{
	int x, y;
	double total = 0;

	for (x = 0; x < row; x++)
		for (y = 0; y < LINE; y++)
			total += source[x][y];

	return (total / (ROW * LINE));
}

 double max_data(double source[][LINE], int row)
 {
	 int x, y;
	 double max = source[0][0];

	 for (x = 0; x < row; x++)
		 for (y = 0; y < LINE; y++)
			 if (max < source[x][y])
				 max = source[x][y];

	 return max;
 }