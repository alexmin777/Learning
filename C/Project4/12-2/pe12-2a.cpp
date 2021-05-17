#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int choose)
{
	if (choose <= 1)
		mode = choose;
	else
		printf("Invalid mode specified. Mode %s used.\n", (mode ? "1(US)" : "0(metric)"));
}

void get_info(void)
{
	if (mode)
	{ 
		printf("Enter distance traveled in miles: ");
		scanf_s("%lf", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf_s("%lf", &fuel);
	}
	else
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%lf", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf_s("%lf", &fuel);
	}
}

void show_info(void)
{
	if (mode)
		printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel);
	else
		printf("Fuel consumption is %.2lf liters per 100 km.\n", (fuel / distance) * 100);
}