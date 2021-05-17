#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

int main(void)
{
	int words;
	char array[256];
	int array_length;

	printf("How many words do you wish to enter? ");
	scanf_s("%d", &words);

	char** ptr = (char** )malloc(words * sizeof(char*));
	
	printf("Enter %d words now:\n", words);
	for (int i = 0; i < words; i++)
	{
		scanf_s("%s", array, 256);
		array_length = strlen(array);
		ptr[i] = (char*)malloc(array_length * sizeof(char) + 1);
		strcpy_s(ptr[i], array_length + 1, array);
	}
	printf("Here are your words:\r\n");

	for (int i = 0; i < words; i++)
		printf("%s\r\n", ptr[i]);
	free(ptr);

	return 0;
}