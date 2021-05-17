#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char name[256];
	int location;
	char ch;

	printf("Please enter which file do you want to open:");
	scanf("%s", name);
	while (getchar() != '\n')
		continue;

	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s file.\n", name);
		exit(EXIT_FAILURE);
	}

	printf("which do you want to start(q to quit):");
	while ((scanf("%d", &location) == 1) && location >= 0)
	{
		fseek(fp, location, SEEK_SET);
		while ((ch = getc(fp)) != '\n' && ch != EOF)
		{
			putchar(ch);
		}
		puts("");
		printf("which do you want to start(q to quit):");
	}
	fclose(fp);

	return 0;
}