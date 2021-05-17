#include <stdio.h>
#include <ctype.h>

int address(char ch);

int main(void)
{
	char ch;
	int position;

	printf("Please enter string:\n");
	while ((ch = getchar()) != EOF)
	{
		position = address(ch);
		printf("%d	", position);
		printf("Please enter string:\n");
	}
	printf("Bye!\n");
}

int address(char ch)
{
		ch = toupper(ch);
		if (!isalpha(ch))
			return -1;
		else
			return ch - 64;
}

