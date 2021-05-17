#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 100

int str_search(char * str, char ch);
void strings(char * inpit, int len);
char chars(void);

int main(void)
{
	char orgin[LEN];
	char ch;
	int location;

	strings(orgin, LEN);
	puts(orgin);
	ch = chars();
	while (orgin != NULL && ch != '\0')
	{
		location = str_search(orgin, ch);
		printf("%c in the %d of %s\r\n", ch, location, orgin);
		strings(orgin, LEN);
		ch = chars();
	}

	return 0;
}

char chars(void)
{
	char ch;
	printf("Please enter a char:\r\n");
	while ((ch = getchar()))
	{
		if (isblank(ch))
			continue;
		else
			break;
	}
	while (getchar() != '\n')
		continue;

	return ch;
}

void strings(char input[], int len)
{
	int i = 0;

	printf("Please enter less than %d string:\r\n", LEN);
	fgets(input, len, stdin);
	if(input)
	{
		while (input[i] != '\n' && input[i] != '\0')
			i++;
		if (input[i] == '\n')
			input[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		puts(input);
	}
}

int str_search(char* str, char ch)
{
	int i, location;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ch)
		{
			return i;
		}
	}
	if (i >= strlen(str))
		return '\0';
	return i;
}