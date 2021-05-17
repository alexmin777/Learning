#include <stdio.h>
#include <limits.h>

int open_bit(int value);

int main(void)
{
	int value;

	printf("Please enter the value(q to quit):\r\n");
	while ((scanf("%d", &value) == 1) && value >= 0)
	{
		printf("Open the %d bit\r\n", open_bit(value));
		while (getchar() != '\n')
			continue;
		printf("Please enter the value(q to quit):\r\n");
	}
	puts("Done!");

	return 0;
}

int open_bit(int value)
{
	int count = 0;
	int check;

	for (int i = CHAR_BIT * sizeof(int) - 1; i >= 0; i--, value >>= 1)
	{
		if (check = (01 & value))
			count++;
	}

	return count;
}