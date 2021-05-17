#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
	char ch;
	int i, j;

	printf("What do you want to printf?\n");
	scanf_s("%c", &ch);
	printf("How many line and list do you want to printf?\n");
	scanf_s("%d %d", &i, &j);
	chline(ch, i, j);
	printf("Bye\n");

	return 0;
}

void chline(char ch, int i, int j)
{
	int count1, count2;

	for (count1 = 0; count1 < i; count1++)
	{
		for (count2 = 0; count2 < j; count2++)
		{
			putchar(ch);
		}
		putchar('\n');
	}
}