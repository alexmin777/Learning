#include <stdio.h>
#include <string.h>
#include "inputs.h"
#define LEN 10

extern char * s_gets(char* st, int n);
char * mystrncpy(char * s1, char * s2, int n);

int main(void)
{
	char target[50];
	char source[LEN];
	char* complete;

	puts("Enter target string(words less than 100):");
	while (s_gets(target, 50) && target[0] !='\0')
	{
		puts("Enter source string(words less than 100):");
		s_gets(source, LEN);
		complete = mystrncpy(target, source, LEN);
		printf("Complete string is %s\r\n", complete);
		puts("Next target string(words less than 100):");
	}
	puts("Done!");
	
	return 0;
}

char* mystrncpy(char* s1, char* s2, int n)
{
	int i;
	int length_s1 = strlen(s1);
	int length_s2 = strlen(s2);
	int length_copy = (length_s2 >= n ? n : length_s2);

	for (i = 0; i < length_copy; i++)
	{
		*(s1 + length_s1 + i) = *(s2 + i);
	}
	if (n > length_s2)
		* (s1 + length_s1 + length_s2) = '\0';

	return s1;
}