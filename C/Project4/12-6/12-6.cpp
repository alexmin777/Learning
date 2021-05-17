#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

int main(void)
{
	int array[10] = { 0 };
	int num;
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 100 == 0)
		{
			srand((unsigned int)time(0));
		}
		num = rand() % 10 + 1;
		array[num - 1]++;
	}

	for (int i = 0; i < 10; i++)
		printf("%d count %d\r\n", i + 1, array[i]);
}