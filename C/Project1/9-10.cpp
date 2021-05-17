#include <stdio.h>

void to_base_n(unsigned long a, unsigned int b);

int main(void)
{
	unsigned long number;
	unsigned int base;
	printf("Enter an integer and a base(q to quit):\n");
	while (scanf_s("%lu %u", &number, &base) == 2)
	{
		printf("Base %u equivalent: ", base);
		to_base_n(number, base);
		putchar('\n');
		printf("Enter an integer and a base(q to quit):\n");
	}
	printf("Done!\n");

	return 0;
}

void to_base_n(unsigned long a, unsigned int b)
{
	int r;

	r = a % b;
	if (a >= b)
		to_base_n((a / b), b);
	putchar('0' + r);
	return;
}