#include <stdio.h>
#include <limits.h>
#include <string.h>

void value_to_string(unsigned int value, char * str);
void rotate_l(unsigned int value, int move);

int main(void)
{
	unsigned int value, move;

	while ((scanf("%d %d", &value, &move) == 2) && value >= 0 && move >= 0)
	{
		rotate_l(value, move);
		while (getchar() != '\n')
			continue;
		printf("Next the value and move bit(q to quit):\r\n");
	}

	puts("Doen!");
	return 0;
}

void rotate_l(unsigned int value, int move)
{
	int size = CHAR_BIT * sizeof(int);
	char string[CHAR_BIT * sizeof(int) + 1];
	char result[CHAR_BIT * sizeof(int) + 1];

	value_to_string(value, string);
	strncpy(result, string + move, size - move);
	strncpy(result + (CHAR_BIT * sizeof(int) - move), string, move);
	result[CHAR_BIT * sizeof(int)] = '\0';
	printf("Rseult:%s\r\n", result);
}

void value_to_string(unsigned int value, char* str)
{
	int size = CHAR_BIT * sizeof(int);

	for (int i = size - 1; i >= 0; i--, value >>= 1)
		str[i] = (01 & value) + '0';
	str[size] = '\0';
	printf("Orange string:%s\r\n", str);
}