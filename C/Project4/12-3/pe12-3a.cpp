#include <stdio.h>
#include "pe12-3a.h"

void set_mode(int* mode)
{
	if (*mode > 1)
	{
		printf("Invalid mode specified. Mode %d.\n", *mode);
		printf("Previous mode will be used.\n");
		*mode = MODE_OTHER;
	}
}

void get_info(int mode, double* distance, double* fuel)
{
	if (mode)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%lf", distance);
		printf("Enter fuel consumed in gallons: ");
		scanf_s("%lf", fuel);
	}
	else
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%lf", distance);
		printf("Enter fuel consumed in liters: ");
		scanf_s("%lf", fuel);
	}
}

void show_info(int mode, double* distance, double* fuel)
{
	if (mode)
		printf("Fuel consumption is %.2lf miles per gallon.\n", *distance / *fuel);
	else
		printf("Fuel consumption is %.2lf liters per 100 km.\n", (*fuel / *distance) * 100);
}