#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define SIZE 1000

int main(void)
{
	FILE* in, * out;
	int ch;
	char in_name[LEN];
	char out_name[LEN];
	char data[SIZE];
	int count = 0;

	printf("Please enter source file name:");
	scanf("%s", in_name);
	if ((in = fopen(in_name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s file.\n", in_name);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(in, NULL, _IOFBF, SIZE))
	{
		fputs("Can't create source buffer!\n", stderr);
		exit(EXIT_FAILURE);
	}


	strncpy(out_name, in_name, LEN - 5);
	out_name[LEN - 5] = '\0';
	strcat(out_name, ".red");
	if ((out = fopen(out_name, "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s file.\n", in_name);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(out, NULL, _IOFBF, SIZE))
	{
		fputs("Can't create target buffer!\n", stderr);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
			putc(ch, out);
	}

	if (fclose(in) != 0 || fclose(out))
		fprintf(stderr, "Close files error!\n");

	return 0;
}