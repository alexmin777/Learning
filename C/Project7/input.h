#include <stdio.h>
#include <string.h>

char* s_gets(char* st, int n)
{
	char* check;
	char* find;

	check = fgets(st, n, stdin);
	if (check)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return check;
}