#include <stdio.h>
#define LEN 4

void add_array(const int source1[], const int source2[], int target[], int length);
void show_array(const int source[], int length);

int main(void)
{
	const int origin1[LEN] = { 2,4,5,7 };
	const int origin2[LEN] = { 1,0,4,6 };
	int target[LEN];

	add_array(origin1, origin2, target, LEN);
	printf("target:");
	show_array(target, LEN);
	printf("\r\n:");

	return 0;
}

void add_array(const int source1[], const int source2[], int target[], int length)
{
	int i;

	for (i = 0; i < length; i++)
		*(target + i) = *(source1 + i) + *(source2 + i);
}

void show_array(const int source[], int length)
{
	int i;

	for (i = 0; i < length; i++)
		printf("%d	", *(source + i));
}