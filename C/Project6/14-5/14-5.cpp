#include <stdio.h>
#include <string.h>
#define MAX 100
#define CSIZE 4
#define SCORES 3

void get_scores(struct student ar[], int lim);
void find_means(struct student ar[], int lim);
void show_class(const struct student ar[], int lim);
void show_ave(const struct student ar[], int lim);

struct name
{
	char first[MAX];
	char last[MAX];
};
struct student
{
	struct name names;
	float grade[SCORES];
	float average;
};

int main(void)
{
	struct student classes[CSIZE] = {
		{"Flip", "Snide"},
		{ "Clare", "Voyans"},
		{ "Bingo", "Higgs"},
		{ "Fawn", "Hunter"}
	};

	get_scores(classes, CSIZE);
	find_means(classes, CSIZE);
	show_class(classes, CSIZE);
	show_ave(classes, CSIZE);
	
	return 0;
}

void get_scores(struct student ar[], int lim)
{
	for (int i = 0; i < lim; i++)
	{
		printf("Please enter %d scores for %s %s:\n", SCORES, ar[i].names.first, ar[i].names.last);
		for (int j = 0; j < SCORES; j++)
		{
			while (scanf("%f", &ar[i].grade[j]) != 1)
			{ 
				scanf("%*s");
				puts("Please use numeric input.");
			}
		}
	}
}

void find_means(struct student ar[], int lim)
{
	for (int i = 0; i < lim; i++)
	{
		float sum = 0;
		for (int j = 0; j < SCORES; j++)
			sum += ar[i].grade[j];
		ar[i].average = sum / SCORES;
	}
}

void show_class(const struct student ar[], int lim)
{
	int i, j;
	char wholename[2 * MAX];
	for (i = 0; i < lim; i++) 
	{ 
		strcpy(wholename, ar[i].names.first);
		strcat(wholename, " ");
		strcat(wholename, ar[i].names.last);
		printf("%27s: ", wholename);
		for (j = 0; j < SCORES; j++)
			printf("%6.1f ", ar[i].grade[j]);
		printf(" Average = %5.2f\n", ar[i].average);
	}
}

void show_ave(const struct student ar[], int lim)
{
	float sum = 0;

	for (int i = 0; i < lim; i++)
		sum += ar[i].average;

	printf("All average = %f\r\n", sum / lim);
}