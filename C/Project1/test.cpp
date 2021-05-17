#include <stdio.h>

int main(void)
{
	int dates[5] = { 1, 2, 3, 4, 5 };
	int* pd, *pr;
	pd = dates;
	pr = dates;
	printf("pd:%d  pr:%d\r\n",pd[4], *(pr + 4));
}