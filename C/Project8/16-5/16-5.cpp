#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void random(int ar[], int size, int count);
int array[SIZE] = { 1,2,3,4,5,6,7,8,9 };

int main(void)
{
	int count;

	printf("Please enter how many do you want to choose(q to quit):\n");
	while ((scanf("%d", &count) == 1) && count > 0)
	{
		random(array, SIZE, count);
		printf("Please continue to enter (q to quit):\n");
	}
	puts("Bye!");

	return 0;
}


void random(int ar[], int size, int count)
{
	int result, index;

	srand((unsigned int)time(0));
	for (int i = 0; i < count; i++)
	{
		index = rand() % (size - 1);
		result = ar[index];
		printf("%d ", result);
		if (i % 10 == 9)
			putchar('\n');
		ar[index] = ar[size - 1];
		ar[size - 1] = result;
		size--;
	}
}