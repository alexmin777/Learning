#include <stdio.h>
#include <time.h>
#include <Windows.h>

void delay(double);
int main(void)
{
	clock_t start, end;
	double ms;

	printf("How long do you want to dealy(ms) (q to quit):\n");
	while ((scanf("%lf", &ms) == 1) && ms >= 0)
	{
		start = clock();
		delay(ms);
		end = clock();
		printf("Dealy %lf s\r\n", ((double)(end - start)) / CLOCKS_PER_SEC);
		puts("Continue enter the time (q to quit)");
	}
	puts("Bye");

	return 0;
}

void delay(double ms)
{
	Sleep(ms);
}