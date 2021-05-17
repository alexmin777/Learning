#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fp;
	unsigned long count = 0;
	char file_name[256];

	printf("Please enter name of file:");
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s file.\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", file_name, count);

	return 0;
}