#include <stdio.h>
#include <string.h>
#include "inputs.h"
#define LEN 100

void reverse(char* input, char * output);

int main(void)
{
	char origin[LEN];
	char source[LEN];

	puts("Please enter a origin string:(less than 100 words)");
	while (s_gets(origin, LEN) && origin[0])
	{
		reverse(origin, source);
		puts(source);
		puts("Next origin string:");
	}

	puts("Done!");

	return 0;
}

void reverse(char* input, char* output)
{
	int length = strlen(input);

	for (int i = 0; i < length; i++)
		output[i] = input[length - 1 - i];
	output[length] = '\0';
}