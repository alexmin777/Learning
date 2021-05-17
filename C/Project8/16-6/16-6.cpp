#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

struct name
{
	char first[40];
	char last[40];
};
struct name staff[SIZE] = {
	{"alex", "min"}, 
	{"boy", "chen"},
	{"alex", "jun"},
	{"alex", "long"},
	{"jack", "chen"}
};

void showarray(const struct name source[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
	puts("Name list:\n");
	showarray(staff, SIZE);
	qsort(staff, SIZE, sizeof(struct name), mycomp);
	puts("Sort list:\n");
	showarray(staff, SIZE);

	return 0;
}

void showarray(const struct name source[], int n)
{
	for (int i = 0; i < n ;i++)
	{
		printf("%5s %5s", source[i].first, source[i].last);
		if (i % 3 == 2)
			putchar('\n');
	}
	putchar('\n');
}

int mycomp(const void* p1, const void* p2)
{
	const struct name* ps1 = (const struct name*)p1;
	const struct name* ps2 = (const struct name*)p2;
	int res;

	res = strcmp(ps1->first, ps2->first);
	if (res != 0)
		return res;
	else
		return strcmp(ps1->last, ps2->last);;
}