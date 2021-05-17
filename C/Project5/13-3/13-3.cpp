#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	char file_name[256];
	FILE *fp, *target;
	char ch;
	
	printf("Please enter which file do you want to update:");
	scanf("%s", file_name);
	if ((fp = fopen(file_name, "r+")) == NULL)
	{
		printf("Can't open %s file.\n", file_name);
		exit(EXIT_FAILURE);
	}
	if ((target = fopen("1.txt", "w")) == NULL)
	{
		printf("Can't open %s file.\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		ch = toupper(ch);
		putc(ch, target);
	}
	if (fclose(fp) != 0)
		printf("Close file error!\n");
	if (fclose(target) != 0)
		printf("Close file error!\n");

	return 0;
}