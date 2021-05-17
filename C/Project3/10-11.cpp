#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "inputs.h"
#define LEN 100

void menu(void);
void printf_real_strings(char * string[10], int num);
void printf_strings(char input[][LEN], int num);
void printf_strings_by_ascii(char input[][LEN], int num);
void printf_strings_by_length(char input[][LEN],int num);
int count_first_word_length(char* input);
void printf_strings_by_first_word(char input[][LEN], int num);

int main(void)
{
	char origin[10][LEN];
	int string_count = 0;
	char choose;
	
	puts("Please enter 10 strings:");
	for (int i = 0; i < 10; i++)
	{
		s_gets(origin[i], LEN);
		if (origin[i][0] == '\0')
			break;
		string_count++;
	}
	while (1)
	{

		menu();
		puts("Please enter a~e to choose:");
		scanf_s("%c", &choose);
		choose = tolower(choose);
		while (getchar() != '\n')
			continue;
		switch (choose)
		{
		case 'a':
			printf_strings(origin, string_count);
			break;
		case 'b':
			printf("Choose b\r\n");
			printf_strings_by_ascii(origin, string_count);
			break;
		case 'c':
			printf("Choose c\r\n");
			printf_strings_by_length(origin, string_count);
			break;
		case 'd':
			printf("Choose d\r\n");
			printf_strings_by_first_word(origin, string_count);
			break;
		case 'q':
			puts("Bye!");
			return 0;
		default:
			printf("Unkonw command, enter again!\n");
			break;
		}
	}
}

void printf_strings(char input[][LEN], int num)
{

	for (int i = 0; i < num; i++)
	{
		printf("%d:", i);
		printf("%s\r\n", input[i]);
	}
}

void printf_strings_by_ascii(char input[][LEN], int num)
{
	char * output;
	int flag;
	char* source[10];

	for (int i = 0; i < num; i++)
		source[i] = input[i];

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			flag = strcmp(source[i], source[j]);
			if (flag > 0)
			{
				output = source[j];
				source[j] = source[i];
				source[i] = output;
			}
		}
	}
	printf_real_strings(source, num);
}

void printf_strings_by_length(char input[][LEN], int num)
{
	char* output;
	char* source[10];

	for (int i = 0; i < num; i++)
		source[i] = input[i];

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (strlen(source[i]) > strlen(source[j]))
			{
				output = source[i];
				source[i] = source[j];
				source[j] = output;
			}
		}
	}
	printf_real_strings(source, num);
}

void printf_strings_by_first_word(char input[][LEN], int num)
{
	char* output;
	char* source[10];

	for (int i = 0; i < num; i++)
		source[i] = input[i];

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			
			if (count_first_word_length(source[i]) > count_first_word_length(source[j]))
			{
				output = source[i];
				source[i] = source[j];
				source[j] = output;
			}
		}
	}
	printf_real_strings(source, num);
}

int count_first_word_length(char* input)
{
	int num = strlen(input);

	for (int i = 0; i < num; i++)
	{
		if (isspace(input[i]))
		{
			return i;
		}
	}
	
	return num;
}

void menu(void)
{
	printf("Menu:\n");
	printf("%-50s%-50s\n%-50s%-50s\n%-50s\n", "a) print original string",
		"b) print string sorted by ascii", "c) print string sorted by string length",
		"d) print string sorted by first word length", "q) quit");
}

void printf_real_strings(char* string[10], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d: ", i);
		puts(string[i]);
	}
}