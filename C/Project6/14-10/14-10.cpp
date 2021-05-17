#include <stdio.h>
#include <math.h>    // for sqrt() 
#include "../input.h"
double twice(double x);
double half(double x);
double thrice(double x);
void show_menu(void);

#define NUM 4
int main(void)
{
	double val, ans;
	int sel;
	double(*fp[NUM])(double) = { twice, half, thrice, sqrt };

	printf("Enter a number (q to quit): ");
	while ((scanf("%lf", &val)) == 1 && (val >= 0))
	{
		show_menu();
		while ((scanf("%d", &sel) == 1) && (sel >= 0) && (sel <= 3))
		{
			ans = (*fp[sel])(val);
			printf("answer = %f\n", ans);
			ans = fp[sel](val);
			printf("to repeat, answer = %f\n", ans);
			show_menu();
		}
		printf("Enter next number (q to quit): ");
	}

	puts("bye");
	return 0;
}

double twice(double x)
{
	return 2.0 * x;
}

double half(double x)
{
	return x / 2.0;
}

double thrice(double x)
{
	return 3.0 * x;
}

void show_menu(void)
{
	puts("Enter one of the following choices:");
	puts("0) double the value        1) halve the value");
	puts("2) triple the value        3) squareroot the value");
	puts("4) next number");
}