#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"
#define LEN 100
int my_atio(char * str);

int main(void)
{
	char origin[LEN];

	puts("Please enter a string (less than 100 words):");
	while (s_gets(origin, LEN) == NULL)
	{
		puts("Please enter not NULL string:");
	}

	printf("The value of string is %d\r\n", my_atio(origin));

	return 0;
}

int my_atio(char* str)
{
	int result = 0;
	int string_size = strlen(str);

	for (int i = 0; i < string_size; i++)
	{
		if (!isdigit(str[i]))
			return 0;
		else
		{
			result = result * 10 + str[i] - '0';
		}
	}

	return result;
}