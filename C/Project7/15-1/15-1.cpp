#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include "../input.h"

extern char* s_gets(char* st, int n);
int bstr_to_dec(const char* str);
bool check_val(const char* str);

int main(void)
{
	const size_t SLEN = CHAR_BIT * sizeof(int) + 1;
	char value[SLEN];

	printf("Enter a binary number with up to %zu digits: ", SLEN - 1);
	while (s_gets(value, SLEN) && value[0] != '\0')
	{
		if (!check_val(value))
			puts("A binary number contains just 0s and 1s.");
		else
			printf("%s is %d\n", value, bstr_to_dec(value));
		puts("Enter next value (empty line to quit):");
	}
	puts("Done");
	
	return 0;
}

bool check_val(const char* str)
{
	bool flag = true;

	while (flag && *str != '\0')
	{
		if ((*str == '1') || (*str == '0'))
			str++;
		else
			flag = false;
	}

	return flag;
}

int bstr_to_dec(const char* str)
{
	int value = 0;

	while (*str != '\0')
		value = 2 * value + (*str++ - '0');

	return value;
}