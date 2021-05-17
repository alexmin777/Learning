#include <stdio.h>
#include <string.h>

char* s_gets(char* st, int n)
{
	char* find, * check;

	check = fgets(st, n, stdin);
	find = check;
	if (check)
	{
		find = strchr(check, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return check;
}