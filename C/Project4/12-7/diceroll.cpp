#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"

int roll_count = 0;

static int rollen(int sides)
{
	int roll;

	roll = rand() % sides + 1;
	roll_count++;

	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int total = 0;

	if (sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Need at least 1 dice.\n");
		return -1;
	}

	for (int i = 0; i < dice; i++)
		total += rollen(sides);
	return total;
}