#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* fp1, * fp2;
	char ch1, ch2;

	if (argc != 3)
	{
		printf("Usage: %s file1 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp1 = fopen(argv[1], "r")) == NULL)
	{
		printf("Could not open file %s for input\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen(argv[2], "r")) == NULL)
	{
		printf("Could not open file %s for input\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	ch1 = getc(fp1);
	ch2 = getc(fp2);
	while (ch1 != EOF || ch2 != EOF)
	{
		while (ch1 != EOF && ch1 != '\n')
		{
			putchar(ch1);
			ch1 = getc(fp1);
		}
		if (ch1 != EOF)
		{
			if (ch2 == EOF)
				putchar('\n');
			else
				putchar(' ');
			ch1 = getc(fp1);
		}
		while (ch2 != EOF && ch2 != '\n')
		{
			putchar(ch2);
			ch2 = getc(fp2);
		}
		if (ch2 != EOF)
		{
			putchar('\n');
			ch2 = getc(fp2);
		}
	}
	if (fclose(fp1) != 0)
		printf("Could not close file %s\n", argv[1]);
	if (fclose(fp2) != 0)
		printf("Could not close file %s\n", argv[2]);
	return 0;
}