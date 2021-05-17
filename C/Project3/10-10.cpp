#include <stdio.h>
#include <string.h>
#include "inputs.h"
#define LEN 100

void remove_blank(char* input);

int main(void)
{
	char origin[LEN];

	puts("Please enter a origin string (less than 100 words):");
	while (s_gets(origin, LEN) && origin[0] != '\0')
	{
		remove_blank(origin);
		puts(origin);
		puts("Next origin string(less than 100 words):");
	}

	puts("Done!");

	return 0;
}

void remove_blank(char* input)
{
	int flag = 1;
	char * find;

	while (flag)
	{
		find = strchr(input, ' ');
		if (find)
		{
			flag = 1;
			do
			{
				*find = *(find + 1);
				find++;
			} while (*find);
		}
		else
			flag = 0;
	}
}