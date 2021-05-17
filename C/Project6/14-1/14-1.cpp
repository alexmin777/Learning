#include <stdio.h>
#include <string.h>

struct month
{
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};
const struct month months[12] = { 
	{"January", "Jan", 31, 1},
	{"February", "Feb", 28, 2},     
	{"March", "Mar", 31, 3},     
	{"April", "Apr", 30, 4},     
	{"May", "May", 31, 5},     
	{"June", "Jun", 30, 6},     
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};

int main(void)
{
	char input[20];
	int total = 0;
	int flag = 0;

	printf("Please enter name of month:");
	scanf("%s", input);
	for (int i = 0; i < 12; i++)
	{
		total += months[i].days;
		if (!strncmp(months[i].name, input, strlen(months[i].name)))
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		printf("total days = %d\r\n", total);
	
	return 0;
}