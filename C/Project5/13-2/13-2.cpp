#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* source, * target;
	char ch;

	if (argc != 3)
	{
		printf("Usage: %s sourcefile targetfile\n", argv[0]);
		exit(EXIT_SUCCESS);
	}
	if ((source = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open %s file.", argv[1]);
		exit(EXIT_SUCCESS);
	}
	if ((target = fopen(argv[2], "wb")) == NULL)
	{
		printf("Can't open %s file.", argv[1]);
		exit(EXIT_SUCCESS);
	}
	while ((ch = getc(source)) != EOF)
	{
		putc(ch, target);
	}
	if (fclose(source) != 0)
		printf("Could not close file %s\n", argv[1]);
	if (fclose(target) != 0)
		printf("Could not close file %s\n", argv[2]);

	return 0;
}