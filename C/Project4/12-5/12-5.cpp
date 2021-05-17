#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

void show_array(const int *str, int size);
void sort_array(int* str, int size);

int main(void)
{
	int origin[SIZE];
	srand((unsigned int)time(0));
	for (int i = 0; i < SIZE; i++)
		origin[i] = rand() % 10 + 1;
	show_array(origin, SIZE);
	sort_array(origin, SIZE);
	show_array(origin, SIZE);

	return 0;
}

void show_array(const int* str, int size)
{
	printf("Array:");
	for (int i = 0; i < size; i++)
		printf("%d\r\n", str[i]);
}

void sort_array(int* str, int size)
{
	int compare = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
			if (str[i] < str[j])
			{
				compare = str[j];
				str[j] = str[i];
				str[i] = compare;
			}
	}
}