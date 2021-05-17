#include <stdio.h>
#include <string.h>
#include "inputs.h"
#define LEN 100
char* string_in(char* s1, char* s2);
extern char* s_gets(char* st, int n);

int main(void)
{
	char target[LEN];
	char source[LEN];

	puts("Please enter target string(words less than 100):");
	while (s_gets(target, LEN) && target[0] != '\0')
	{
		puts("Please enter source string(words less than 100):");
		s_gets(source, LEN);
		if (string_in(target, source) == NULL)
			printf("Can't find %s in the %s\r\n", source, target);
		else
			printf("Find %s in the %s\r\n", source, target);
		puts("Next target string:");
	}
	puts("Done!\r\n");

	return 0;
}

char* string_in(char* s1, char* s2)
{
	int length;
	int flag;
	int compare_length = strlen(s2);
	length = strlen(s1) + 1 - compare_length;

	while ((flag = strncmp(s1, s2, compare_length)) && length--)
		s1++;
	if (flag)
		return NULL;
	else
		return s1;

}