#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	int count = 0;
	char ch;
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s ch filenames.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{ 
		ch = argv[1][0];
		char in;
		printf("Please enter a string:");
		while ((in = getchar()) != '\n')
		{
			if (in == ch)
				count++;
		}
		printf("%c appear %d counts.\n", ch, count);
	}
	else
	{
		char in;
		ch = argv[1][0];

		for (int i = 2; i < argc; i++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open %s file.\n", argv[i]);
				continue;
			}
			while ((in = getc(fp)) != EOF)
			{
				if (in == ch)
					count++;
			}
			printf("%c appear %d counts in %s file.\n", ch, count, argv[i]);
			fclose(fp);
		}
	}

	return 0;
}