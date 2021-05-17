#include <stdio.h>

unsigned long Fibonacci(int n);

int main(void)
{
	int num;
	int result;

	printf("Please enter number:(q to quit)\n");
	while (scanf_s("%d", &num) == 1)
	{
		result = Fibonacci(num);
		printf("result:%ul\n", result);
		printf("Please enter number:(q to quit)\n");
	}
	printf("Done!\n");

	return 0;
}

unsigned long Fibonacci(int n)
{
	int i;
	unsigned long count[100];
	count[0] = 1;
	count[1] = 1;

	for ( i = 2; i < n; i++)
	{
		count[i] = count[i - 1] + count[i - 2];
	}

	return count[i - 1];
}