#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "diceroll.h"

int main(void)
{
	int dice, count, roll;
	int sides;
	int set, sets;

	srand((unsigned int)time(0));
	printf("Enter the number of sets; enter q to stop: ");
	while (scanf_s("%d", &sets) == 1)
	{
		printf("How many sides and how many dice?  ");
		if (scanf_s("%d %d", &sides, &dice) != 2)
		{
			puts("not integers -- terminating input loop.");
			break;
		}
		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);

		for (set = 0; set < sets; set++)
		{
			count = roll_n_dice(dice, sides);
			printf("%4d", count);
			if (set % 15 == 14)
				putchar('\n');
		}
		if (set % 15 != 0)
			putchar('\n');
		printf("Enter the number of sets; enter q to stop: ");
	}
	return 0;
}