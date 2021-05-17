#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char* argv[])
{
	FILE* fp;
	char array[MAX];
	if (argc != 3)
	{
		printf("Usage: %s string filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Can't open %s file.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(array, MAX, fp) != NULL)
	{
		if (strstr(array, argv[1]) != NULL)
			fputs(array, stdout);
	}
	fclose(fp);

	return 0;
}