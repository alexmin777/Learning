#include <stdio.h>
#include <stdlib.h>

int* make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int* pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	while (scanf_s("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf_s("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit): ");
	}
	printf("Done.\n");

	return 0;
}

int* make_array(int elem, int val)
{
	int* pointer;
	
	pointer = (int*)malloc(elem * sizeof(int));
	srand(val);
	for (int i = 0; i < elem; i++)
	{
		pointer[i] = rand();
	}

	return pointer;
}

void show_array(const int ar[], int n)
{
	int i;
	printf("The value of array:\n");
	for (i = 0; i < n; i++)
	{
		printf("%4d	", ar[i]);
		if (i % 8 == 7)
			putchar('\n');
	}
	if (i % 8 != 0)
		putchar('\n');
}