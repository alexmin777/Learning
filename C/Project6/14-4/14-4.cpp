#include <stdio.h>
#include "../input.h"
#define MAX 10
struct information
{
	char last[MAX];
	char mid[MAX];
	char first[MAX];
};
struct message
{
	unsigned int num;
	struct information person;
};

void show(struct message * input, int n);

int main(void)
{
	struct message insurance[5];
	int count = 0;

	printf("Please enter the numbers(q to quit):\r\n");
	while (scanf("%d", &insurance[count].num) == 1 && insurance[count].num != '\0')
	{
		while (getchar() != '\n')
			continue;
		printf("Please enter first name:\r\n");
		s_gets(insurance[count].person.first, MAX);
		printf("Please enter mid name(if have or enter to quit):\r\n");
		s_gets(insurance[count].person.mid, MAX);
		printf("Please enter last name:\r\n");
		s_gets(insurance[count].person.last, MAX);
		count++;
		printf("Please enter the numbers(q to quit):\r\n");
	}

	show(insurance, count);

	return 0;
}

void show(struct message* input, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*input->person.mid == '\0')
			printf("%s, %s -- %d", input->person.last, input->person.first, input->num);
		else
			printf("%s, %s %c. -- %d", input->person.last, input->person.first, *input->person.mid, input->num);
	}
}