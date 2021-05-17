#include <stdio.h>
#include <ctype.h>
#define LEN 100

char* getwords(char str[], int len);

int main(void)
{
	char input[LEN];
	char* check;

	puts("Please enetr words:");
	check = getwords(input, LEN);
	if (check = NULL)
		puts("input error!");
	else
		puts(input);
	puts("Done!");

	return 0;
}

char* getwords(char str[], int len)
{
	char ch;
	int i;

	while (1)
	{
		ch = getchar();
		if (isblank(ch))
			continue;
		else
			break;
	}
	if (ch == EOF)
		return NULL;
	str[0] = ch;
	for (i = 1; i < len; i++)
	{
		ch = getchar();
		if (ch != NULL && !isblank(ch))
			str[i] = ch;
		else
		{
			str[i] = '\0';
			while (getchar() != '\n')
				continue;
			return str;
		}
	}
}