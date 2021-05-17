#include <stdio.h>
#include <stdbool.h>
#define LEN 100
extern char* s_gets(char* st, int n);
bool is_within(char ch, const char * str);

int main(void)
{
	char input[LEN];
	char ch;
	bool find;

	puts("Please enter a string (words less than 100):");
	while (s_gets(input, LEN) && input[0] != '\0')
	{
		puts("Please enter what char do you want to find?");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		find = is_within(ch, input);
		if (find)
			printf("%c found in string %s\n", ch, input);
		else
			printf("%c not found in string %s\n", ch, input);
		puts("Next string:");
	}
	puts("Done!");

	return 0;
}

bool is_within(char ch, const char* str)
{
	while (ch != *str && *str != '\0')
		str++;

	return *str;
}